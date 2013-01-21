/*
 * An example rotated sorted array: 6, 7, 8, 1, 2 3
 * TAGS: binary search, rotate, logarithmic
 */
#include <cstdio>
#include <cassert>
using namespace std;

int f(int arr[], int el, int l, int r) {

}

int main() {
  int arr1[] = {7, 8, 9, 1, 2, 4, 6};
  printf("%d\n", 2 == f(arr1, 9, 0, 6));
  printf("%d\n", 4 == f(arr1, 2, 0, 6));
  printf("%d\n", -1 == f(arr1, 3, 0, 6));
  int arr2[] = {1, 2, 4, 6, 8, 9};
  printf("%d\n", 0 == f(arr2, 1, 0, 5));
  printf("%d\n", -1 == f(arr2, 0, 0, 5));
  printf("%d\n", 3 == f(arr2, 6, 0, 5));
  printf("%d\n", -1 == f(arr2, 10, 0, 5));
  return 0;
}

