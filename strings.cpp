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
#include <cctype>
#include <iostream>
#include "strings.hpp"

namespace {
template <typename Sep>
std::vector<std::string> split_impl(const std::string& str, const Sep& sep) {
  std::vector<std::string> result;
  std::string::size_type last(0);
  auto index = str.find(sep, last);
  while (index != std::string::npos) {
    // last is start of string without sep, index is end.
    result.emplace_back(str.substr(last, index - last));
    last = index + strings::sep_size(sep);
    index = str.find(sep, last);
  }
  result.emplace_back(str.substr(last));
  return result;
}
}

namespace strings {

std::vector<std::string> split(const std::string& str, const std::string& sep) {
  return split_impl(str, sep);
}

std::vector<std::string> split(const std::string& str, const char sep) {
  return split_impl(str, sep);
}

std::string ltrim(const std::string& str) {
  if (str.empty() || !std::isspace(str.front())) {
    return str;
  }
  auto start = str.find_first_not_of(" \n\t\v\f\r");
  return str.substr(start);
}

std::string rtrim(const std::string& str) {
  if (str.empty() || !std::isspace(str.back())) {
    return str;
  }
  auto end = str.find_last_not_of(" \n\t\v\f\r");
  return str.substr(0, end + 1);
}

std::string trim(const std::string& str) {
  if (str.empty() ||
      (!std::isspace(str.front()) && !std::isspace(str.back()))) {
    return str;
  }
  auto start = str.find_first_not_of(" \n\t\v\f\r");
  auto end = str.find_last_not_of(" \n\t\v\f\r");
  return str.substr(start, end - start + 1);
}
}
