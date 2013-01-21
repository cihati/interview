/*
 * Given two sorted arrays, an integer k, find the kth smallest integer
 * in the union of two arrays.
 * TAGS: binary search, logarithmic, tricky, coding
 */
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

int kthSmallest(int a[], int n, int b[], int m, int k) {
  assert(n + m >= k);
  int l = 0, r = min(n - 1, k - 1);
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int ll = 0, rr = m - 1;
    while (ll <= rr) {
      int mm = ll + (rr - ll) / 2;
      if (a[mid])
    }
  }
}

int main() {

  return 0;
}

