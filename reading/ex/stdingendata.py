#!/usr/bin/python

import math
import time
import sys

f = sys.stdout
# Loop
degrees = 0
while True:
  # Generate three data points
  si = math.sin(math.radians(degrees))
  co = 0.5 * math.cos(math.radians(degrees))
  if si>0:
    sq = 0.6
  else:
    sq = -0.6
  # Write 3 data points to text file
  data = "{} {} {} {}\n".format(degrees,si,co,sq)
  f.write(data)
  f.flush()
  degrees += 1
  time.sleep(0.0001)
f.close()
