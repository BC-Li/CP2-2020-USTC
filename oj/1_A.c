#include<stdio.h>
int main(){
    int a1, a2;
   while (scanf("%d %d", &a1, &a2) != EOF){
        printf("%d\n", a1 + a2);
   } 
    return 0;
}