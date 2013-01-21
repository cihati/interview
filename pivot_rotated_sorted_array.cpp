#include <cstdio>
using namespace std;

// Does not work with duplicates.
int f(int arr[], int n) {
  if (n < 3) return 0;
  int l = 0, r = n - 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] < arr[r]) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  int a1[] = {3, 4, 5, 1, 2};
  printf("%d\n", 3 == f(a1, 5));
  int a2[] = {1, 2, 3, 4, 5};
  printf("%d\n", 0 == f(a2, 5));
  int a3[] = {4, 5, 6, 7, 8, 9, 1};
  printf("%d\n", 6 == f(a3, 7));
  return 0;
}

