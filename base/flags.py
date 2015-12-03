# Copyright 2013
# Author: Christopher Van Arsdale
#
# See common/third_party/google/gflags_python/gflags for info
#
# Examlpe:
#  import common.base.flags
#  import sys
#
#  FLAGS = flags.FLAGS
#  flags.d.DEFINE_bool('my_bool', false, 'My description')
#
#  def main(argv):
#    flags.Parse(argv)
#    ... use FLAGS.my_bool as boolean ...
#
#  if __name__ == "__main__":
#    main(sys.argv)

import sys
import common.third_party.google.gflags_python.gflags as gflags

# Interface simplification
d = gflags
FLAGS = gflags.FLAGS

def Parse(argv):
  try:
    argv = FLAGS(argv)
  except gflags.FlagsError, e:
    print '%s\\nUsage: %s ARGS\\n%s' % (e, sys.argv[0], FLAGS)
    sys.exit(1)
