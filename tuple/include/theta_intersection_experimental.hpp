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

#ifndef THETA_INTERSECTION_EXPERIMENTAL_HPP_
#define THETA_INTERSECTION_EXPERIMENTAL_HPP_

#include "theta_sketch_experimental.hpp"
#include "theta_intersection_base.hpp"

namespace datasketches {

template<typename Allocator = std::allocator<uint64_t>>
class theta_intersection_experimental {
public:
  using Entry = uint64_t;
  using ExtractKey = trivial_extract_key;
  using Sketch = theta_sketch_experimental<Allocator>;
  using CompactSketch = compact_theta_sketch_experimental<Allocator>;

  struct pass_through_policy {
    uint64_t operator()(uint64_t internal_entry, uint64_t incoming_entry) const {
      unused(incoming_entry);
      return internal_entry;
    }
  };
  using State = theta_intersection_base<Entry, ExtractKey, pass_through_policy, Sketch, CompactSketch, Allocator>;

  explicit theta_intersection_experimental(uint64_t seed = DEFAULT_SEED, const Allocator& allocator = Allocator());

  /**
   * Updates the intersection with a given sketch.
   * The intersection can be viewed as starting from the "universe" set, and every update
   * can reduce the current set to leave the overlapping subset only.
   * @param sketch represents input set for the intersection
   */
  template<typename FwdSketch>
  void update(FwdSketch&& sketch);

  /**
   * Produces a copy of the current state of the intersection.
   * If update() was not called, the state is the infinite "universe",
   * which is considered an undefined state, and throws an exception.
   * @param ordered optional flag to specify if ordered sketch should be produced
   * @return the result of the intersection
   */
  CompactSketch get_result(bool ordered = true) const;

  /**
   * Returns true if the state of the intersection is defined (not infinite "universe").
   * @return true if the state is valid
   */
  bool has_result() const;

private:
  State state_;
};

} /* namespace datasketches */

#include "theta_intersection_experimental_impl.hpp"

#endif