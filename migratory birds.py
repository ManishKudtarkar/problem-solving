def migratoryBirds(arr):
    theCounter = [0, 0, 0, 0, 0] 
    for i in arr:
        theCounter[i - 1] += 1

    max_count = max(theCounter)
    return theCounter.index(max_count) + 1
