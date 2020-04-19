#include <math.h>
#include <stdio.h>

int iTarget = 0;
void dfs(double dArr[], int n)
{ // dfs search
  if (n == 1)
  { //stop when there is only 1 number left. see if it is 24 and return
    if (fabs(dArr[0] - 24) < 1e-4)
    {
      iTarget = 1; //if it is 24 there is a way to operate the numbers to 24. set the target to 1.
    }
    return; //if it is not 24 this is not a way to operate them to 24. move on to the next way.
  }
  //below are the operations.
  double dArr_2[4];
  for (int i = 0; i < n; i++)
  {
    for (int iJ = 0; iJ < n; iJ++)
    { // 2 dimension loop to pick out 2 of the numbers randomly.
      if (i == iJ)
      {
        continue;
      } // not picking the same number
      int iM = 0;
      for (int iK = 0; iK < n; iK++)
      {
        if (iK != i && iK != iJ)
        {
          dArr_2[iM] = dArr[iK];
          iM++;
        } //copy the 2 numbers
      }
      dArr_2[iM] = dArr[i] + dArr[iJ];
      dfs(dArr_2, iM + 1); //dfs search the numbers left(iM) plus 1 which is plused , multiplied or divised (1).
      dArr_2[iM] = dArr[i] - dArr[iJ];
      dfs(dArr_2, iM + 1);
      dArr_2[iM] = dArr[i] * dArr[iJ];
      dfs(dArr_2, iM + 1);
      if (fabs(dArr[iJ]) < 1e-4)
      { //fabs command in this program is used to judge whether it is zero.
        continue;
      }
      dArr_2[iM] = dArr[i] / dArr[iJ];
      dfs(dArr_2, iM + 1);
    }
  }
}
int main()
{
  double dArr[4];
  while (scanf("%lf %lf %lf %lf", &dArr[0], &dArr[1], &dArr[2], &dArr[3]) != EOF)
  {              // input using EOF
    iTarget = 0; //set the target to 0
    if (dArr[0] != 0 && dArr[1] != 0 && dArr[2] != 0 && dArr[3] != 0)
    {
      dfs(dArr, 4);
    }
    else
    {
      break;
    }
    if (iTarget == 1)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}