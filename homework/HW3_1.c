#include<stdio.h>
#include<string.h>
int main(){
    int iN;
    int iMax = 1;
    int iArray[100000];               //用高精度数处理2的N次方
    memset(iArray, 0, sizeof(iArray));//把数组全设为0
    iArray[0] = 1;
    scanf("%d", &iN);
    if(iN==0){
        printf("0");
        return 0;
    }                                 //排除0的情况
    for (int i = 0; i < iN;i++){      //乘2
        for (int j = 0; j != iMax;j++){
            iArray[j] = iArray[j] * 2;
        }                            //小于等于iMax位乘2
        for (int k = 0; k != iMax;k++){//遍历进位
            if(iArray[k] > 9){
                iArray[k + 1] = iArray[k + 1] + 1;
                iArray[k] = iArray[k] - 10;
                if(k==iMax-1){
                iMax = iMax + 1;     //只有当遍历到最后一位时才考虑进位时最高位数加1
                }
            }
        }
    }
    for (int i = iMax - 1; i >= 0;i--){
        printf("%d", iArray[i]);    //倒序输出
    }
    return 0;

}