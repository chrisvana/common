[
 { "autoconf": {
     "name": "stringencoders_conf",
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