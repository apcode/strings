// Copyright (c) 2016, Alan Patterson

// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef STRINGS_STRINGS_HPP_
#define STRINGS_STRINGS_HPP_

#include <vector>
#include <string>

namespace strings {

namespace {
// Deal with split/join by string or char.
inline std::string::size_type sep_size(const std::string& s) {
  return s.size();
}
inline std::string::size_type sep_size(const char& c) { return 1; }
inline std::string& sep_append(std::string& str, const std::string& sep) {
  return str.append(sep);
}
inline std::string& sep_append(std::string& str, const char& sep) {
  return str.append(1, sep);
}
}

// Split string using Sep.
std::vector<std::string> split(const std::string& str, const std::string& sep);
std::vector<std::string> split(const std::string& str, const char sep);

// Trim functions.
std::string ltrim(const std::string& str);
std::string rtrim(const std::string& str);
std::string trim(const std::string& str);

// Join container of string.
template <typename Iter, typename Sep>
std::string join(Iter begin, Iter end, const Sep& sep) {
  if (begin == end) {
    return "";
  }
  // WARNING:This won't work on a one-time iterator E.g. a
  // stream_iterator.
  std::string::size_type sz(0);
  Iter i(begin);
  for (; i != end; ++i) {
    sz += i->size() + sep_size(sep);
  }
  sz -= sep_size(sep);
  std::string result;
  result.reserve(sz);
  result.append(*begin++);
  for (; begin != end; ++begin) {
    sep_append(result, sep).append(*begin);
  }
  return result;
}

template <typename Container, typename Sep>
std::string join(const Container& container, const Sep& sep) {
  return join(std::begin(container), std::end(container), sep);
}
}

#endif /* STRINGS__STRINGS_HPP_ */
