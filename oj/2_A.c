#include <stdio.h>
int main(){
    int i,f[100]={0,1},f_recorder = 2;
    while(scanf("%d",&i)!=EOF){
        if(i==0){
            printf("The Fibonacci number for 0 is 0\n");
        }
        else if(i==1){
            printf("The Fibonacci number for 1 is 1\n");
        }
        else if(i==2){
            printf("The Fibonacci number for 2 is 1\n");
        }
        else {
            for (; f_recorder != i+1;f_recorder++){
                f[f_recorder] = f[f_recorder - 1] + f[f_recorder - 2];
            }
             printf("The Fibonacci number for %d is %d\n",i,f[f_recorder-1]);
        }
       
        f_recorder = 2;
    }
    return 0;
}