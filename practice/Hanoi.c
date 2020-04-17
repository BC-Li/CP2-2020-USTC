#include <stdio.h>
void Hanoi(int n,char a,char b,char c){
    if(n == 1){
        printf("%c -> %c\n",a,b);
        return;
    }
    Hanoi(n-1,a,c,b);
    printf("%c -> %c\n",a,b);
    Hanoi(n-1,c,b,a)
}
int main(){
    int n;
    scanf("%d",&n);;
    Hanoi(n,'A','B','C');
    return 0;
}