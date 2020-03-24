#!/bin/env python3
from xml.dom import minidom
import os
import sys
filename = sys.argv[-1]
if filename.split('.')[-1] != 'tmx':
    print("Please give a tmx file", file=sys.stderr)
    exit(1)
cfilename = filename.split('.')[0] + '_tmap.c'
xmldoc = minidom.parse(filename)
tmxmap = xmldoc.getElementsByTagName('map')[0]

if tmxmap.attributes['width'].value != "10" and tmxmap.attributes['height'].value != "9":
    print("Map must be 9 tiles high and 10 tiles wide!", file=sys.stderr)
    exit(2)

file = open(cfilename,'w')
file.write('//Generated from ' + filename + '\n')

layers = xmldoc.getElementsByTagName('layer')
for l in layers:
    name = os.path.basename(filename).split('.')[0] + '_tmap_' + l.attributes['name'].value
    file.write('const unsigned int ' + name + '[] = {' + l.getElementsByTagName('data')[0].firstChild.nodeValue + '};\n')
file.close() 
print('File written to ' + cfilename)