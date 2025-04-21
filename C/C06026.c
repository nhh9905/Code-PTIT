#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int n = 0, len = 0;
struct tu
{
	char s[1005];
	int dem;	
};
typedef struct tu tu;
tu a[1005];
bool tn(char x[])
{
	int l = 0, r = strlen(x) - 1;
	while (l < r)
	{
		if (x[l] != x[r])
			return 0;
		l++; r--;
	}
	return 1;
}
int find(char x[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(x, a[i].s) == 0) //tim thay x
			return i;
	}
	return -1; //ko tim thay x
}
int main()
{
	char x[1005];
	while (scanf("%s", x) != -1)
	{
		if (tn(x))
		{
			int pos = find(x);
			if (pos != -1)
				a[pos].dem++;
			else
			{
				strcpy(a[n].s, x);
				a[n].dem = 1;
				n++;
			}
			if (strlen(x) > len)
				len = strlen(x);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (len == strlen(a[i].s))
			printf("%s %d\n", a[i].s, a[i].dem);
	}
}
