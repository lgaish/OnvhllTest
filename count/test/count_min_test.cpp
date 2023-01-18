#include <catch2/catch.hpp>
#include <vector>

#include "count_min.hpp"
#include "common_defs.hpp"

namespace datasketches{

TEST_CASE("CM init"){
    uint16_t n_hashes = 3 ;
    uint32_t n_buckets = 5 ;
    uint64_t seed = 1234567 ;
    REQUIRE_THROWS_AS(count_min_sketch<uint64_t>(n_hashes, 1, seed), std::invalid_argument);
    count_min_sketch<uint64_t> c(n_hashes, n_buckets, seed) ;
    //std::vector<uint64_t> sk_config{n_hashes, n_buckets, seed} ;
    REQUIRE(c.get_num_hashes() == n_hashes) ;
    REQUIRE(c.get_num_buckets() == n_buckets) ;
    REQUIRE(c.get_seed() == seed) ;
    //REQUIRE(c.get_config() == sk_config) ;

    //std::vector<uint64_t> sketch_table = c.get_sketch() ;
    for(auto x: c){
      REQUIRE(x == 0) ;
    }

    // Check the default seed is appropriately set.
    count_min_sketch<uint64_t> c1(n_hashes, n_buckets) ;
    REQUIRE(c1.get_seed() == DEFAULT_SEED) ;
}

TEST_CASE("CM parameter suggestions", "[error parameters]") {

    // Bucket suggestions
    REQUIRE_THROWS(count_min_sketch<uint64_t>::suggest_num_buckets(-1.0), "Confidence must be between 0 and 1.0 (inclusive)." ) ;
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_buckets(0.2) == 14) ;
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_buckets(0.1) == 28) ;
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_buckets(0.05) == 55) ;
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_buckets(0.01) == 272) ;

    // Check that the sketch get_epsilon acts inversely to suggest_num_buckets
    uint64_t n_hashes = 3 ;
    REQUIRE(count_min_sketch<uint64_t>(n_hashes, 14).get_relative_error() <= 0.2) ;
    REQUIRE(count_min_sketch<uint64_t>(n_hashes, 28).get_relative_error() <= 0.1) ;
    REQUIRE(count_min_sketch<uint64_t>(n_hashes, 55).get_relative_error() <= 0.05) ;
    REQUIRE(count_min_sketch<uint64_t>(n_hashes, 272).get_relative_error() <= 0.01) ;

    // Hash suggestions
    REQUIRE_THROWS(count_min_sketch<uint64_t>::suggest_num_hashes(10.0), "Confidence must be between 0 and 1.0 (inclusive)." ) ;
    REQUIRE_THROWS(count_min_sketch<uint64_t>::suggest_num_hashes(-1.0), "Confidence must be between 0 and 1.0 (inclusive)." ) ;
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_hashes(0.682689492) == 2) ; // 1 STDDEV
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_hashes(0.954499736) == 4) ; // 2 STDDEV
    REQUIRE(count_min_sketch<uint64_t>::suggest_num_hashes(0.997300204) == 6) ; // 3 STDDEV
}

TEST_CASE("CM one update: uint64_t"){
  uint16_t n_hashes = 3 ;
  uint32_t n_buckets = 5 ;
  uint64_t seed =  9223372036854775807 ; //1234567 ;
  uint64_t inserted_weight = 0 ;
  count_min_sketch<uint64_t> c(n_hashes, n_buckets, seed) ;
  std::string x = "x" ;

  REQUIRE(c.get_estimate("x") == 0) ; // No items in sketch so estimates should be zero
  c.update(x) ;
  REQUIRE(c.get_estimate(x) == 1) ;
  inserted_weight += 1 ;

  uint64_t w = 9 ;
  inserted_weight += w ;
  c.update(x, w) ;
  REQUIRE(c.get_estimate(x) == inserted_weight) ;

    // Doubles are converted to uint64_t
    double w1 = 10.0 ;
    inserted_weight += w1 ;
    c.update(x, w1) ;
    REQUIRE(c.get_estimate(x) == inserted_weight) ;
    REQUIRE(c.get_total_weight() == inserted_weight) ;
    REQUIRE(c.get_estimate(x) <= c.get_upper_bound(x)) ;
    REQUIRE(c.get_estimate(x) >= c.get_lower_bound(x)) ;
}

