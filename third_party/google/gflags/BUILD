[
{ "cc_library": {
    "name": "gflags",
    "cc_headers": [ "src/util.h",
                    "src/google/*.h"
     ],
     "cc_sources": [ "src/gflags.cc",
                     "src/gflags_completions.cc",
                     "src/gflags_nc.cc",
                     "src/gflags_reporting.cc"
     ],
     "gcc": {
        "cc_compile_args": [ "-Wno-error=unused-local-typedefs" ]
     },
     "header_compile_args": [ "-I$SRC_DIR/src" ],
     "env": {
       "GFLAGS_SRC_ROOT" : "$SRC_DIR/src",
       "GFLAGS_OBJS" : "$OBJ_DIR/src/*.o"
     },
     "licenses": [ "http://opensource.org/licenses/BSD-3-Clause" ]
} }
]