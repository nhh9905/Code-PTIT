#include <stdio.h>
#include <string.h>
void add(char a[], char b[])
{
	int l = strlen(a), r = strlen(b), carry = 0;
	char tmp[505], s[505];
	if (l > r)
	{
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
		l = strlen(a), r = strlen(b);
	}
	for (int i = r - l; i >= 0; i--)
		a[i + r - l] = a[i];
	for (int i = 0; i < r - l; i++)
		a[i] = '0';
	for (int i = r - 1; i >= 0; i--)
	{
		int k = a[i] - '0' + b[i] - '0' + carry;
		carry = k/10;
		s[i] = k % 10 + '0';
	}
	if (carry)
		printf("%d", carry);
	for (int i = 0; i < r; i++)
		printf("%c", s[i]);
	printf("\n");
}
int main()
{
//	freopen("a.inp", "r", stdin);
	int t;
	scanf("%d", &t);
	char a[505], b[505];
	while (t--)
	{
		scanf("%s%s", a, b);
		add(a, b);
	}
}
