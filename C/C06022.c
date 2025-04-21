#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() 
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
    	scanf("\n");
        printf("Test %d: ", i);
        char s1[2005], s2[205], tmp[205];
        gets(s1);
        scanf("%s", s2);
        for (int i = 0; i < strlen(s2); i++)
            s2[i] = tolower(s2[i]);
        char *token = strtok(s1, " ");
        while (token != NULL)
        {
            strcpy(tmp, token);
            for (int i = 0; i < strlen(tmp); i++)
            	tmp[i] = tolower(tmp[i]);
            if (strcmp(tmp, s2))
                printf("%s ", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }
}
