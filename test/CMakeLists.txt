include_directories(../src/)
add_executable(test.wt main.cpp)
target_link_libraries(test.wt wt wthttp wtsandbox)
