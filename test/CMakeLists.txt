project(Google_tests)

link_directories(/usr/local/lib)

add_executable(tests core/ValueModelTest.cpp fuzzy/NotMinus1Test.cpp fuzzy/IsTriangle.cpp core/UnaryExpressionModelTest.cpp fuzzy/AggMaxTest.cpp fuzzy/AggPlus.cpp fuzzy/AndMin.cpp fuzzy/AndMult.cpp fuzzy/OrMax.cpp)

target_link_libraries(tests gmock gtest pthread)
target_link_libraries(tests libgtest.a libgtest_main.a)
