#include <stdio.h>
int main(){
    int i;
    scanf("%d",&i);
    if(((i%100!=0)&&(i%4==0))||((i%100==0)&&(i%400==0))){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}