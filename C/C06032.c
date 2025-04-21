#include <stdio.h>
#include <string.h>
void sort(char s[][105], int n)
{
	char tmp1[105], tmp2[105];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			strcpy(tmp1, s[i]);
            strcat(tmp1, s[j]);
            strcpy(tmp2, s[j]);
            strcat(tmp2, s[i]);
			if (strcmp(tmp1, tmp2) > 0)
			{
				strcpy(tmp1, s[j]);
				strcpy(s[j], s[i]);
				strcpy(s[i], tmp1);
			}
		}
	}
}
int main()
{
	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d\n", &n);
		char s[105][105];
		for (int i = 0; i < n; i++) 
			scanf("%s", s[i]);
		sort(s, n);
		for (int i = 0; i < n; i++)
			printf("%s", s[i]);
		printf("\n");
	}
}
