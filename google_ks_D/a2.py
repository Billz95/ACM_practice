import math
def modTime(time, start, freq):
   if time < 0:
       # print("mod time time {} start {} freq {} ".format(time, start, freq))
       return -1
   if time < start:
      return -1
   multiple = (time - start) / freq

   if not multiple.is_integer():
       multiple = math.floor(multiple) - 1
   else:
       multiple = int(multiple)


   final = multiple * freq + start
   #debug
   # print("mod time time {} start {} freq {} final {}".format(time, start, freq, final))
   return final


# Main Program

t = int(input())

for i in range(t):
    firLine = input().split()
    nCity = int(firLine[0])
    Ts = int(firLine[1])
    Tf = int(firLine[2])

    #debug
    # print(firLine, nCity, Ts, Tf)

    # create 2d array Opt
    Opt = [[-1 for k in range(Tf + 1)] for j in range(nCity + 2)]
    Opt[0][0] = 0

    # read bus infomations, in the order of
    # start time,
    # freq,
    # Duration

    bus = [0]
    for k in range(nCity - 1):
        line = input().split()
        for j in range(len(line)):
            line[j] = int(line[j])

        bus.append(line)
    # print(bus)
    # print("Opt") 
    # for item in Opt:
    #     print(item)

    # fix row
    for k in range(1, Tf + 1):
       Opt[1][k] = 1 if k >= Ts else 0

    for city in range(2, nCity + 1):
       for time in range(Tf + 1):
          # print(city, time)
          time1 = modTime(time - Ts - bus[city-1][2], bus[city-1][0], bus[city-1][1])
          time2 = modTime(time - bus[city-1][2], bus[city-1][0], bus[city-1][1])
          out1 = -999 if time1 < 0 or Opt[city-1][time1] < 0 or city == nCity else (Opt[city-1][time1] + 1)
          out2 = -999 if time2 < 0 else Opt[city-1][time2]
          out3 = -999 if time-1 < 0 else Opt[city][time-1]
          Opt[city][time] = max(out1, out2, out3)
          # print(out1, out2, out3)


    # for item in Opt:
    #    print(item)
    if Opt[city][time] == -999:
       print("Case #{}:".format(i+1), "IMPOSSIBLE")
    else:
       print("Case #{}:".format(i+1), max(Opt[nCity]))
    del(Opt)
