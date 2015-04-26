#!/usr/bin/python

import sys

if len( sys.argv ) < 3:
  print"mooop"
  sys.exit(-1)

try:
  fin1 = open( sys.argv[1], 'rt' )
  fin2 = open( sys.argv[2], 'rt' )
except:
  exit(-1)
  

for line1 in fin1:

  for line2 in fin2:
  
    sys.stdout.write( line1.strip("\n") )
    sys.stdout.write( line2 )

  fin2.seek(0)

fin1.close()
fin2.close()

