#!/bin/env python3
from xml.dom import minidom
import argparse
import os
import sys

#decrement integer in string
def decstr(s):
    if s == '' or s == 0:
        return s
    else:
        return str(int(s)-1)

parser = argparse.ArgumentParser()
parser.add_argument('tmx', metavar='map.tmx', help='Tiled map file')
parser.add_argument("--output", "-o", default="", help="Name for generated c files")
global args
args = parser.parse_args()

if args.tmx.split('.')[-1] != 'tmx':
    print("Please give a .tmx file", file=sys.stderr)
    exit(1)
filename = args.tmx
cfilename = filename.split('.')[0] + '_tmap.c'
if args.output != "":
    cfilename = args.output

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
    row = l.getElementsByTagName('data')[0].firstChild.nodeValue
    # decrease each number 1,2,3->0,1,2
    row = ",".join(map(lambda s: decstr(s),row.split(',')))
    file.write('const uint8_t ' + name + '[] = {' + row + '};\n')
file.close()
print('File written to ' + cfilename)