#include <stdio.h>
#include <string.h>
void minus(char a[], char b[])
{
	int l = strlen(a), r = strlen(b), dd = 0, carry = 0;
	char tmp[1005], s[1005];
	if (l == r)
	{
		for (int i = 0; i < l; i++)
		{
			if (a[i] < b[i])
			{
				dd = 1;
				break;
			}
		}
	}
	if (l < r || dd)
	{
		strcpy(tmp, b);
		strcpy(b, a);
		strcpy(a, tmp);
		l = strlen(a), r = strlen(b);
	}
	dd = 0;
	for (int i = l - r; i >= 0; i--)
		b[i + l - r] = b[i];
	for (int i = 0; i < l - r; i++)
		b[i] = '0';
	for (int i = l - 1; i >= 0; i--)
	{
		int k = a[i] - '0' - (b[i] - '0') + carry;
		if (k < 0)
		{
			k += 10;
			carry = -1;
		}
		s[i] = k + '0';
	}
	for (int i = 0; i < l; i++) 
	{
		if (s[i] != '0' && !dd)
			dd = 1;
		if (dd)
			printf("%c", s[i]);
	}
	printf("\n");
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	char a[1005], b[1005];
	while (t--)
	{
		scanf("%s%s", a, b);
		minus(a, b);
	}
}
