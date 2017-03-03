#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():

    # get input
    num = []
    while True:
        try:
            line = input()

            for x in line.split():
                num.append(int(x))
        except:
            break

    # init set
    n = num[0]
    m = num[1]
    n_avail = [n * n]
    v_col = set()
    v_row = set()

    i = 2
    while i <= 2 * m:
        col = num[i]
        row = num[i + 1]
        safe = n_avail[-1]

        if (col in v_col) and (row in v_row):
            #  print('1')
            n_avail.append(safe)
        elif col in v_col:
            #  print('2')
            #  print('len vrow', len(v_row))
            n_avail.append(safe - (n - len(v_col)))
        elif row in v_row:
            #  print('3')
            #  print('len vcol', len(v_col))
            n_avail.append(safe - (n - len(v_row)))
        else:
            #  print('4')
            n_avail.append(safe - (2 * n - len(v_row) -len(v_col) - 1))

        v_col.add(col)
        v_row.add(row)
        i += 2

    for val in n_avail[1:]:
        print(val, end=' ')


if __name__ == '__main__':
    main()
