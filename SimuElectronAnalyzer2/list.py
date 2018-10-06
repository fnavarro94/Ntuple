import sys


f = open(sys.argv[1], 'r')

for i in  f:
	print  "\'"+i[:-1]+"\',"
