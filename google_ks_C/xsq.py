t = int(input())
for i in range(t):
    n = int(input())
    graph = ['' for k in range(n)]

    totX = 0
    colX = [0 for k in range(n)]

    valid = "POSSIBLE"

    for k in range(n):
        graph[k] = input()
        curX = graph[k].count("X")
        if curX == 0 or curX > 2:
            valid = "IMPOSSIBLE"

        totX += curX
        if curX == 2:

            firX = graph[k].index("X")
            sndX = graph[k].index("X", firX)

            colX[firX] += 1
            colX[sndX] += 1

            if colX[firX] > 2 or colX[sndX] > 2:
                valid = "IMPOSSIBLE"

        elif curX == 1:
            firX = graph[k].index("X")

            colX[firX] += 1

            if colX[firX] > 2:
                valid = "IMPOSSIBLE"



    print("Case #{} {}".format(i, valid))


