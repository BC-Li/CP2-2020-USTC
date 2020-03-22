#include <stdio.h>
int func(int n);
void swap(int *i, int *j, int *flag);
void done(int i, int j, int flag);
int main(){
    int i, j,flag = 0;
    while(scanf("%d %d",&i,&j)!=EOF){
        swap(&i, &j,&flag);
        done(i, j,flag);
    }
}
void done(int i,int j,int flag){
    int k;
    int max = 0;
    int sum;
    for (k = i;k <= j;k++)
    {
        sum = func(k);
        if (sum > max) max = sum;
    }
    if (flag)
    printf("%d %d %d\n", j, i, max);
    else printf("%d %d %d\n", i, j, max);
}
void swap (int* i,int* j,int *flag){
    int nn = 0;
    if(*i>*j){
        nn = *i;
        *i = *j;
        *j = nn;
        *flag = 1;
    }
}
int func(int n){
     int s = 0;
    while(1 != n)
    {
        if (0 == n%2) n = n/2;
        else n = n*3 + 1;
        s++;
    }
    return s+1;
}