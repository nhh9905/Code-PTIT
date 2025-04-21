#include <stdio.h>
#include <string.h>
#include <ctype.h>
void chuanhoa(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        s[i] = tolower(s[i]);
}
int main() 
{
    // freopen("a.inp", "r", stdin);
    char s[2005], a[205][205];
    int cnt = 0, d[205] = {0};
    gets(s);
    char *token = strtok(s, " ");
    while (token != NULL)
    {
        int pos = 0;
        chuanhoa(token);
        for (int i = 1; i <= cnt; i++)
        {
            if (strcmp(a[i], token) == 0)
            {
                pos = i;
                d[i]++;
            }
        }
        if (pos == 0)
        {
            strcpy(a[++cnt], token);
            d[cnt]++;
        }
        token = strtok(NULL, " ");
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (d[i])
        {
            printf("%s %d\n", a[i], d[i]);
            d[i] = 0;
        }
    }
}