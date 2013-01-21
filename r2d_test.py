#!/usr/bin/python
from r2d import r2d
import unittest

class TestR2D(unittest.TestCase):
  def test_basic(self):
    self.assertEquals('0.(3)', r2d(1,3))
    self.assertEquals('0.(142857)', r2d(1,7))
    self.assertEquals('6.(307692)', r2d(82,13))

if __name__ == '__main__':
  unittest.main()
