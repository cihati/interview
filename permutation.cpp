#include <cstdio>
#include <cassert>
using namespace std;

void swp(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void perm(int arr[], int n, int pos) {
  if (pos == n - 1) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = pos; i < n; ++i) {
    swp(arr[pos], arr[i]);
    perm(arr, n, pos + 1);
    swp(arr[pos], arr[i]);
  }
}

int main() {
  int arr[] = {1,2,3,4,5};
  perm(arr, 5, 0);
  return 0;
}

