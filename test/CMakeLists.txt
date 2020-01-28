project(Google_tests)

link_directories(/usr/local/lib)

add_executable(tests core/ValueModelTest.cpp)

target_link_libraries(tests gmock gtest pthread)
target_link_libraries(tests libgtest.a libgtest_main.a)
