import math
def modTime(time, start, freq):
   if time < 0:
       print("mod time time {} start {} freq {} ".format(time, start, freq))
       return 0
   multiple = (time - start) / freq

   if not multiple.is_integer():
       multiple = math.floor(multiple) + 1
   else:
       multiple = int(multiple)


   final = multiple * freq + start
   #debug
   print("mod time time {} start {} freq {} final {}".format(time, start, freq, final))
   return final


def solve(Opt, city, time, bus):
    print("BUS TIME", bus[city-1], city ,"and time", time)
    if city < 0 or time < 0:
        return -1

    if Opt[city][time] != -1:
        return Opt[city][time]


    moda = modTime(time - bus[city - 1][2], bus[city-1][0], bus[city - 1][1])
    if moda < time:
        resa = solve(Opt, city-1, moda, bus) + 1
    elif moda < 0:
        print("less than zero not staying")
        moda = -1
    else:
        print("impossible")
        moda = -1

    modb = modTime(time - Ts - bus[city - 1][2], bus[city-1][0], bus[city - 1][1]),
    if modb < time:
        resb = solve(Opt, city-1, modb, bus)
    elif moda < 0:
        print("less than zero staying")
        modb = -1
    else:
        print("impossible")
        modb = -1

    resb = solve(Opt, city-1, modb, bus)
    Opt[city][time] = max(resa, resb)
    return Opt[city][time]



t = int(input())

for i in range(t):
    firLine = input().split()
    nCity = int(firLine[0])
    Ts = int(firLine[1])
    Tf = int(firLine[2])

    #debug
    print(firLine, nCity, Ts, Tf)

    # create 2d array Opt
    Opt = [[-1 for k in range(2 * Tf)] for j in range(nCity + 1)]
    minTime = [[-1 for k in range(nCity)] for j in range(nCity)]
    Opt[0][0] = 0
    minTime[0][0] = 0

    # read bus infomations, in the order of
    # start time,
    # freq,
    # Duration

    bus = []
    for k in range(nCity - 1):
        line = input().split()
        for j in range(len(line)):
            line[j] = int(line[j])

        bus.append(line)
    print(bus)
    print("Opt") 
    for item in Opt:
        print(item)

    res = solve(Opt, nCity - 1, Tf, bus)
    print("Case #", i, res)
