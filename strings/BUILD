[
 { "cc_library": {
     "name" : "stringpiece",
     "cc_headers": [ "stringpiece.h" ],
     "dependencies": [ "//common/third_party/google/re2:re2" ]
   }
 },
 { "cc_library": {
     "name" : "strutil",
     "cc_sources" : [ "strutil.cc", "path.cc", "varmap.cc" ],
     "cc_headers" : [ "strutil.h", "path.h", "varmap.h" ],
     "dependencies": [ "//common/third_party/stringencoders:stringencoders",
                       ":stringpiece" ]
   }
 },
 { "cc_library": {
     "name" : "bits",
     "cc_sources" : [ "bits.cc" ],
     "cc_headers" : [ "bits.h" ],
     "dependencies": [ "//common/base:types", ":stringpiece" ]
   }
 }
]