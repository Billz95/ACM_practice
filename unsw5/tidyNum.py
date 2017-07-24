import math

def nextTidy(mid):
    chNum = list(str(mid))

    # check if it is tidy first
    tidy = True
    pre = chNum[0]
    for i, ch in enumerate(chNum):
        if pre > ch:
            for j in range(i, len(chNum)):
                chNum[j] = pre
            tidy = False
            break
        pre = ch
    if not tidy:
        return int(''.join(chNum))
    else:
        return nextTidy(mid+1)


def bsearch(a, b):

    res = 0
    mid = math.ceil((a+b)/2)
    nxt = nextTidy(mid)
    while True:
        print("a:{} b:{} mid:{} nxt:{}".format(a,b,mid,nxt))
        if nxt > b:
            mid = math.ceil((a + mid)/2)
            nxt = nextTidy(mid)
            b = mid
        elif nxt < b:
            mid = math.ceil((mid + b)/2)
            nxt = nextTidy(mid)
            a = mid
        elif a == b:
            return nxt


numQ = int(input())

for qID in range(numQ):
    inNum = int(input())
    print(bsearch(0,inNum))


