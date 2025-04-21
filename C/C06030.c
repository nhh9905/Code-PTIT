#include <stdio.h>
#include <string.h>
char s[100005];
struct word
{
	char tu[105];
	int num;
};
typedef struct word word;
word a[1005];
int n = 1, maxx = 0;
int find(char x[105])
{
	for (int i = 1; i < n; i++)
	{
		if (strcmp(a[i].tu, x) == 0)
			return i;
	}
	return -1;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int main()
{
	freopen("a.inp", "r", stdin);
	gets(s);
	char *token = strtok(s, " ");
	while (token != NULL)
	{
		int pos = find(token);
		if (pos != -1) 
			a[pos].num++;
		else
		{
			a[n].num = 1;
			strcpy(a[n].tu, token);
			maxx = max(maxx, strlen(a[n].tu));
			++n;
		}
		token = strtok(NULL, " ");
	}
	for (int i = 1; i < n; i++)
	{
		if (strlen(a[i].tu) == maxx)
			printf("%s %d %d\n", a[i].tu, strlen(a[i].tu), a[i].num);
	}
}

