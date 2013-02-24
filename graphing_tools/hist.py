#!/usr/bin/env python 




import os 
import sys
import pylab

from optparse import OptionParser

parser = OptionParser()

parser.add_option("-f", "--file", dest = "raw", help = "The raw file to be processed")
parser.add_option("-t", "--title", help = "The title of your chart")
parser.add_option("-x", "--xlabel", help = "The ylabel of your chart")
parser.add_option("-y", "--ylabel", help = "The xlabel of your chart")
parser.add_option("-b", "--bins", help = "The number of bins in the distribution")

options, args = parser.parse_args()
raw = options.raw
title = options.title
xlab = options.xlabel
ylab = options.ylabel
bins = options.bins

if not raw:
	print "Invalid Raw File"
	sys.exit(1)

if not os.path.isfile(raw):
	print "Invalid Raw File"
	sys.exit(1)


fh = open(raw, 'r')


data = []

print "Processing Data from file " + raw
for line in fh:
	line = line.strip()
	try:
		data.append(float(line))

	except:
		print "Unable to process data point: " + line
		print "Skipping.."





if title:
	print "Received title as: " + title
	pylab.title(title)


if xlab: 
	print "Recieved X-Label as: " + xlab
	pylab.xlabel(xlab)

if ylab:
	print "Recieved Y-Label as: " + ylab
	pylab.ylabel(ylab)
	
if not bins:
	pylab.hist(data, normed = True)
else:
	print 'plotting with: ' + bins
	pylab.hist(data, normed = True, bins = int(bins))

			
pylab.show()

