[
{ "gen_sh": {
    "name": "glog_gen",
    "build_cmd": "mkdir -p $OBJ_DIR; DEST_DIR=$(pwd)/$GEN_DIR; CXXFLAGS=\"$BASIC_CXXFLAGS $DEP_FLAGS\" CFLAGS=\"$BASIC_CFLAGS $DEP_FLAGS\" LDFLAGS=\"$LDFLAGS\" CC=\"$CC\" CXX=\"$CXX\" ./configure --prefix=/ --cache-file=$GEN_DIR/config.cache && make install DESTDIR=$(pwd)/$GEN_DIR",
    "clean": "make DESTDIR=$(pwd)/$GEN_DIR clean",
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