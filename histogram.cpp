/*
 * TAGS: linear scan, stack
 */
// Given a histogram, assume that infinite amount of rain flows on.
// What is the amount of water that remains within histogram?
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int,int> pii;

int findVolume(int arr[], int n) {
  stack<pii> s;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a = arr[i];
    if (s.empty() || s.top().first > a) {
      s.push(pii(a, i));
    }
    else {
      if (s.top().first == a || s.size() == 1) {
        s.pop();
        s.push(pii(a, i));
      } else {
        int rmost = -1;
        while (s.size() != 1 && a > s.top().first) {
          pii p = s.top();
          rmost = max(p.second, rmost);
          s.pop();
          int w =-s.top().second + rmost;
          int h =  (min(a, s.top().first) - p.first);
          res +=  w * h;
        }
        if (s.size() == 1 && a > s.top().first) s.pop();
        s.push(pii(a, i));
      }
    }
  }
  return res;
}

int findVolume2(int arr[], int n) {
  int *ltrMax = new int[n]; // Left to right running sum.
  int *rtlMax = new int[n]; // Right to left running sum.

  ltrMax[0] = arr[0];
  rtlMax[n - 1] = arr[n - 1];
  for (int i = 1; i < n; ++i) {
    ltrMax[i] = max(ltrMax[i - 1], arr[i]);
  }
  for (int i = n - 2; i >= 0; --i) {
    rtlMax[i] = max(rtlMax[i + 1], arr[i]);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += min(ltrMax[i], rtlMax[i]) - arr[i];
  }
  return res;
}

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void test(int arr[], int n) {
  printf("stack:%d running sum:%d\n", findVolume(arr, n),
      findVolume2(arr, n));
}

int main() {
  // Unfortunately, C/C++ does not have array of arrays of unknown size,
  // hence the ugly testing code below.
  int arr1[] = {4, 7, 7, 8, 2, 9, 5, 6, 8, 9, 7, 4, 3, 2, 5, 6};
  int arr2[] = {4, 3, 2, 1, 2, 3, 4};
  int arr3[] = {1, 2, 3, 4, 3, 2, 1};
  int arr4[] = {10, 9, 9, 9, 11};
  test(arr1, SIZE(arr1));
  test(arr2, SIZE(arr2));
  test(arr3, SIZE(arr3));
  test(arr4, SIZE(arr4));
  return 0;
}

