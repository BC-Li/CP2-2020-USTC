#include <stdio.h>
#include <string.h>
int main(){
    int i = 0,j = 0;   
    char cs[100001], ct[100001];
    scanf("%s", cs);
    scanf("%s", ct);
    while(i<strlen(cs)&&j<strlen(ct)){
        if(cs[i]==ct[j]){
            i++;
        }
        j++;
    }
    if(i>=strlen(cs)){
        printf("Yes\n");
    }
    else{
        printf("No.");
    }
    return 0;
}