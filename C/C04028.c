#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
int main() 
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pos = 0;
    for (int i = 0; i <= pos; i++)
    {
        printf("Buoc %d: ", i);
        for (int j = pos; j > 0; j--)
        {
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
        }
        for (int j = 0; j <= i; j++)
            printf("%d ", a[j]);
        printf("\n");
        ++pos;
        if (pos == n)
            break;
    }
}