TEST_CASE("CM frequency estimates"){
    int number_of_items = 10 ;
    std::vector<uint64_t> data(number_of_items) ;
    std::vector<uint64_t> frequencies(number_of_items) ;

    // Populate data vector
    for(int i=0; i < number_of_items; i++){
      data[i] = i;
      frequencies[i] = 1 << (number_of_items - i) ;
    }

    double relative_error = 0.1 ;
    double confidence = 0.99 ;
    uint16_t n_buckets = count_min_sketch<uint64_t>::suggest_num_buckets(relative_error) ;
    uint32_t n_hashes = count_min_sketch<uint64_t>::suggest_num_hashes(confidence) ;

    count_min_sketch<uint64_t> c(n_hashes, n_buckets) ;
    for(int i=0 ; i < number_of_items ; i++) {
      uint64_t value = data[i] ;
      uint64_t freq = frequencies[i] ;
      c.update(value, freq) ;
    }

    for(const auto i: data){
      uint64_t est = c.get_estimate(i) ;
      uint64_t upp = c.get_upper_bound(i) ;
      uint64_t low = c.get_lower_bound(i) ;
      REQUIRE(est <= upp) ;
      REQUIRE(est >= low) ;
    }
}

TEST_CASE("CM merge - reject", "[reject cases]"){
    double relative_error = 0.25 ;
    double confidence = 0.9 ;
    uint32_t n_buckets = count_min_sketch<uint64_t>::suggest_num_buckets(relative_error) ;
    uint16_t n_hashes = count_min_sketch<uint64_t>::suggest_num_hashes(confidence) ;
    count_min_sketch<uint64_t> s(n_hashes, n_buckets, 9082435234709287) ;


    // Generate sketches that we cannot merge into ie they disagree on at least one of the config entries
    count_min_sketch<uint64_t> s1(n_hashes+1, n_buckets) ; // incorrect number of hashes
    count_min_sketch<uint64_t> s2(n_hashes, n_buckets+1) ;// incorrect number of buckets
    count_min_sketch<uint64_t> s3(n_hashes, n_buckets, 1) ;// incorrect seed
    std::vector<count_min_sketch<uint64_t>> sketches = {s1, s2, s3};

    // Fail cases
    REQUIRE_THROWS(s.merge(s), "Cannot merge a sketch with itself." ) ;
    for(count_min_sketch<uint64_t> sk : sketches){
      REQUIRE_THROWS(s.merge(sk), "Incompatible sketch config." ) ;
    }
}

TEST_CASE("CM merge - pass", "[acceptable cases]"){
    double relative_error = 0.25 ;
    double confidence = 0.9 ;
    uint32_t n_buckets = count_min_sketch<uint64_t>::suggest_num_buckets(relative_error) ;
    uint16_t n_hashes = count_min_sketch<uint64_t>::suggest_num_hashes(confidence) ;
    count_min_sketch<uint64_t> s(n_hashes, n_buckets) ;
    uint16_t s_hashes = s.get_num_hashes() ;
    uint32_t s_buckets = s.get_num_buckets() ;
    count_min_sketch<uint64_t> t(s_hashes, s_buckets) ;

    // Merge in an all-zeros sketch t.  Should not change the total weight.
    s.merge(t) ;
    REQUIRE(s.get_total_weight() == 0 ) ;

    std::vector<uint64_t> data = {2,3,5,7};
    for(auto d: data){
      s.update(d) ;
      t.update(d) ;
    }
    s.merge(t);

    REQUIRE(s.get_total_weight() == 2*t.get_total_weight());

    // Estimator checks.
    for (auto x : data) {
      REQUIRE(s.get_estimate(x) <= s.get_upper_bound(x)) ;
      REQUIRE(s.get_estimate(x) <= 2); // True frequency x == 2 for all x.
    }
  }
} /* namespace datasketches */

