#include <cstdio>
#include <vector>
using namespace std;

void swp(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void comb_(int arr[], int n, int k, vector<bool>& used, int pos) {
  if (k == 0) {
    for (int i = 0; i < n; ++i)
      if (used[i])
        printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  used[pos] = true;
  comb_(arr, n, k - 1, used, pos + 1);
  used[pos] = false;
  if (pos + 1 + k > n)
    return;
  comb_(arr, n, k, used, pos + 1);
}

void comb(int arr[], int n, int k) {
  vector<bool> v(n, false);
  comb_(arr, n, k, v, 0);
}

int main() {
  int arr[] = {1,2,3,4,5};
  comb(arr, 5, 3);
  return 0;
}

