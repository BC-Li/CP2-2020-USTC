#include<stdio.h>
#include<math.h>
int main(){
    long long int iA;
    long long int iM;
    scanf("%lld", &iA);
    for (iM = iA; ;iM--){
        if(((iA * iA + 1) % iM) == 0){
        printf("%lld", 2 * iA + iM + (iA * iA + 1) / iM);
        break;// ������ѧ����֮��ó�����
        }
    }
    return 0;
}