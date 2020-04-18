#include <stdio.h>
void Hanoi(int n,char a,char b,char c){
    if(n == 1){
        printf("%c -> %c\n",a,b);
        return;
    }//下面都是前一步的操作，即：n不等于1的时候先做上一步的操作
    Hanoi(n-1,a,c,b);//那么，前一步也就是f(n - 1, other variables)
    printf("%c -> %c\n",a,b);//显然是先将n -1 个在A柱子上的盘子通过C柱移动到B柱上，
    Hanoi(n-1,c,b,a);//再将在A柱子上的编号为n的盘子移动到C柱上，再将B柱子上的n-1个盘子通过A柱移动到C柱上
}
int main(){
    int n;
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
    return 0;
}