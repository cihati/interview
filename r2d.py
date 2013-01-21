#!/usr/bin/python

def r2d(num, denum):
  integer = num // denum
  num = 10 * (num % denum)
  states = {}
  sofar = []
  pos = 0
  res = '%d.' % integer
  while True:
    div = num // denum
    q = num % denum
    if (div,q) in states:
      nonrepeat = states[(div,q)]
      for i in range(nonrepeat):
        res += '%d' % sofar[i]
      res += '('
      for i in range(nonrepeat, pos):
        res += '%d' % sofar[i]
      res += ')'
      break
    states[(div,q)] = pos
    sofar.append(div)
    num = 10 * q
    pos += 1
  return res


if __name__ == '__main__':
  pass

