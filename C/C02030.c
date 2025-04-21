#include <stdio.h>
int main() 
{
    int n, kc = 2, k = 0;
    scanf("%d", &n);
    char a = 'B';
    for (int i = 1; i <= n; i++)
    {
        a = 'B';
        if (i == 1)
            printf("@\n");
        else
        {
            printf("@");
            for (int j = 1; j <= k*2 - 1; j++)
            {
                printf("%c", a);
                if (j < k)
                    a += 2;
                else
                    a -= 2;
            }
            printf("@\n");
        }
        k++;
    }
}