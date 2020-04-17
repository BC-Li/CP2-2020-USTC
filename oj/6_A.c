#include <stdio.h>
#include <string.h>
#include <math.h>
void scan(int M ,int N,int *arrpoint[],int* max_x,int* max_y){
    for (int i = 0; i < M;i++){
        for (int j = 0; j < N;j++){
             if(arrpoint[i][j]>arrpoint[i][max_y[i]]){
                 max_y[i] = j ;
             }
        }
    }
       *max_x = 0;
    for (int i = 0; i < M;i++){
        
        if(arrpoint[i][max_y[i]]>arrpoint[*max_x][max_y[*max_x]]){
            *max_x = i;
        }
    }
}
int main(){
    int M, N, K,totaltime = 0,peanutmax = 0;
    scanf("%d %d %d", &M, &N, &K);
    int arr[M][N];
    int *arrpoint[M];
    int max_x, max_y[M];
    int x_memory = 0, y_memory = 0;
    for (int i = 0; i < M;i++){
        arrpoint[i] = arr[i];
    }
    memset(max_y, 0, sizeof(max_y));
    for (int i = 0; i < M;i++){
        for (int j = 0; j < N;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    totaltime = totaltime + 1;
    scan(M, N, arrpoint, &max_x, max_y);
    if(totaltime+max_x+1+max_x+1>K){
        printf("0");
        return 0;
    }
    y_memory = max_y[max_x];
    while (totaltime <= K){
    scan(M, N, arrpoint, &max_x, max_y);
    if(totaltime+abs(max_x-x_memory) + abs(max_y[max_x]-y_memory) +1+ max_x + 1 >K){
        break;
    }
    totaltime = totaltime + abs(max_x-x_memory) + abs(max_y[max_x]-y_memory) + 1;
    peanutmax = peanutmax + arr[max_x][max_y[max_x]];
    arr[max_x][max_y[max_x]] = 0;
    x_memory = max_x;
    y_memory = max_y[max_x];
    }
    printf("%d", peanutmax);
    return 0;
}