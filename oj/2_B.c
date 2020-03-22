#include<stdio.h>
int main(){
    int i, j=1;
    while(scanf("%d",&i)!=EOF){
        for (int k = 0; k < i;k++){
            j = j * 2;
        }
        printf("%d\n", j);
        j = 1;
    }
    return 0;
}