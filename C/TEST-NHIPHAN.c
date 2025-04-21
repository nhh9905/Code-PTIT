#include <stdio.h>
int main() 
{
    int a, b[15], cnt = 0;
    scanf("%d", &a);
    if (a == 0)
        printf("0");
    while (a)
    {
        b[cnt++] = a % 2;
        a /= 2;
    }
    for (int i = cnt - 1; i >= 0; i--)
        printf("%d", b[i]);
}