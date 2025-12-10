✅ 1. What scripting language does CMake use?

CMake uses its own scripting language, called:

CMake Language (also called CMake Scripting Language or CMake DSL)

It is NOT:

Bash

Python

Lua

Makefile syntax

It is a custom DSL created specifically for build configuration.

The language has:

Variables (set())

Conditions (if())

Loops (foreach(), while())

Functions (function())

Macros (macro())

Built-in commands (add_executable, target_link_libraries, etc.)

Files are written in:

CMakeLists.txt

✅ 2. What are CMake commands?

CMake commands are the built-in functions and language keywords you use inside CMakeLists.txt.

Here is a list of the most important ones, grouped by purpose.

🔨 Project Setup Commands
Command	Purpose
cmake_minimum_required()	Specify the minimum CMake version
project()	Define project name, version, languages
📁 Source File & Target Commands
Command	Purpose
add_executable()	Create an executable
add_library()	Create a library (static/shared)
target_sources()	Add source files to a target
target_include_directories()	Add include directories
target_link_libraries()	Link libraries to a target
🧩 Build Configuration Commands
Command	Purpose
set()	Set variables
option()	Create ON/OFF options
configure_file()	Create config header files
🔍 Flow Control Commands
Command	Purpose
if(), elseif(), else(), endif()	Conditions
foreach(), endforeach()	Loops
while(), endwhile()	Loops
function()	Create a function
macro()	Create a macro
📦 Package & Dependency Commands
Command	Purpose
find_package()	Find installed packages (Boost, SDL, OpenGL...)
find_library()	Find library files
include()	Include other CMake files
add_subdirectory()	Add another CMake project/submodule
📤 Installation & Export Commands
Command	Purpose
install()	Install targets, binaries, headers
export()	Export targets for other projects
📚 Example of a simple CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(MyApp VERSION 1.0 LANGUAGES CXX)

add_executable(MyApp main.cpp utils.cpp)

target_include_directories(MyApp
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

🧠 Summary (Very Simple)

CMake uses its own scripting language (CMake DSL)

Commands include:
add_executable, target_link_libraries, set, if, foreach, find_package, etc.

The language lets you configure how your project is built, linked, and installed.