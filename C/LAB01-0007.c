#include <stdio.h>
#include <string.h>
int main()
{  
	int n;
	scanf("%d", &n);
	float s = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		s += x;
	}
	printf("%.3f", s/(float)n);
}