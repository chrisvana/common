[
{ "autoconf": {
    "name": "perf_gen",
    "outs": [ "$GEN_DIR/lib/libprofiler.a",
              "$GEN_DIR/lib/libtcmalloc_and_profiler.a",
              "$GEN_DIR/lib/libtcmalloc_minimal.a",
              "$GEN_DIR/lib/libtcmalloc.a",
              "$GEN_DIR/lib/libtcmalloc_debug.a",
              "$GEN_DIR/lib/libtcmalloc_minimal_debug.a"
    ],
    "configure_env" : [
      "USER_CXXFLAGS=-msse4"
    ],
    // TODO(cvanarsdale): This doesn't seem to work on all platforms.
    //  *** Warning: Linking the shared library libglog.la against the
    //  non-libtool *** objects <cut> gflags_reporting.cc.o is not portable!
    //  /usr/bin/ld: <cut> gflags.cc.o: relocation R_X86_64_32S against
    //     `.rodata' can not be used when making a shared object; recompile
    //     with -fPIC
    //  <cut>/gflags.cc.o: error adding symbols: Bad value
    //  collect2: error: ld returned 1 exit status
    // "configure_args": [
    //   "--with-gflagssrc=\"$ROOT_DIR/$GFLAGS_SRC_ROOT\"",
    //   "--with-gflagslib=\"$ROOT_DIR/$GFLAGS_OBJS\""
    // ],
    // "dependencies": [ "//common/third_party/google/gflags:gflags" ],
    "licenses": [ "http://opensource.org/licenses/BSD-3-Clause" ]
} },
{ "cc_library": {
    "name": "atomicops",
    "cc_headers": [ "src/base/atomicops.h" ],
    "cc_include_dirs": [ "src" ],
    "dependencies": [ ":perf_gen" ]
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