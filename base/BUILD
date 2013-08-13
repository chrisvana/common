 [
 { "cc_library": {
     "name" : "flags",
     "cc_sources": [ "flags.cc" ],
     "cc_headers" : [ "flags.h" ]
   }
 },
 { "cc_library": {
     "name" : "init",
     "cc_sources": [ "init.cc" ],
     "cc_headers" : [ "init.h" ],
     "dependencies": [ ":flags" ]
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
     "name" : "base",
     "dependencies": [ ":flags",
                       ":init",
                       ":macros",
                       ":mutex",
                       ":time",
                       ":types" ]
   }
 }
]