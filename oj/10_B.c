#include <stdio.h>
#include <string.h>
#define MAX 400000  // all of the possible routes 9! = 362880

int hash [MAX];  
char aim[10]="876543210";
char single_status [MAX][10]; // every single status. 9! in total

int cantor(char x[],int n)  // calculate the cantor function 
{
	int fac[]={1,1,2,6,24,120,720,5040,40320};  // values of factorial, from 0 to 8 (there is 9 numbers used in total) 
	int i,j,num=0,count; //num means X.
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=i+1;j<n;j++)
			if(x[j]<x[i]) count++;
		
		num+=count*fac[n-1-i];
	}
	return num + 1;
}

int bfs(int p, int q, int n){
    int i,j=q+1,t,num;
    char new_status[10]; // new status

    for(i=p;i<=q;i++){
        if(strcmp(single_status[i],aim)==0){
            printf("%d",n);
            return 0;
        }

        t=0;
        while(single_status[i][t]!='0'){
            t++;
        }
        if(t>2){ // 0 isn't in the first line
        strcpy(new_status,single_status[i]);
        new_status[t]=single_status[i][t-3];// down
        new_status[t-3]=single_status[i][t];
        num = cantor(new_status,9);
        if(hash[num]==1){
            strcpy(single_status[j],new_status);
            hash[num] = 0;
            j++;
        }
        }
        if(t<6){
        strcpy(new_status,single_status[i]);
        new_status[t]=single_status[i][t+3];// down
        new_status[t+3]=single_status[i][t];
        num = cantor(new_status,9);
        if(hash[num]==1){
            strcpy(single_status[j],new_status);
            hash[num] = 0;
            j++;
        }
        }
        if(t%3 != 0){
        strcpy(new_status,single_status[i]);
        new_status[t]=single_status[i][t-1];// down
        new_status[t-1]=single_status[i][t];
        num = cantor(new_status,9);
        if(hash[num]==1){
            strcpy(single_status[j],new_status);
            hash[num] = 0;
            j++;
        }
        }
        if(t%3 != 2){
        strcpy(new_status,single_status[i]);
        new_status[t]=single_status[i][t+1];// down
        new_status[t+1]=single_status[i][t];
        num = cantor(new_status,9);
        if (hash[num] == 1) {
          strcpy(single_status[j], new_status);
          hash[num] = 0;
          j++;
        }
        }
        
    }
    bfs(q + 1, j - 1, n + 1);
    return 0;
}
int main(){
    int i,trans;
    for(i = 0;i<9;i++){
        scanf("%d",&trans);
        single_status[0][i]=trans+'0';
    }
    single_status[0][9]='\0';
    for(i = 0;i<MAX;i++){
        hash[i]=1;
    }
    hash[cantor(single_status[0],9)]=0;
    bfs(0,0,0);
    return 0;
}