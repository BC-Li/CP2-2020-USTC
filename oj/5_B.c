#include<stdio.h>
int main(){
    int arrMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int m1,d1,m2,d2,days;
    scanf("%d %d",&m1,&d1);
    scanf("%d %d",&m2,&d2);
    days=0;
    if(m2-m1){
        days=days+arrMonth[m1-1]-d1;
        for(int i = 0;i<m2-m1-1;i++){
            days=days+arrMonth[m1+i];
        }
        days=days+d2;
    }
    else{
        days=days+d2-d1;
    }
    printf("%d",days);
    return 0;
}