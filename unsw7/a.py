tmp = input().split()
n = int(tmp[0])
m = int(tmp[1])

puzzles = sorted(map(int, input().split()))
mindiff = puzzles[m - n] - puzzles[0];

for i in range(m - n):
    diff = puzzles[i+n-1] - puzzles[i]
    if diff < mindiff:
        mindiff = diff

print(mindiff)
