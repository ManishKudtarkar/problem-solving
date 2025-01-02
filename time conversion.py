#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    if s[:2] == "12" and s[-2:] == "AM": 
        return "00" + s[2:-2]
    if s[-2:] == "AM":
        return s[:-2]
    # now only other "PM"s to check
    if s == "12:00:00PM": 
        return "12:00:00"
    if s[:2] == "12":
        return "12" + s[2:-2]
        
    return str(int(s[:2])+ 12) + s[2:-2]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
