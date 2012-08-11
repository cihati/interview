#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

void swp(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}

void f(int arr[], int n) {
  int a = 0, b = 0, c = n - 1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 3 && i < c) {
      swp(arr[c], arr[i]);
      --i; --c;
    } else if (arr[i] == 1) {
      swp(arr[i], arr[a]);
      a++; ++b;
    } else {
      b++;
    }
  }
}

void print(int a[], int n) {
  for (int i = 0; i < n; ++i)
    printf ("%d ", a[i]);
  printf("\n");
}

void test1() {
  int a[] = {1, 2, 3};
  int n = 3;
  f(a, n);
  print(a, n);
}

void test2() {
  int a[] = {3, 2, 1};
  int n = 3;
  f(a, n);
  print(a, n);
}

void test3() {
  int a[] = {1, 3, 2, 3, 1, 2, 2, 2, 3, 1};
  int n = 10;
  f(a, n);
  print(a, n);
}

void test4() {
  int a[] = {2, 2, 2, 2, 1, 3, 1, 2};
  int n = 8;
  f(a, n);
  print(a, n);
}

void test5() {
  int a[] = {2, 2, 2, 2};
  int n = 4;
  f(a, n);
  print(a, n);
}

void test6() {
  int a[] = {1, 1, 1, 3, 3, 3, 2, 2};
  int n = 8;
  f(a, n);
  print(a, n);
}

void test7() {
  int a[] = {1, 1, 1, 1, 1};
  int n = 5;
  f(a, n);
  print(a, n);
}

void test8() {
  int a[] = {3, 2, 1, 1, 2, 3, 2, 3, 1};
  int n = 9;
  f(a, n);
  print(a, n);
}

void test9() {
  int a[] = {2, 1, 1, 1, 3, 3, 3, 3, 2};
  int n = 9;
  f(a, n);
  print(a, n);
}
int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  return 0;
}

