#include <stdio.h>
int main(){
    int i = 2;
    int a;
    a = (++i) + (++i);
    printf("%d", a);
    return 0;
}