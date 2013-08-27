[
{ "autoconf": {
    "name": "perf_gen",
    "outs": [ "lib/libprofiler.a",
              "lib/libtcmalloc_and_profiler.a",
              "lib/libtcmalloc_minimal.a",
              "lib/libtcmalloc.a",
              "lib/libtcmalloc_debug.a",
              "lib/libtcmalloc_minimal_debug.a"
    ]
} },
{ "cc_library": {
    "name": "perf_headers",
    "cc_headers": [ "src/*.h", "src/*/*.h", "src/*/*/*.h" ],
    "header_compile_args": [ "-I$SRC_DIR/src" ]
} },
{ "cc_library": {
    "name": "profiler",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} },
{ "cc_library": {
    "name": "libtcmalloc_and_profiler",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} },
{ "cc_library": {
    "name": "libtcmalloc_minimal",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} },
{ "cc_library": {
    "name": "libtcmalloc",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} },
{ "cc_library": {
    "name": "libtcmalloc_debug",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} },
{ "cc_library": {
    "name": "libtcmalloc_minimal_debug",
    "cc_objects": [ "$GEN_DIR/lib/libprofiler.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":perf_gen" ]
} }
]