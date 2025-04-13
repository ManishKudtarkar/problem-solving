def formingMagicSquare(s):
    a_b = [
        [-3,-1],
        [-3,1],
        [-1,-3],
        [-1,3],
        [1,-3],
        [1,3],
        [3,-1],
        [3,1]
    ]
    costs =[]
    for a,b in a_b:
        ms = [
            [5-b, 5+(a+b), 5 -a],
            [5-(a-b), 5, 5+(a-b)],
            [5+a, 5-(a+b), 5+b]
        ]
        cost = 0
        for i in range(3):
            for k in range(3):
                cost+=abs(s[i][k]-ms[i][k])
        
        costs.append(cost)
    return min(costs)
