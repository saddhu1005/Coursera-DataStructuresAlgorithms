#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100007]={0};
void money(ll m)
{
for(ll i=5;i<=m;++i){
	ll x=dp[i-1]+1,y=dp[i-3]+1,z=dp[i-4]+1;
	x=min(x,y);
	dp[i]=min(x,z);

	}
}
int main()
{
	dp[1]=1;
	dp[2]=2;
	dp[3]=1;
	dp[4]=1;

ll n;
cin>>n;
if(n<=4)
	cout<<dp[n]<<"\n";
else
	{	money(n);
	cout<<dp[n]<<"\n";
	}
return 0;
}