#include <cstdio>
using namespace std;

void removeDups(char *str) {
  if (str == NULL || !str[0]) return;
  for (int i = 1, next = 1; str[i]; ++i) {
    if (str[i] != str[i - 1]) {
      str[next++] = str[i];
    }
  }
  str[next] = '\0';
}

int main() {

  return 0;
}

