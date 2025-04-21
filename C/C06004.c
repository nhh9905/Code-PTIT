#include <stdio.h>
#include <string.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	int a = 0, b = 0, c = 0, cnt = 0;
	char s[205];
	gets(s);
	char *token = strtok(s, " ");
	while (token != NULL)
	{
		++cnt;
		int dd;
		for (int i = 0; i < strlen(token); i++)
		{
			dd = 0;
			if ((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z')) 
			{
				a++;
				dd = 1;
			}
			if (token[i] >= '0' && token[i] <= '9') 
			{
				b++;
				dd = 1;
			}
			if (!dd)
				c++;
		}
		token = strtok(NULL, " ");
	}
	printf("%d %d %d", a, b, c + cnt - 1);
}
