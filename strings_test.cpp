#include "gtest/gtest.h"
#include <vector>
#include "strings.hpp"

using namespace strings;

////////////////////////////////////////////////////////////////////////////////
// Split Tests.
//
TEST(Split, SplitStringsByString) {
  std::string test = "A::B::C";
  auto splits = split(test, "::");
  EXPECT_EQ(3, splits.size());
  EXPECT_EQ("A", splits[0]);
  EXPECT_EQ("B", splits[1]);
  EXPECT_EQ("C", splits[2]);
}


TEST(Split, SplitStringsByChar) {
  std::string test = "A:B:C";
  auto splits = split(test, ':');
  EXPECT_EQ(3, splits.size());
  EXPECT_EQ("A", splits[0]);
  EXPECT_EQ("B", splits[1]);
  EXPECT_EQ("C", splits[2]);
}

TEST(Split, SplitEmpty) {
  std::string test = "";
  auto splits = split(test, ':');
  EXPECT_EQ(1, splits.size());
  EXPECT_EQ("", splits[0]);
}

TEST(Split, NoSeparators) {
  std::string test = "A,B,C";
  auto splits = split(test, ':');
  EXPECT_EQ(1, splits.size());
  EXPECT_EQ("A,B,C", splits[0]);  
}

TEST(Split, MultiCharSeps) {
  std::string test = "A::B:C";
  auto splits = split(test, ':');
  EXPECT_EQ(4, splits.size());
  EXPECT_EQ("A", splits[0]);
  EXPECT_EQ("", splits[1]);
  EXPECT_EQ("B", splits[2]);
  EXPECT_EQ("C", splits[3]);  
}

TEST(Split, SplitBorderSep) {
  std::string test = ":B:C";
  auto splits = split(test, ':');
  EXPECT_EQ(3, splits.size());
  EXPECT_EQ("", splits[0]);
  EXPECT_EQ("B", splits[1]);
  EXPECT_EQ("C", splits[2]);  
  test = "A:B:";
  splits = split(test, ':');
  EXPECT_EQ(3, splits.size());
  EXPECT_EQ("A", splits[0]);
  EXPECT_EQ("B", splits[1]);
  EXPECT_EQ("", splits[2]);  
}

////////////////////////////////////////////////////////////////////////////////
// Join Tests.
//
TEST(Join, JoinVectorByString) {
  std::vector<std::string> v = { "A", "B", "C" };
  std::string joined = join(v, "::");
  EXPECT_EQ("A::B::C", joined);
}

TEST(Join, JoinVectorByChar) {
  std::vector<std::string> v = { "A", "B", "C" };
  std::string joined = join(v, ':');
  EXPECT_EQ("A:B:C", joined);
}

TEST(Join, JoinSet) {
  std::set<std::string> v = { "A", "B", "C" };
  std::string joined = join(v, ":");
  EXPECT_EQ("A:B:C", joined);
}

TEST(Join, Empty) {
  std::vector<std::string> v;
  std::string joined = join(v, ':');
  EXPECT_EQ("", joined);
}

TEST(Join, EmptyElement) {
  std::vector<std::string> v = { "A", "", "C" };
  std::string joined = join(v, ":");
  EXPECT_EQ("A::C", joined);
}

TEST(Join, EmptyStart) {
  std::vector<std::string> v = { "", "B", "C" };
  std::string joined = join(v, ":");
  EXPECT_EQ(":B:C", joined);
}

////////////////////////////////////////////////////////////////////////////////
// Trim Tests.
//
TEST(Trim, Left) {
  std::string str = " \t\nTest";
  std::string trimmed = ltrim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, LeftNoSpace) {
  std::string str = "Test";
  std::string trimmed = ltrim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, LeftRightSpace) {
  std::string str = "  Test  \t\n";
  std::string trimmed = ltrim(str);
  EXPECT_EQ("Test  \t\n", trimmed);
}

TEST(Trim, Right) {
  std::string str = "Test \t\n";
  std::string trimmed = rtrim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, RightNoSpace) {
  std::string str = "Test";
  std::string trimmed = rtrim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, RightLeftSpace) {
  std::string str = "  \t\nTest  \t\n";
  std::string trimmed = rtrim(str);
  EXPECT_EQ("  \t\nTest", trimmed);
}

TEST(Trim, Both) {
  std::string str = " \t\nTest \t\n";
  std::string trimmed = trim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, BothNoSpace) {
  std::string str = "Test";
  std::string trimmed = trim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, LeftSpace) {
  std::string str = " \t\nTest";
  std::string trimmed = trim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, RightSpace) {
  std::string str = "Test \t\n";
  std::string trimmed = trim(str);
  EXPECT_EQ("Test", trimmed);
}

TEST(Trim, MiddleSpace) {
  std::string str = "  Te  st \t\n";
  std::string trimmed = trim(str);
  EXPECT_EQ("Te  st", trimmed);
}
