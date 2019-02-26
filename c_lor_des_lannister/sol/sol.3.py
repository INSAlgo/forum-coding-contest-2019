#!/usr/bin/env python3

from collections import defaultdict


def main():
    n = int(input())
    numbers = list(map(int, input().split()))
    numbers.sort()
    best_len = 1
    seq_info = defaultdict(lambda: defaultdict(lambda: 1))

    for i in range(n):
        for j in range(i):
            inter = numbers[i] - numbers[j]
            if inter == 0:
                continue
            seq_info[i][inter] = seq_info[j][inter] + 1
            if seq_info[i][inter] > best_len:
                best_len = seq_info[i][inter]

    print(best_len)


main()
