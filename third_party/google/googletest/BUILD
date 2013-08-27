[
{ "cc_library": {
    "name": "googletest",
    "cc_sources": [ "src/gtest-all.cc" ],
    "cc_headers": [ "include/gtest/*.h",
                    "include/gtest/*/*.h" ],
    "header_compile_args": [ "-I$SRC_DIR/include" ],
    "cc_compile_args": [ "-I$SRC_DIR" ]
} },
{ "cc_library": {
    "name": "googletest_main",
    "cc_sources": [ "src/gtest_main.cc" ],
    "dependencies": [ ":googletest" ]
} }
]