#!/usr/bin/python3
import sys

size = 0
count = 0
codes = {'200': 0, '301': 0, '400': 0,
         '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}

for x in sys.stdin:
    myStr = x[::-1]
    idx = myStr.find('"')
    myStr = myStr[0:idx]
    myStr = myStr.strip()[::-1]
    codeSize = myStr.split()
    codes[codeSize[0]] += 1
    size += int(codeSize[1])
    count += 1
    if (count == 10):
        count = 0
        print("File size: {}".format(size))

        for x, y in codes.items():
            if (y > 0):
                print("{}: {}".format(x, y))
