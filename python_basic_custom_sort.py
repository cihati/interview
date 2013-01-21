#!/usr/bin/python

if __name__ == '__main__':
  s = ['hasan', 'abc', 'xx', 'bbb', 'z']
  # print sorted(s, cmp=lambda x, y: x < y if len(x) == len(y) else len(x) <
  #    len(y))
  print sorted(s, key=lambda x: (len(x), x))

