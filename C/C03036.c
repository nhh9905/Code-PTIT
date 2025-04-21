#include<math.h>
#include<stdio.h>
#define ll long long
int thuannghich(long long a){
	ll b=0, c=a;
	while(c){
		b=b*10+(c%10);
		c/=10;
	}
	if(b==a) return 1 ;
	else return 0; 
}
int tong(long long a){
	int sum=0;
	while(a){
		sum+=a%10;
		a/=10;
	}
	if(sum%2==0) return 0;
	else return 1;
}
int check(ll a)
{
	while (a)
	{
		if ((a % 10) % 2 == 0)
			return 0;
		a /= 10;
	}
	return 1;
}
int main () {
	int n;
	scanf("%d",&n);
	while (n--){
		long long a;
		scanf("%lld",&a);
		if(thuannghich(a) && tong(a) && check(a)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

