//分解因数
#include <stdio.h>
int count(int x, int y) {
  if (x == 1) {
    return 1;
  }
  if (y == 1) {
    return 0;
  }
  if (x % y == 0) {
    return count(x / y, y) + count(x, y - 1);
  } else {
     return count(x, y - 1);
  }
}
int main() {
  int x;
  scanf("%d", &x);
  printf("%d", count(x, x));
  return 0;
}