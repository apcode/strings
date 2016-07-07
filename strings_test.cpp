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
