#ifndef TWO_TUPLE_SKETCH_H
#define TWO_TUPLE_SKETCH_H

#include <cstdint>

namespace datasketches {

class TwoTupleSketch {
public:
  /*old*/
  // virtual bool offerFlow(const void* ptr_flow_id, uint64_t flow_id_len, const
  // void* ptr_element_id, uint64_t element_id_len) = 0; virtual double
  // decodeFlow(const void* ptr_flow_id, uint64_t flow_id_len) = 0;

  /*new*/
  // virtual bool update(const std::string &, const std::string &);
  virtual bool update(const char *, uint64_t, const char *, uint64_t) = 0;
  // virtual double get_estimate(const std::string &);
  virtual double get_estimate(const char *, uint64_t) = 0;
  virtual void resetSketch() = 0;
  virtual void resetSeed(uint32_t) = 0;
};

} // namespace datasketches

#endif
