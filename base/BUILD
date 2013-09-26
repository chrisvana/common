 [
 { "cc_library": {
     "name" : "flags",
     "cc_headers" : [ "flags.h" ],
     "dependencies": [ "//common/third_party/google/gflags:gflags" ]
   }
 },

 { "py_library": {
     "name" : "py_flags",
     "py_sources" : [ "flags.py" ],
     "dependencies": [ "//common/third_party/google/gflags_python:gflags" ]
   }
 },

 { "cc_library": {
     "name" : "callback",
     "cc_headers": [ "callback.h" ],
     "dependencies": [ ":macros" ]
   }
 },
 { "cc_library": {
     "name" : "init",
     "cc_sources": [ "init.cc" ],
     "cc_headers" : [ "init.h" ],
     "dependencies": [ "//common/log:log",
                       "//common/third_party/google/init:init",
                       ":flags" ]
   }
 },
 { "cc_library": {
     "name" : "macros",
     "cc_headers" : [ "macros.h" ]
   }
 },
 { "cc_library": {
     "name" : "mutex",
     "cc_headers" : [ "mutex.h" ]
   }
 },
 { "cc_library": {
     "name" : "time",
     "cc_sources" : [ "time.cc" ],
     "cc_headers" : [ "time.h", "rdtsc.h" ]
   }
 },
 { "cc_library": {
     "name" : "types",
     "cc_headers" : [ "types.h" ]
   }
 },
 { "cc_library": {
     "name" : "base_nomalloc",
     "dependencies": [ ":flags",
                       ":init",
                       ":macros",
                       ":mutex",
                       ":time",
                       ":types" ]
   }
 },

 { "cc_library": {
    "name": "tcmalloc_perf",
    "dependencies": [
         "//common/third_party/google/gperftools:libtcmalloc_and_profiler"
    ]
 } },

 { "cc_library": {
     "name" : "base",
     "dependencies": [ ":base_nomalloc", ":tcmalloc_perf" ]
   }
 }
]