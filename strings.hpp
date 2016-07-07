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
