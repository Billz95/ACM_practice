#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def cal_ee(nums):
    init = int(nums[0])
    target  = int(nums[1])
    var = int(nums[2])
    t = int(nums[3])
    print("init {}, target {}, var {}, t {}".format(init, target, var, t))

    lower = target - var
    upper = target + var


    if init <= lower or init > upper:
        print("not possible")
        return

    period = 4 * var

    n_p = int( t / period )
    remain = t % period;

    if (init - lower) > remain:
        cal_ee([ target - var + 1, target, var, t - (init - (target - var + 1))])
        return

    period_e = 20 * var + 5
    len_on = int ((remain - (init - lower)) / 2)

    rest_e = len_on * 10 + 5;
    print("remain = {}, n_p {}, len_on {}, rest_e {}, period_e {}".format(remain, n_p, len_on, rest_e, period_e))

    #  if n_p == 0 and remain <= 2:
        #  fix = 5
    #  elif remain <= 2 or n_p == 0:
        #  fix = 5
    #  else:
        #  fix = 0

    tot_e = n_p * period_e + rest_e
    print(tot_e)





def main():
    fh = open("eeinput.in", 'r')
    for line in fh:
        nums = line.strip().split(',')
        cal_ee(nums)



if __name__  == "__main__":
    main()


