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
     "header_compile_args": [ "-Icommon/third_party/google/gflags/src" ],
     "env": {
       "GFLAGS_SRC_ROOT" : "$SRC_DIR/src",
       "GFLAGS_LIB_ROOT" : "$OBJ_DIR"
     }
} }
]