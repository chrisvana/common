[
 { "cc_library": {
     "name" : "stringpiece",
     "cc_headers" : [ "stringpiece.h", "re2/stringpiece.h" ],
     "cc_sources" : [ "re2/stringpiece.cc" ]
   }
 },
 { "cc_library": {
     "name" : "strutil",
     "cc_sources" : [ "strutil.cc", "path.cc", "varmap.cc",
                      "re2/stringprintf.cc" ],
     "cc_headers" : [ "strutil.h", "path.h", "varmap.h" ],
     "dependencies": [ ":stringpiece" ]
   }
 }
]