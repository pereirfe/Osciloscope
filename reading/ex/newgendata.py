#!/usr/bin/python

import math
import time

# Loop
degrees = 0
T = 0.001
k = 0
while True:
  # Generate three data points
  data = ""
  degrees = 0
  for i in range(2000):
    si =k+ math.sin(math.radians(degrees))
    # Write 3 data points to text file
    data += "{} {}\n".format(degrees,si)
    degrees += 1
    time.sleep(T)
  f = open('mydata.dat', 'w')
  f.write(data)
  f.flush()
  k+= 0.05
  f.close()

