#include <stdio.h>
#include <string.h>
char a[100], b[100];
int x[100], y[100], z[100], m[100];
int digit;
void sub(int x[], int y[], int len1, int len2)
{ //大数减法，倒序相减
    for (int i = 0; i < len1; i++)
    {
        if (x[i] >= y[i])
        {
            x[i] = x[i] - y[i];
        }
        else
        {
            x[i] = x[i] + 10 - y[i];
            x[i + 1] = x[i + 1] - 1;
        }
    }
    for (int i = len1 - 1; i >= 0; i--)
    {
        if (x[i])
        {
            digit = i + 1;
            break;
        }
    }
}
int judge(int x[], int y[], int len1, int len2)
{
    if (len1 < len2)
    {
        return -1;
    }
    if (len1 == len2)
    {
        for (int i = len1; i >= 0; i--)
        {
            if (x[i] == y[i])
            {
                continue;
            }
            if (x[i] > y[i])
            {
                return 1;
            }
            if (x[i] < y[i])
            {
                return -1;
            }
        }
        return 0;
    }
    return 1;
}
int main()
{
    int i, j = 0, k = 0, temp;
    int len1, len2, len;
    scanf("%s", a);
    scanf("%s", b);
    len1 = strlen(a);
    len2 = strlen(b);
    for (i = len1 - 1, j = 0; i >= 0; i--)
    {
        x[j++] = a[i] - '0';
    }
    for (i = len2 - 1, k = 0; i >= 0; i--)
    {
        y[k++] = b[i] - '0';
    }
    if (len1 < len2)
    {
        printf("0\n%s", a);
    }
    else
    {
        len = len1 - len2;
        for (i = len1 - 1; i >= 0; i--)
        {
            if (i >= len)
            {
                y[i] = y[i - len];
            }
            else
            {
                y[i] = 0;
            }
        }
        len2 = len1;
        digit = len1;
        for (j = 0; j <= len; j++)
        {
            z[len - j] = 0;
            while ((((temp = judge(x, y, len1, len2) )>= 0)) && digit >= k)
            {
                sub(x, y, len1, len2);
                z[len - j]++;
                len1 = digit;
                if (len1 < len2 && y[len2 - 1] == 0)
                {
                    len2 = len1;
                }
            }
            if (temp < 0)
            {
                for (i = 1; i < len2; i++)
                {
                    y[i - 1] = y[i];
                }
                y[i - 1] = 0;
                if (len1 < len2)
                {
                    len2--;
                }
            }
        }
        for (i = len; i > 0; i--)
        {
            if (z[i])
            {
                break;
            }
        }
        for (; i >= 0; i--)
        {
            printf("%d", z[i]);
        }
        printf("\n");
        for (i = len1; i > 0; i--)
        {
            if (x[i])
            {
                break;
            }
        }
        for (; i >= 0; i--)
        {
            printf("%d", x[i]);
        }
    }
    return 0;
}