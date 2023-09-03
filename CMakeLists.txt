cmake_minimum_required(VERSION 3.20)
project(Nonogram VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_subdirectory(src)

add_library(src_objs OBJECT ${SRCS})
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE src_objs)
# target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -fsanitize=address -O0 -g)
# target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -fsanitize=address)

# unit tests
find_package(GTest REQUIRED)

add_subdirectory(tests)
add_executable(UnitTests ${UNIT_TESTS})
target_link_libraries(UnitTests PUBLIC GTest::gtest GTest::gtest_main src_objs)
target_include_directories(UnitTests PRIVATE src)
target_compile_options(UnitTests PUBLIC -fsanitize=address -O0 -g)
target_link_options(UnitTests PRIVATE -fsanitize=address)


# unit tests with coverage
add_executable(UnitTestsGcov ${UNIT_TESTS} ${SRCS})
target_include_directories(UnitTestsGcov PRIVATE src)
target_compile_options(UnitTestsGcov PUBLIC -fprofile-arcs -ftest-coverage -O0 -g)
target_link_libraries(UnitTestsGcov PUBLIC gcov GTest::gtest GTest::gtest_main)


add_custom_target(TestsGcovTarget
    COMMAND find . -name "*.gcda" -delete
    COMMAND lcov -i --exclude '/usr/*'  --exclude '*tests*' -d ${CMAKE_BINARY_DIR} --capture --output-file coverage_initial.info --ignore-errors mismatch
    COMMAND $<TARGET_FILE:UnitTestsGcov>
    COMMAND lcov --exclude '/usr/*' --exclude '*tests*' -d ${CMAKE_BINARY_DIR} --capture --output-file coverage_test.info --ignore-errors mismatch
    COMMAND lcov -a coverage_initial.info -a coverage_test.info -o coverage.info
    COMMAND genhtml --function-coverage --branch-coverage coverage.info --output-directory coverage
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)