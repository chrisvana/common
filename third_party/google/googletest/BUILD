[
{ "cc_library": {
    "name": "googletest",
    "cc_sources": [ "src/gtest-all.cc" ],
    "cc_headers": [ "include/gtest/*.h",
                    "include/gtest/*/*.h" ],
    "cc_compile_args": [ "-I$SRC_DIR" ],
    "cc_include_dirs": [ "include" ],
    "licenses": [ "http://opensource.org/licenses/BSD-3-Clause" ]
} },
{ "cc_library": {
    "name": "googletest_main",
    "cc_sources": [ "src/gtest_main.cc" ],
    "dependencies": [ ":googletest" ]
} }
]