

import sys
print(sys.argv)
with open(sys.argv[1], "w") as f:
    f.write("test_file")