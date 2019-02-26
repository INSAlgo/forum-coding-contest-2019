#!/usr/bin/env python3

from heapq import heappop, heappush


def main():
    # Lecture de l'input
    n, m = map(int, input().split())
    danger = list(map(int, input().split()))
    l, c = map(int, input().split())
    tower = [[list(map(int, input().split()))
              for _ in range(m)]
             for _ in range(n)]

    # Algorithme de Dijkstra
    hq = [(0, l, c, 0)]
    dst = {(l, c, 0): 0}
    while hq:
        di, li, ci, hi = heappop(hq)
        if hi == n:
            print(di)
            return
        elif dst[(li, ci, hi)] == di:
            for lj, cj, hj in neighbors(li, ci, hi, tower, m, n, dst):
                dj = di + danger[hi]
                if (lj, cj, hj) not in dst or dst[(lj, cj, hj)] > dj:
                    dst[(lj, cj, hj)] = dj
                    heappush(hq, (dj, lj, cj, hj))

    print(-1)  # Pas de solution
    return


def neighbors(li, ci, hi, tower, m, n, dst):
    """Retourne les voisins valides de cette position dans la tour"""
    offsets = [(-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0)]
    if tower[hi][li][ci] == 2:
        offsets.append((0, 0, 1))
    elif tower[hi][li][ci] == 3:
        offsets.append((0, 0, -1))
    for ol, oc, oh in offsets:
        lj, cj, hj = li + ol, ci + oc, hi + oh
        if hj >= 0 and lj >= 0 and cj >= 0 and lj < m and cj < m \
           and (hj == n or tower[hj][lj][cj] != 1 and (lj, cj, hj) not in dst):
            yield (lj, cj, hj)


main()
