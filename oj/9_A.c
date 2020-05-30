#include <stdio.h>
#include <string.h>

char map[1001][1001];
int total = 0;
void search(int a,int  b){
    if(map[a][b]!='*'|| a<0 || b<0 || a>1000 || b>1000 ){
        return;
    }
    map[a][b]='.';
    search(a-1,b);
    search(a,b-1);
    search(a+1, b);      
    search(a,b+1);   
}

int main(){
    for(int i = 0;i<1001;i++){
        for(int j = 0;j<1001;j++){
            map[i][j]='.';
        }
    }
    int i = 0;
    while(scanf("%s",map[i])!=EOF){

        i++;
    }
    for(int i =0;i<1000;i++){
        for(int j = 0;j<1000;j++){
            if(map[i][j]=='*'){
                total++;
                search(i,j);
            }
        }
    }
    printf("%d",total);
    return 0;
}