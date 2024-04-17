cmake_minimum_required(VERSION 3.0)
project(hw02.cp24s.cse.snu.ac.kr)
add_executable(lint main.cc linter.cc lv1_stack_linter.cc lv2_queue_linter.cc)
set_property(TARGET lint PROPERTY CXX_STANDARD 17)
