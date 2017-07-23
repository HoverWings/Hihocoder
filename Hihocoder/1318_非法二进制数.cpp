#include<cstdio>
#include<iostream>
#include<cmath>
typedef long long LL;
const LL mod = 1000000007;
using namespace std;
//这是个数学题


LL quickmul(LL x, LL n)
{
	LL ret = 1;
	while (n) 
	{
		if (n & 1) ret = (ret * x) % mod;
		n >>= 1;
		x = (x * x) % mod;
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	LL p=0, q=1;
	for (int i = 1; i <= n-2; i++)
	{
		if(i%2)//奇数
		{
			p = (q + p)%mod + (LL)quickmul(2,i)%mod;//i=1时算出来的3
		}
		else
		{
			q = (p + q)%mod + (LL)quickmul(2, i)%mod;
		}
	}
	LL ans = (p > q ? p : q);
	cout << ans<<endl;
	return 0;
}