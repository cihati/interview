#include <cstdio>
using namespace std;

int calc(char *s) {
  if (!*(s + 1))
    return *s - '0';
  int res = 0;
  int prev = *s++ - '0';
  while (*s) {
    char op = *s++;
    int n = *s++ - '0';
    if (op == '+') {
      res += prev;
      prev = n;
    } else {
      prev *= n;
    }
  }
  res += prev;
  return res;
}

int main() {
  char *s[] = {"5", "6*7", "3*6*2", "5+6+7", "2*3+4", "2+3*4+5"};
  for (int i = 0; i < 6; ++i)
    printf("%s %d\n", s[i], calc(s[i]));
  return 0;
}

