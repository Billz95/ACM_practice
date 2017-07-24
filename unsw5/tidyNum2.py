import math

def nextTidy(mid):
    chNum = list(str(mid))

    # tidy = True
    pre = chNum[0]
    for i, ch in enumerate(chNum):
        if pre > ch:
            for j in range(i, len(chNum)):
                chNum[j] = pre
            # tidy = False
            break
        pre = ch
    # if not tidy:
    return int(''.join(chNum))
    # else:
    #     return nextTidy(mid+1)


def bsearch(a, b):

    res = 0
    prev = a
    while a != b:
        mid = math.ceil((a+b)/2)
        nxt = nextTidy(mid)
        print("a:{} b:{} mid:{} nxt:{}".format(a,b,mid,nxt))

        if nxt > b:
            prev = b
            b = mid-1
        else:
            prev = a
            a = nxt

    return b;

numQ = int(input())

for qID in range(numQ):
    inNum = int(input())
    print(bsearch(0,inNum))


