#!/usr/bin/python

def div1(dividend, divisor):
    if divisor > dividend:
        return (0, num)
    if divisor == dividend:
        return (1, 0)
    res = 0
    i = 0
    while (dividend >= (divisor << i)):
        i += 1
    i -= 1
    while i >= 0:
        if dividend >= (divisor << i):
            res += 1 << i
            dividend -= divisor << i
        i -= 1
    return (res, dividend)

if __name__ == '__main__':
    pass

