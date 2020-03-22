#include<stdio.h>
#include<math.h>
int main (){
    int i_10,i_8 = 0;
    scanf("%d",&i_10);
    for (int k = 7; k >= 0; k--) {
      i_8 =i_8 + i_10 / (int)pow(8,k) * (int)pow(10,k);
      i_10 = i_10 - i_10 / (int)pow(8,k) * (int)pow(8,k);
    }
    printf("%d",i_8);
    return 0;
}
