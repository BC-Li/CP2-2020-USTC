#include <math.h>
#include <stdio.h>

int target = 0;
void dfs(double arr[], int n) {
  if (n == 1) {
    if (fabs(arr[0] - 24) < 1e-4) {
      target = 1;
    }
    return;
  }
  double arr_2[4];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int m = 0;
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          arr_2[m] = arr[k];
          m++;
        }
    }
        arr_2[m] = arr[i] + arr[j];
        dfs(arr_2, m + 1);
        arr_2[m] = arr[i] - arr[j];
        dfs(arr_2, m + 1);
        arr_2[m] = arr[i] * arr[j];
        dfs(arr_2, m + 1);
        if (fabs(arr[j]) < 1e-4) {
          continue;
        }
        arr_2[m] = arr[i] / arr[j];
        dfs(arr_2, m + 1);
      }
  }
}
int main() {
  double arr[4];
  while (scanf("%lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3]) != EOF) {
    target = 0;
    if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0) {
      dfs(arr, 4);
    } else {
      break;
    }
    if (target == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}