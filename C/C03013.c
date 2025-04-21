#include <stdio.h>
int n, f[35];
int main()
{
	scanf("%d", &n);
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 30; i++) 
		f[i] = f[i - 1] + f[i - 2];
	for (int i = 0; i < n; i++)
		printf("%d ", f[i]);
}
