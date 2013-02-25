#!/usr/bin/env python

import pylab 
import sys
import os


plotDict = {}
titleDict = {}
if len(sys.argv) != 2:
	print "Incorrect Usage"	
	sys.exit(1)

graph_file = sys.argv[1]


markers = [ 'o', 'D', 'h', '+', '*', 'v', 'x' ] 
colours = ['b', 'g', 'r', 'c', 'm', 'y', 'k' ] 
lineDict ={}
scatterDict = {}
logxDict = {}
histDict = {}


def processKeyValues(_dict):
	if _dict['xlabel'] != None:
		pylab.xlabel(_dict['xlabel'])
	if _dict['ylabel'] != None:
		pylab.ylabel(_dict['ylabel'])
	if _dict['title'] != None:
		pylab.title(_dict['title'])


def parseKeyValues(keyString):

		_dict = {}

		_dict['xlabel'] = None
		_dict['ylabel'] = None
		_dict['title'] = None
		_dict['legend'] = None

		pairs = keyString.split(',')
		for pair in pairs:
			try:
				keyval = pair.strip().split('=')
				key = keyval[0].strip().lower()
				val = keyval[1].strip()

				if key == 'xlabel' or key == 'ylabel' or key == 'title' or key == 'legend':
					_dict[key] = val

			except:
			
				print 'Warning ignoring: ' + pair

		return _dict 

def graph_plot():

   for key in plotDict.keys():
	
	if key == 'line':
		pylab.figure()
		index = 0
		flag = False
		for value in plotDict[key]:
			lab = titleDict[key][index]
			if lab != "None":
				flag = True
			pylab.plot(value, label = lab)
			index += 1	
		if flag:
			pylab.legend();
		processKeyValues(lineDict)

	if key == 'logx':
		pylab.figure()
		index = 0
		flag = False
		for value in plotDict[key]:
			lab = titleDict[key][index]
			
			if lab != "None":
				flag = True

			pylab.semilogx(value, label=lab)
			index += 1
		if flag:
			pylab.legend()

		processKeyValues(logxDict)


	elif key == 'scatter':
		pylab.figure()
		ctr = 0
		index = 0
		flag = False
		for value in plotDict[key]:
			
			if ctr == 7:
				print "scatter limit"
			lab = titleDict[key][index]

			if lab != "None":
				flag = True
			pylab.scatter(value[0], value[1], label = lab,marker=markers[ctr], color=colours[ctr])
			index += 1
			ctr += 1
		if flag:
			pylab.legend()
		processKeyValues(scatterDict)

	elif key == 'hist':
		pylab.figure()
		index = 0
		flag = False
		for value in plotDict[key]:
			lab = titleDict[key][index]
			if lab != "None":
				flag = True
			pylab.hist(value, normed = True, label=lab)
			index += 1
		if flag:
			pylab.legend()
		processKeyValues(histDict)



def getList(raw):
	raw = raw.strip()
	raw = raw.split(',')
	raw = map(float, raw)
	return raw
	
if not os.path.isfile(graph_file):
	print 'Invalid File'
	sys.exit(1)

fh = open(graph_file, 'r')

for line in fh:

	try:

		tokens = line.split(":")

		gtype = tokens[0].strip()

		if gtype == "scatter":
			try:
				keyValueStr = tokens[3].strip() 
			except:
				keyValueStr = ""
				
			scatterDict = parseKeyValues(keyValueStr)

			title = str(scatterDict['legend'])

			glist_x = getList(tokens[1])
			glist_y = getList(tokens[2])
			lst = []
			lst.append(glist_x)
			lst.append(glist_y)

        	        if gtype not in plotDict.keys():
                	        plotDict[gtype] = []
                        	titleDict[gtype] = []
	                        plotDict[gtype].append(lst)
        	                titleDict[gtype].append(title)
                	else:
                        	plotDict[gtype].append(lst)
        	                titleDict[gtype].append(title)
	
			continue
		try:	
	
			keyValueStr = tokens[2].strip()
			
		except:
			keyValueStr = ""

		if gtype == 'line':
			lineDict = parseKeyValues(keyValueStr)
			title = str(lineDict['legend'])
		if gtype == 'hist':
			histDict = parseKeyValues(keyValueStr)
			title = str(histDict['legend'])
		if gtype == 'logx':
			logxDict = parseKeyValues(keyValueStr)
			title = str(logxDict['legend'])

		

		if gtype not in plotDict.keys():
			plotDict[gtype] = []
			titleDict[gtype] = []
			plotDict[gtype].append(getList(tokens[1]))
			titleDict[gtype].append(title)
		else:
			plotDict[gtype].append(getList(tokens[1]))
			titleDict[gtype].append(title)
		
	except:
		'print Malformed data'
		continue


graph_plot()		
pylab.show()

