
#include <stdio.h>
#include <math.h>
#define N 20
 
int x[N];          // x[i] means in line i, the queen is placed on i place.
int n;             // the numbers of queens (totally)
int sum=0;         // numbers of solutions
 
int place(int k)
{
	int i;
	for(i=1;i<k;i++)
       if(abs(k-i)==abs(x[k]-x[i])||x[k]==x[i])
		   return 0;
	   return 1;
}
int queen(int k) // numbers of the solutions
{
	int i;
	if(k>n)
		sum++;
	else
	   for(i=1;i<=n;i++)
	   {
		   x[k]=i;
		   if(place(k))    // if x[k] makes no conflicts with the former ones
			   queen(k+1); // then place the next line
	   }
	   return sum;
}
int main()
{
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", queen(1));
    sum = 0;
  }
        return 0;
}