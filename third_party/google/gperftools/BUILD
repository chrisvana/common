[
{ "autoconf": {
    "name": "perf_gen",
    "outs": [ "lib/libprofiler.a",
              "lib/libtcmalloc_and_profiler.a",
              "lib/libtcmalloc_minimal.a",
              "lib/libtcmalloc.a",
              "lib/libtcmalloc_debug.a",
              "lib/libtcmalloc_minimal_debug.a"
    ],
    "configure_env" : [
      "USER_CXXFLAGS=-msse4"
    ],
    "configure_args": [
      "--with-gflagssrc=\"$ROOT_DIR/$GFLAGS_SRC_ROOT\"",
      "--with-gflagslib=\"$ROOT_DIR/$GFLAGS_OBJS\""
    ],
    "dependencies": [ "//common/third_party/google/gflags:gflags" ]
} },
{ "cc_library": {
    "name": "profiler",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} },
{ "cc_library": {
    "name": "libtcmalloc_and_profiler",
    "cc_objects": [ "$GEN_DIR/lib/libtcmalloc_and_profiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} },
{ "cc_library": {
    "name": "libtcmalloc_minimal",
    "cc_objects": [ "$GEN_DIR/lib/libtcmalloc_minimal.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} },
{ "cc_library": {
    "name": "libtcmalloc",
    "cc_objects": [ "$GEN_DIR/lib/libtcmalloc.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} },
{ "cc_library": {
    "name": "libtcmalloc_debug",
    "cc_objects": [ "$GEN_DIR/lib/libtcmalloc_debug.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} },
{ "cc_library": {
    "name": "libtcmalloc_minimal_debug",
    "cc_objects": [ "$GEN_DIR/lib/libtcmalloc_minimal_debug.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ],
    "alwayslink": true
} }
]