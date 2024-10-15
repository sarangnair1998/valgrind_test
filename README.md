# Valgrind Exercise

## Standard install via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# To build with debugging information, do:
  cmake -S ./ -B build/ -D CMAKE_BUILD_TYPE=Debug
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

# Question and Answers

## What happens when the executable is linked statically?  Does Valgrind still detect those same bugs?


Even with a statically linked executable, Valgrind can still find fundamental problems like memory leaks and uninitialized variables. On the other hand, if a bug was tied to the behavior of dynamically loaded libraries, its behavior might change, and some issues might become more difficult to find.


## Why or why not.

This occurs because the executable's overall memory structure is altered by static linking, which also incorporates all required libraries. This may mask flaws that are only visible when libraries are dynamically linked and maintained independently.