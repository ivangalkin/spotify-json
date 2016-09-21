/*
 * Copyright (c) 2014-2016 Spotify AB
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#pragma once

#include <spotify/json/detail/macros.hpp>

namespace spotify {
namespace json {
namespace detail {

template <typename char_type>
struct char_traits {
  json_force_inline static bool is_space(const char_type c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
  }

  json_force_inline static bool is_digit(const char_type c) {
    return (c >= '0' && c <= '9');
  }

  json_force_inline static bool is_hex_digit(const char_type c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
  }

  json_force_inline static int to_integer(const char_type c) {
    return (c - '0');
  }

  json_force_inline static int to_integer_hex(const char_type c) {
    if (c >= '0' && c <= '9') return (c - '0');
    if (c >= 'a' && c <= 'f') return (c - 'a') + 0xA;
    if (c >= 'A' && c <= 'F') return (c - 'A') + 0xA;
    return 0;
  }
};

}  // namespace detail
}  // namespace json
}  // namespace spotify
