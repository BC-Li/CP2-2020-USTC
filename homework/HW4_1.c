//分解因数
#include <stdio.h>
int count(int iX, int iY) {
  if (iX == 1) {
    return 1;
  }//如果除到1了就停止，同时计数器+1
  if (iY == 1) {
    return 0;//如果除数到了1仍然无法整除说明无法分解
  }
  if (iX % iY == 0) {
    return count(iX / iY, iY) + count(iX, iY - 1);//如果能整除就加上（x/iY,iY)的结果（继续分解）和y-1的结果（下一种分解方式）
  } else {
     return count(iX, iY - 1);//不能整除就换下一个.
  }
}
int main() {
  int iX;
  scanf("%d", &iX);
  printf("%d", count(iX, iX));
  return 0;
}