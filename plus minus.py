#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    p, n, z = [], [], []
    for i in arr:
        if i == 0:
            z.append(i)
        elif i > 0:
            p.append(i)
        else:
            n.append(i)
    
    print(len(p)/len(arr))
    print(len(n)/len(arr))
    print(len(z)/len(arr))

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
