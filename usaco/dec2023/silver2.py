import sys
from collections import deque


def count_sim(d1, d2):
    count = 0
    for i in range(len(L1)):
        if d1[i] == d2[i]:
            count += 1
    return count


def rotate(d):
    temp = d[-1]
    d.pop()
    d.appendleft(temp)


N, K = map(int, sys.stdin.readline().split())
L1 = list(map(int, sys.stdin.readline().split()))
L2 = list(map(int, sys.stdin.readline().split()))

s = set(L1)
for i in L2:
    s.add(i)
not_cycle = N - len(s)

d1 = deque(L1)
d2 = deque(L2)

maxcount = 0
for i in range(len(d1)):
    c = count_sim(d1, d2)
    maxcount = max(maxcount, c)
    rotate(d2)

d1 = deque(reversed(L1))
for i in range(len(d1)):
    c = count_sim(d1, d2)
    maxcount = max(maxcount, c)
    rotate(d2)

print(not_cycle+maxcount)