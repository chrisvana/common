[
{ "autoconf": {
    "name": "glog_gen",
    "outs": [ "lib/libglog.a" ],
    "configure_args": [
      "--with-gflagssrc=\"$ROOT_DIR/$GFLAGS_SRC_ROOT\"",
      "--with-gflagslib=\"$ROOT_DIR/$GFLAGS_LIB_ROOT/src/*.o\""
    ],
    "dependencies": [ "//common/third_party/google/gflags:gflags" ]
} },

{ "cc_library": {
    "name": "glog_headers",
    "cc_headers": [ "src/*.h", "src/*/*.h", "src/*/*/*.h" ],
    "header_compile_args": [ "-I$SRC_DIR/src" ]
} },
{ "cc_library": {
    "name": "glog",
    "cc_objects": [ "$GEN_DIR/lib/libglog.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":glog_gen", ":glog_headers" ]
} }
]