[
{ "autoconf": {
    "name": "glog_gen",
    "outs": [ "$GEN_DIR/lib/libglog.a" ],
    "configure_args": [
      "--with-gflagssrc=\"$ROOT_DIR/$GFLAGS_SRC_ROOT\"",
      "--with-gflagslib=\"$ROOT_DIR/$GFLAGS_OBJS\""
    ],
    "dependencies": [ "//common/third_party/google/gflags:gflags" ],
    "licenses": [ "http://opensource.org/licenses/BSD-3-Clause" ]
} },

{ "cc_library": {
    "name": "glog",
    "cc_objects": [ "$GEN_DIR/lib/libglog.a" ],
    "cc_include_dirs" : [ "src" ],
    "strict_file_mode": false,
    "dependencies": [ ":glog_gen" ]
} }
]