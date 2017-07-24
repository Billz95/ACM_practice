#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def main():
    fh = open("ice.in", 'r')
    for line in fh:
        nums = line.strip().split()
        ices = []
        ices.clear()
        for i, ice in enumerate(nums):
            ices.append(int(ice))

        #  print("in")
        #  for ice in ices:
            #  print(ice, end=' ')
        #  print("done")

        hi = 0
        lo = len(nums) - 1
        max_area = 0
        max_lo = lo
        max_hi = hi

        highest = max(ices)
        for i in range(1, highest + 1):
            hi = 0
            lo = len(ices) - 1
            for j, ice in enumerate (ices):
                if ice >= i and j < lo:
                    lo = j
                if ice >= i and j > hi:
                    hi = j
                if (hi > lo):
                    if (hi - lo) * i > max_area:
                        max_height = i
                        max_area = (hi - lo) * i
                        max_hi = hi
                        max_lo = lo

        print(max_area, max_lo, max_hi)



if __name__  == "__main__":
    main()


