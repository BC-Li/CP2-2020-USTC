#include<stdio.h>
#include<string.h>
int main(){
    int g_iM, g_iL;
    int g_iStart, g_iEnd;
    int g_iCounter=0;
    scanf("%d %d", &g_iL, &g_iM);
    int g_aL_arr[g_iL+1];
    memset(g_aL_arr,-1, sizeof(g_aL_arr)); //turn all the marker(trees) to 1;
    for (int i = 0; i < g_iM;i++){//cut down the trees
        scanf("%d %d", &g_iStart, &g_iEnd);
        for (int k = g_iStart; k <= g_iEnd;k++){
            g_aL_arr[k] = 0;
        }
    }
    for (int i = 0; i <= g_iL;i++){// count the amount of trees
        if(g_aL_arr[i]==-1){
            g_iCounter++;
        }
    }
    printf("%d", g_iCounter);
    return 0;
}