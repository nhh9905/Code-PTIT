#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct
{
    int a, b;
} ptu;
ptu x[10005];
int n = 0;
int pos(ptu x[], int y)
{
    for (int i = 0; i < n; i++)
    {
        if (y == x[i].b)
            return i;
    }
    return -1;
}
int cmp(const void *a, const void *b)
{
    ptu *x = (ptu*)a;
    ptu *y = (ptu*)b;
    return x->b < y->b;
}
void tach(char *a)
{
    char *token = strtok(a, " +");
    while (token != NULL)
    {
        int l = 0, r = 0, cnt;
        for (int i = 0; i < strlen(token); i++)
        {
            if (l)
            {
                for (int j = strlen(token) - 1; j >= i; j--)
                {
                    if (token[j] < '0' || token[j] > '9')
                    {
                        cnt = j;
                        break;
                    }
                }
                int k = cnt;
                for (int j = cnt + 1; j < strlen(token); j++)
                {
                    r += (token[j] - '0')*pow(10, strlen(token) - k - 2);
                    ++k;
                }
                break;
            }
            if (token[i] < '0' || token[i] > '9')
            {
                cnt = i - 1;
                for (int j = 0; j <= i - 1; j++)
                {
                    l += (token[j] - '0')*pow(10, cnt);
                    --cnt;
                }
            }
        }
        if (pos(x, r) != -1) //neu da xuat hien so mu
            x[pos(x, r)].a += l;
        else
        {
            x[n].a = l;
            x[n].b = r;
            ++n;
        }
        token = strtok(NULL, " +");
    }
}
int main() 
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        n = 0;
        char a[2][100005];
        for (int i = 0; i < 2; i++)
        {
            scanf("\n");
            gets(a[i]);
            tach(a[i]);
        }
        qsort(x, n, sizeof(ptu), cmp);
        for (int i = 0; i < n - 1; i++)
            printf("%d*x^%d + ", x[i].a, x[i].b);
        printf("%d*x^%d\n", x[n - 1].a, x[n - 1].b);
    }
}