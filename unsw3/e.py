#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys


def main():
    # read N, M, Q
    nmq = input()
    numTown, numRoads, numQuery = map(lambda x: int(x),list(nmq.split()))
    print(numTown,numRoads, numQuery)

    towns = []
    regions = []
    popin = input().split()
    for i,pop in enumerate(popin):
        #  print("pop", pop)
        towns.append(int(pop))
        regions.append(i)



    data = sys.stdin.readlines()
    query = []
    for raw in data:
        line = raw.strip()
        query.append(line)





if __name__ == "__main__":
        main()
