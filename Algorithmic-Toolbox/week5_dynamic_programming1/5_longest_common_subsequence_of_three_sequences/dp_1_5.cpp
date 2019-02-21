#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max(ll a,ll b,ll c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
ll dp[103][103][103];
ll lcs3(ll i,ll j,ll k,vector<ll> a,vector<ll> b,vector<ll> c)
{
if(i>=a.size() || j>=b.size() || k>=c.size())
{
	return 0;
}
if(dp[i][j][k]!=-1)
return dp[i][j][k];
if(a[i]==b[j] && a[i]==c[k])
return dp[i][j][k]=1+lcs3(i+1,j+1,k+1,a,b,c);
else
	return dp[i][j][k]=max(lcs3(i,j,k+1,a,b,c),lcs3(i,j+1,k,a,b,c),lcs3(i+1,j,k,a,b,c));
}
int main()
{
ll m,n,l;
vector<ll>a,b,c;
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
cin>>l;
c.resize(l);
for(i=0;i<l;++i)
{
cin>>c[i];
}
memset(dp,-1,sizeof(dp));
cout<<lcs3(0,0,0,a,b,c);
return 0;
}