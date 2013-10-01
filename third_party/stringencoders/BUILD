[
 { "autoconf": {
     "name": "stringencoders_conf",
     "gcc" : {
       "configure_env": [
         "USER_CFLAGS=-Wno-error=unused-but-set-variable"
        ]
     },
     "outs": [ "lib/libmodpbase64.a" ]
 } },
 { "cc_library": {
    "name": "stringencoders",
    "cc_headers": [ "src/*.h" ],
    "cc_objects": [ "$GEN_DIR/lib/libmodpbase64.a" ],
    "strict_file_mode": false,
    "dependencies": [ ":stringencoders_conf" ]
 } }
]