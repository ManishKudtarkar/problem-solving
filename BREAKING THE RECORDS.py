#!/bin/python3

import math
import os
import random
import re
import sys

def breakingRecords(scores):
    min_point,max_point=scores[0],scores[0]
    num_broken_records=[0,0]
    rest_scores=scores[1:]
    
    for i in rest_scores:
        if i > max_point:
            num_broken_records[0]+=1
            max_point=i
        elif i < min_point:
            num_broken_records[1]+=1
            min_point=i
            
    return (num_broken_records[0],num_broken_records[1])
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
