#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10007][303]={0};
ll gold(ll n,ll w,ll a[])
{
	ll val;
	ll i,j;
	for(i=0;i<n;++i)
	{

		for(j=1;j<=w;++j)
		{
			dp[j][i]=dp[j][i-1];
			if(j>=a[i])
			{
				val=dp[j-a[i]][i-1]+a[i];
				if(val>dp[j][i])
					dp[j][i]=val;
			}
		}
	}
	return dp[w][n-1];
}
int main()
{
	
ll n,w;
cin>>w>>n;
ll v[303];
ll i;
for(i=0;i<n;++i)
	cin>>v[i];
memset(dp,0,sizeof(dp));
cout<<gold(n,w,v);
return 0;
}