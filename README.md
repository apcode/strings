# Some string utilities for c++

This provides a few useful utilities for processing strings in c++. It has no external dependencies, except c++11, though the C++11 parts are minimal and could be easily removed.

## Build

The project has a BUILD file intended to be used within a Bazel workspace. It would be easy to add to any other build system though.

To use with bazel, you can add this git repo to your WORKSPACE file. It will then be pulled down when your build depends on it:

     git_repository(
          name = "strings",
          remote = "https://github.com/apcode/strings.git",
          commit = "f9b708db49b4468dd0ff1e3e70f5777eb4aaaefa",
     )

Alternatively, you can use git submodule by creating a third_party directory in your WORKSPACE to hold external libraries. Add the repo to that directory and then, assuming your directory is named strings, run test:
     
     > ls
     WORKSPACE third_party/
     > git submodule add  https://github.com/apcode/cppstrings.git third_party/strings
     > bazel test strings:strings_test

## Usage

For full examples of how to use, see the unit tests in strings_test.cpp.

Some examples:

     std::string test = "A::B::C";
     std::vector<std::string> splits = split(test, "::");

     std::vector<std::string> v = { "A", "B", "C" };
     std::string joined = join(v, "::");

     std::string str = " \t\nTest";
     std::string trimmed = ltrim(str);

     std::string str = " \t\nTest \t\n";
     std::string trimmed = trim(str);
