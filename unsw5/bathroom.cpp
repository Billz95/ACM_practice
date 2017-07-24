/*
  do until y >= k
      x = max in S
      a = floor((x-1)/2), y = ceil
      delete x
      insert a, b
      c[a] += c[x]
      c[b] += c[x]
      y += c
 */
