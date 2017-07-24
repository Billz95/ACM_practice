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

    first_section = init - lower
    if t <= first_section:
        print(0)
        return

    if init <= lower or init > upper:
        print("not possible")
        return

    rest_section = t - first_section
    period = 4 * var

    n_p = int( rest_section / period )
    last_few = t % period;
#
    #  if (init - lower) > remain:
        #  cal_ee([ target - var + 1, target, var, t - (init - (target - var + 1))])
        #  return

    period_e = 20 * var + 5
    if last_few == 1:
        last_e = 5
    else:
        last_e = int ((last_few + 1) / 2) * 10 + 5

    #  if n_p == 0 and remain <= 2:
        #  fix = 5
    #  elif remain <= 2 or n_p == 0:
        #  fix = 5
    #  else:
        #  fix = 0

    tot_e = n_p * period_e + last_e
    print(tot_e)





def main():
    fh = open("eeinput.in", 'r')
    for line in fh:
        nums = line.strip().split(',')
        cal_ee(nums)



if __name__  == "__main__":
    main()


