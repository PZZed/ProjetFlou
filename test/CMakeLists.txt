project(Google_tests)

link_directories(/usr/local/lib)

add_executable(tests core/ValueModelTest.cpp fuzzy/NotMinus1Test.cpp fuzzy/IsTriangle.cpp core/UnaryExpressionModelTest.cpp fuzzy/AggMaxTest.cpp fuzzy/AggPlus.cpp fuzzy/AndMin.cpp fuzzy/IsGaussian.cpp fuzzy/AndMult.cpp fuzzy/OrMax.cpp fuzzy/OrPlus.cpp fuzzy/ThenMin.cpp fuzzy/ThenMult.cpp core/BinaryExpressionModel.cpp fuzzy/FuzzyFactoryTest.cpp fuzzy/IsTrapeze.cpp fuzzy/IsBell.cpp core/BinaryShadowExpressionTest.cpp core/UnaryShadowExpressionTest.cpp)

target_link_libraries(tests gmock gtest pthread)
target_link_libraries(tests libgtest.a libgtest_main.a)
