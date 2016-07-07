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
