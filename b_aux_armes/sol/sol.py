#!/usr/bin/env python3

S, L, N = map(int, input().split())

V = []
if N > 0:
    V = list(map(int, input().split()))
    V = sorted(V, reverse=True)

if S > L:
    print(0)
else:
    C = 0
    for Vn in V:
        C += 1
        S += Vn
        if S > L:
            print(C)
            break
    if S <= L:
        print(-1)
