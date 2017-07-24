#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import sys

n = input()
data = sys.stdin.readlines()
dict1= dict()
dict2= dict()
list1 = []
list2 = []

line = data[0].strip().split()
for num in line:
    list1.append(int(num))

line = data[1].strip().split()
for num in line:
    dict2[int(num)] = dict2.get(int(num), 0) + 1
    list2.append(int(num))


for num in list1:
    if dict2.get(num, 0) == 0:
        print(num)
    else:
        dict2[int(num)]-=1;

line = data[2].strip().split()
for num in line:
    dict1[int(num)] = dict1.get(int(num), 0) + 1

for num in list2:
    if dict1.get(num, 0) == 0:
        print(num)
    else:
        dict1[int(num)]-=1;

