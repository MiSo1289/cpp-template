# C++ template
This is a C++20 project template for the Conan package manager.

## Features
- CMake project skeleton with a library, and a CLI executable powered by Lyra.
- Unit testing skeleton using Catch2 and Trompeloeil for mocking.
- Many other useful libraries to choose from included out of the box.
- Documentation target is created when Doxygen is installed.

## Usage
Clone this repository into `~/.conan/templates/command/new/`:
```shell script
$ mkdir -p ~/.conan/templates/command/new
$ cd ~/.conan/templates/command/new
$ gh repo clone MiSo1289/cpp-template
```

Create your new project from the template:
```shell script
$ mkdir -p ~/Projects/my_project
$ cd ~/Projects/my_project
$ conan new my_project/0.0.0 --template cpp-template  
```

Install dependencies, then build and run:
```shell script
$ conan install . -if build
$ cd build
$ cmake ..
$ cmake --build . --target my_project_tests
$ bin/my_project_tests
$ cmake --build . --target my_project_executable
$ bin/my_project_executable --help
```
