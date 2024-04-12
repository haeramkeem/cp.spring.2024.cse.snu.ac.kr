cmake_minimum_required(VERSION 3.0)
project(hw.cp24s.cse.snu.ac.kr)
add_executable(lint main.cc linter.cc)
set_property(TARGET lint PROPERTY CXX_STANDARD 17)
