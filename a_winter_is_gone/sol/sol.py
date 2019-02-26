n = int(input())
best_dst = 99999999999999999999
best_arrow = 1
for i in range(1, n+1):
    x, y = map(float, input().split())
    if x*x + y*y < best_dst:
        best_dst = x*x + y*y
        best_arrow = i

print(best_arrow)