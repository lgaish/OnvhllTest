/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "hll.hpp"
#include "CouponList.hpp"
#include "HllUtil.hpp"

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <ostream>
#include <cmath>
#include <string>
#include <exception>

namespace datasketches {

class CouponListTest : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(CouponListTest);
  CPPUNIT_TEST(checkIterator);
  CPPUNIT_TEST(checkDuplicatesAndMisc);
  CPPUNIT_TEST(checkSerializeDeserialize);
  CPPUNIT_TEST(checkCorruptBytearrayData);
  CPPUNIT_TEST(checkCorruptStreamData);
  CPPUNIT_TEST_SUITE_END();

  void println_string(std::string str) {
    //std::cout << str << std::endl;
  }

  void checkIterator() {
    int lgConfigK = 8;
    CouponList<> cl(lgConfigK, HLL_4, LIST);
    for (int i = 1; i <= 8; ++i) { cl.couponUpdate(HllUtil<>::pair(i, i)); } // not hashes but distinct values
    const int mask = (1 << lgConfigK) - 1;
    int idx = 0;
    auto itr = cl.begin(true);
    while (itr != cl.end()) {
      int key = HllUtil<>::getLow26(*itr);
      int val = HllUtil<>::getValue(*itr);
      int slot = HllUtil<>::getLow26(*itr) & mask;
      std::ostringstream oss;
      oss << "Idx: " << idx << ", Key: " << key << ", Val: " << val
          << ", Slot: " << slot;
      println_string(oss.str());
      CPPUNIT_ASSERT_EQUAL(val, idx + 1);
      ++itr;
      ++idx;
    }
  }

  void checkDuplicatesAndMisc() {
    int lgConfigK = 8;
    hll_sketch sk(lgConfigK);

    for (int i = 1; i <= 7; ++i) {
      sk.update(i);
      sk.update(i);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(sk.get_composite_estimate(), 7.0, 7 * 0.1);

    sk.update(8);
    sk.update(8);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(sk.get_composite_estimate(), 8.0, 8 * 0.1);

    for (int i = 9; i <= 25; ++i) {
      sk.update(i);
      sk.update(i);
    }
    CPPUNIT_ASSERT_DOUBLES_EQUAL(sk.get_composite_estimate(), 25.0, 25 * 0.1);

    double relErr = sk.get_rel_err(true, true, 4, 1);
    CPPUNIT_ASSERT(relErr < 0.0);
  }

  std::string dumpAsHex(const char* data, int len) {
   constexpr uint8_t hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                 '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    std::string s(len * 2, ' ');
    for (int i = 0; i < len; ++i) {
      s[2 * i]     = hexmap[(data[i] & 0xF0) >> 4];
      s[2 * i + 1] = hexmap[(data[i] & 0x0F)];
    }
    return s;
  }

  void serializeDeserialize(const int lgK) {
    hll_sketch sk1(lgK);

    int u = (lgK < 8) ? 7 : (((1 << (lgK - 3))/ 4) * 3);
    for (int i = 0; i < u; ++i) {
      sk1.update(i);
    }
    double est1 = sk1.get_estimate();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(est1, u, u * 1e-4);

    std::stringstream ss(std::ios::in | std::ios::out | std::ios::binary);
    sk1.serialize_compact(ss);
    hll_sketch sk2 = hll_sketch::deserialize(ss);
    double est2 = sk2.get_estimate();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(est2, est1, 0.0);

    ss.str(std::string());
    ss.clear();

    sk1.serialize_updatable(ss);
    sk2 = hll_sketch::deserialize(ss);
    est2 = sk2.get_estimate();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(est2, est1, 0.0);
  }
  
  void checkSerializeDeserialize() {
    serializeDeserialize(7);
    serializeDeserialize(21);
  }

  void checkCorruptBytearrayData() {
    int lgK = 6;
    hll_sketch sk1(lgK);
    sk1.update(1);
    sk1.update(2);
    auto sketchBytes = sk1.serialize_compact();
    uint8_t* bytes = sketchBytes.data();
    const size_t size = sketchBytes.size();

    bytes[HllUtil<>::PREAMBLE_INTS_BYTE] = 0;
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in preInts byte",
                                 hll_sketch::deserialize(bytes, size),
                                 std::invalid_argument);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in preInts byte",
                                 CouponList<>::newList(bytes, size),
                                 std::invalid_argument);

    bytes[HllUtil<>::PREAMBLE_INTS_BYTE] = HllUtil<>::LIST_PREINTS;

    bytes[HllUtil<>::SER_VER_BYTE] = 0;
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in serialization version byte",
                                 hll_sketch::deserialize(bytes, size),
                                 std::invalid_argument);
    bytes[HllUtil<>::SER_VER_BYTE] = HllUtil<>::SER_VER;

    bytes[HllUtil<>::FAMILY_BYTE] = 0;
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in family id byte",
                                 hll_sketch::deserialize(bytes, size),
                                 std::invalid_argument);
    bytes[HllUtil<>::FAMILY_BYTE] = HllUtil<>::FAMILY_ID;

    uint8_t tmp = bytes[HllUtil<>::MODE_BYTE];
    bytes[HllUtil<>::MODE_BYTE] = 0x01; // HLL_4, SET
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in mode byte",
                                 hll_sketch::deserialize(bytes, size),
                                 std::invalid_argument);
    bytes[HllUtil<>::MODE_BYTE] = tmp;

    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in serialized length",
                                 hll_sketch::deserialize(bytes, size - 1),
                                 std::invalid_argument);

    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in serialized length",
                                 hll_sketch::deserialize(bytes, 3),
                                 std::invalid_argument);
  }

  void checkCorruptStreamData() {
    int lgK = 6;
    hll_sketch sk1(lgK);
    sk1.update(1);
    sk1.update(2);
    std::stringstream ss;
    sk1.serialize_compact(ss);

    ss.seekp(HllUtil<>::PREAMBLE_INTS_BYTE);
    ss.put(0);
    ss.seekg(0);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in preInts byte",
                                 hll_sketch::deserialize(ss),
                                 std::invalid_argument);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in preInts byte",
                                 CouponList<>::newList(ss),
                                 std::invalid_argument);
    ss.seekp(HllUtil<>::PREAMBLE_INTS_BYTE);
    ss.put(HllUtil<>::LIST_PREINTS);

    ss.seekp(HllUtil<>::SER_VER_BYTE);
    ss.put(0);
    ss.seekg(0);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in serialization version byte",
                                 hll_sketch::deserialize(ss),
                                 std::invalid_argument);
    ss.seekp(HllUtil<>::SER_VER_BYTE);
    ss.put(HllUtil<>::SER_VER);

    ss.seekp(HllUtil<>::FAMILY_BYTE);
    ss.put(0);
    ss.seekg(0);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in family id byte",
                                 hll_sketch::deserialize(ss),
                                 std::invalid_argument);
    ss.seekp(HllUtil<>::FAMILY_BYTE);
    ss.put(HllUtil<>::FAMILY_ID);

    ss.seekp(HllUtil<>::MODE_BYTE);
    ss.put(0x22); // HLL_8, HLL
    ss.seekg(0);
    CPPUNIT_ASSERT_THROW_MESSAGE("Failed to detect error in mode bytes",
                                 hll_sketch::deserialize(ss),
                                 std::invalid_argument);
  }

};

CPPUNIT_TEST_SUITE_REGISTRATION(CouponListTest);

} /* namespace datasketches */
