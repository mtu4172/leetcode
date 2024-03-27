# Link : https://usaco.org/index.php?page=viewproblem2&cpid=1350#

import sys

N, M, K = map(int, sys.stdin.readline().split())

weightcount = {}
weight = []
for i in range(N):
    w, c = map(int, sys.stdin.readline().split())
    weight.append(w)
    weightcount[w] = c

weight = sorted(weight)

cows = 0
stacks = [0] * M

while len(weight) > 0:
    for i, e in enumerate(stacks):
        while True:
            if len(weight) == 0:
                break
            if weight[-1] <= e - K or e == 0:
                stacks[i] = weight[-1]
                weightcount[weight[-1]] -= 1
                cows += 1
                if weightcount[weight[-1]] == 0:
                    weight.pop()
                break
            weight.pop()

print(cows)