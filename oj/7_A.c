#include <stdio.h>
#include <string.h>

int main()
{
    char arr_1[110];
    char arr_2[110];
    int arr_answer[210];
    int n_1[110];
    int n_2[110];
    memset(n_1, 0, sizeof(n_1));
    memset(n_2, 0, sizeof(n_2));
    memset(arr_answer, 0, sizeof(arr_answer));
    scanf("%s", arr_1);
    scanf("%s", arr_2);
    int length_1 = strlen(arr_1);
    int length_2 = strlen(arr_2);

    int j = 0;
    for (int i = length_1 - 1; i >= 0; i--)
    {
        n_1[j] = arr_1[i] - '0';
        j++;
    }
    j = 0;
    for (int i = length_2 - 1; i >= 0; i--)
    {
        n_2[j] = arr_2[i] - '0';
        j++;
    }
    for (int i = 0; i < length_2; i++)
    {
        for (int j = 0; j < length_1; j++)
        {
            arr_answer[i + j] += n_1[j] * n_2[i];
        }
    }
    int highest = 0;
    for (int i = 0; i < 200; i++)
    {
        if (arr_answer[i] >= 10)
        {
            arr_answer[i + 1] = arr_answer[i + 1] + arr_answer[i] / 10;
            arr_answer[i] = arr_answer[i] % 10;
        }
        if (arr_answer[i])
        {
            highest = i;
        }
    }
    for (int i = highest; i >= 0; i--)
    {
        printf("%d", arr_answer[i]);
    }
    return 0;
}