[
{ "gen_sh": {
    "name": "glog_gen",
    "build_cmd": "DEST_DIR=$(pwd)/$GEN_DIR; CXXFLAGS=\"$BASIC_CXXFLAGS\" CFLAGS=\"$BASIC_CFLAGS\" LDFLAGS=\"$LDFLAGS\" CC=\"$CC\" CXX=\"$CXX\" ./configure --prefix=/ --cache-file=$GEN_DIR/config.cache && make install DESTDIR=$(pwd)/$GEN_DIR",
    "outs": [ "lib/libglob.a" ]
} },
{ "cc_library": {
    "name": "glog_headers",
    "cc_headers": [ "src/*.h", "src/*/*.h", "src/*/*/*.h" ],
    "cc_header_args": [ "-I$SRC_DIR/src" ]
} },
{ "cc_library": {
    "name": "glog",
    "cc_objects": [ "$GEN_DIR/lib/libglog.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":glog_gen", ":glog_headers" ]
} }
]