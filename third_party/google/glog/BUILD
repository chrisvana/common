[
{ "autoconf": {
    "name": "glog_gen",
    "outs": [ "lib/libglog.a" ]
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