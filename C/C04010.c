#include <stdio.h>
int main()
{
//	freopen("a.inp", "r", stdin);
	int n, x, minn = 1e9 + 5, minn2 = 1e9 + 5;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (minn > x)
		{
			minn2 = minn;
			minn = x;
		}
		else
		{
			if (x < minn2 && x != minn)
				minn2 = x;
		}
	}
	printf("%d %d", minn, minn2);
}
