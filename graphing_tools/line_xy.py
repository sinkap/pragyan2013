#!/usr/bin/env python 


import os 
import sys
import pylab

from optparse import OptionParser

parser = OptionParser()

parser.add_option("-f", "--file", dest = "raw", help = "The raw file to be processed")
parser.add_option("-s", "--scale", help = "Can be one of 'logx', 'logy', 'logxy' default is linear")
parser.add_option("-t", "--title", help = "The title of your chart")
parser.add_option("-x", "--xlabel", help = "The ylabel of your chart")
parser.add_option("-y", "--ylabel", help = "The xlabel of your chart")
parser.add_option("-m", "--multi", action = "store_true", help = "select this is you want to graph multiple lines on a single graph")

options, args = parser.parse_args()
raw = options.raw
title = options.title
xlab = options.xlabel
ylab = options.ylabel
scale = options.scale
multi = options.multi


def plotData(_data, legend = False):
	

	for key in _data.keys():
		flag = False

		if scale:
			if scale == 'logx':
				print "Received scale as logx"
				pylab.semilogx(_data[key]['x'],_data[key]['_y'], label = key)
				flag = True
	
			if scale == 'logy':
				print "Received scale as logy"
				if not legend:
					pylab.semilogy(_data[key]['x'], _data[key]['y'], label = key)
				flag = True
		
			if scale == 'logxy':
				print "Received scale as logx"
				pylab.loglog(_data[key]['x'],_data[key]['y'], label = key)
				flag = True
	
			if not flag:
				print "Ignoring Scale parameter: " + scale
				print "Using Linear Scale"
				pylab.plot(_data[key]['x'],_data[key]['y'], label = key)
			
		else:
		
			print "Using Linear Scale"
			pylab.plot(_data[key]['x'],_data[key]['y'], label = key)
			

		if legend:
			pylab.legend()

if not raw:
	print "Invalid Raw File"
	sys.exit(1)

if not os.path.isfile(raw):
	print "Invalid Raw File"
	sys.exit(1)


fh = open(raw, 'r')



print "Processing Data from file " + raw

if not multi:

	data = {}
	leg = '__DEFAULT__'
	data[leg] = {}
	data[leg]['x'] = []
	data[leg]['y'] = []

	for line in fh:
		line = line.strip()
		try:

			tokens = line.split(" ")
			x = tokens[0].strip()
			y = tokens[1].strip()
			data[leg]['x'].append(x)
			data[leg]['y'].append(y)

		except:
			print "Unable to process data point: " + line
			print "Skipping.."


	plotData(data)
else:
	leg = None
	plots = {}
	for line in fh:
		try:
			line = line.strip()
			if line.startswith("legend"):
				line = line.split("=")
				leg = line[1].strip()
				print "Identified series as " + leg
				plots[leg] = {}
				plots[leg]['x'] = []
				plots[leg]['y'] = []
				
			else:
				if not leg:	
					print "Check data: legend not defined"
					sys.exit(1)
				else:
					tokens = line.split(" ")
					x = tokens[0].strip()
					y = tokens[1].strip()
					plots[leg]['x'].append(x)
					plots[leg]['y'].append(y)
	
			
	

		except ValueError:
			print "Unable to process data point: " + line
		
	plotData(plots, True)




			

if title:
	print "Received title as: " + title
	pylab.title(title)


if xlab: 
	print "Recieved X-Label as: " + xlab
	pylab.xlabel(xlab)

if ylab:
	print "Recieved Y-Label as: " + ylab
	pylab.ylabel(ylab)
	

pylab.show()

