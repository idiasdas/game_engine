include(GoogleTest)

file(GLOB test_sources ${PROJECT_SOURCE_DIR}/tests/*.cpp)

add_executable(tests ${test_sources})

target_link_libraries(tests PUBLIC
    GTest::gtest_main
    DDS_engine # Linking tests to the engine
)

gtest_discover_tests(tests)
