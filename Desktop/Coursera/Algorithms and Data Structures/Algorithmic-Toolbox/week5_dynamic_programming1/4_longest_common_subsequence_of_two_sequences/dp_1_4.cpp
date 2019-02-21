#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1000][1000];
ll lcs(ll i,ll j,vector<ll> a,vector<ll> b)
{
if(i>=a.size() || j>=b.size())
{
	return 0;
}
if(dp[i][j]!=-1)
return dp[i][j];
if(a[i]==b[j])
return dp[i][j]=1+lcs(i+1,j+1,a,b);
else
	return dp[i][j]=max(lcs(i,j+1,a,b),lcs(i+1,j,a,b));
}
int main()
{
ll m,n;
vector<ll>a,b;
ll i;
cin>>m;
a.resize(m);
for(i=0;i<m;++i)
{
cin>>a[i];
}
cin>>n;
b.resize(n);
for(i=0;i<n;++i)
{
cin>>b[i];
}
memset(dp,-1,sizeof(dp));
cout<<lcs(0,0,a,b);
return 0;
}