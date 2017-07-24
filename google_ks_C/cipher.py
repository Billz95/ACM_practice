def cipher(word):
    res = []
    for i in range(len(word)):
        if i == 0:
            res.append(word[1])
        elif i == len(word) - 1:
            res.append(word[len(word) - 2])
        else:
            res.append((word[i-1] + word[i+1]) % 26)

    return tuple(res)


def toLetter(x):
    return chr(ord('A') + x)


def toNum(x):
    return ord(x) - ord('A')

def dictAppend(inputDict, key , value):
    if inputDict.get(key, 0) != 0:
        inputDict[key].append(value)
    else:
        inputDict[key] = [value]

def toNums(word):
    res = []
    for letter in word:
        res.append(toNum(letter))
    return tuple(res)

def toWord(letters):
    res = []
    for letter in letters:
        res.append(toLetter(letter))
    return ''.join(res)

def smallSet():
    revDict = {}
    for x0 in range(26):
        for x1 in range(26):
            revDict[(x0, x1)] = [(x1, x0)]
            for x2 in range(26):
                dictAppend(revDict, cipher((x0,x1,x2)), (x0,x1,x2))
                for x3 in range(26):
                    dictAppend(revDict, cipher((x0,x1,x2,x3)), (x0,x1,x2,x3))

    # print("ready to take input")
    numQ = int(input())
    for i in range(numQ):
        encry = toNums(input())
        if len(revDict[encry]) > 1:
            print("Case #{}: AMBIGUOUS".format(i+1))
        else:
            print("Case #{}: {}".format(i+1, toWord(revDict[encry][0])))

def largeSetRec():
    numQ = int(input())
    for i in range(numQ):
        encry = input()
        encryNum = toNums(encry)
        res = recDe(encryNum)
        print("Case #{} {}".format(i, res))



smallSet()
