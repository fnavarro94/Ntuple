#!/usr/bin/python

import sys

fileName = sys.argv[1]
mfile = open(fileName,'r')
for x, l in enumerate(mfile):
 	print  '\''+ l[:-1] + '\','
 	
 	if (x%100 == 0):
		print '\n'
	
	
	
