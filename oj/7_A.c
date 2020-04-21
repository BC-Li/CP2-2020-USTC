#include <stdio.h>
#include <string.h>

int main()
{
    char arr_1[100];
    char arr_2[100];
    unsigned arr_answer[200];
    memset(arr_1, 0, sizeof(arr_1));
    memset(arr_2, 0, sizeof(arr_2));
    memset(arr_answer, 0, sizeof(arr_answer));
    scanf("%s", arr_1);
    scanf("%s", arr_2);
    int length_1 = sizeof(arr_1);
    int length_2 = sizeof(arr_2);
    unsigned n_1[110];
    unsigned n_2[110];
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
            arr_answer[i + j] = n_1[j] * n_2[i];
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