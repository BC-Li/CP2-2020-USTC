//�ֽ�����
#include <stdio.h>
int count(int iX, int iY) {
  if (iX == 1) {
    return 1;
  }//�������1�˾�ֹͣ��ͬʱ������+1
  if (iY == 1) {
    return 0;//�����������1��Ȼ�޷�����˵���޷��ֽ�
  }
  if (iX % iY == 0) {
    return count(iX / iY, iY) + count(iX, iY - 1);//����������ͼ��ϣ�x/iY,iY)�Ľ���������ֽ⣩��y-1�Ľ������һ�ַֽⷽʽ��
  } else {
     return count(iX, iY - 1);//���������ͻ���һ��.
  }
}
int main() {
  int iX;
  scanf("%d", &iX);
  printf("%d", count(iX, iX));
  return 0;
}