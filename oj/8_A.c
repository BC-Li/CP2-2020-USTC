#include <stdio.h>
int main(){
    int n,i,j,k,max=0;
    scanf("%d", &n);
    for ( i = 0; i <= n;i++){
        for ( j = 0; j <= n;j++){
            for ( k = 0; k <= n;k++){
                if((((i+j)%2)==0)&&(((j+k)%3)==0)&&(((i+j+k)%5)==0)){
                    if(max<i+k+j){
                        max = i+k+j;
                    }
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}