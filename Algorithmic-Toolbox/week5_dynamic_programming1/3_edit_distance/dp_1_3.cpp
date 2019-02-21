#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll min(ll a,ll b,ll c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
ll dp[1000][1000];
ll editdist(ll i,ll j,string s1,string s2)
{
ll dist=0;
if(i>=s1.size() && j>=s2.size())
{
	return dist;
}
if(i>=s1.size())
{
	return abs(s2.size()-j);
}
if(j>=s2.size())
{
	return abs(s1.size()-i);
}
if(dp[i][j]!=-1)
return dp[i][j];
if(s1[i]==s2[j])
return dp[i][j]=editdist(i+1,j+1,s1,s2);
else
	{ dist=min(editdist(i+1,j,s1,s2),editdist(i,j+1,s1,s2),editdist(i+1,j+1,s1,s2));
		dp[i][j]=dist+1;
		return dp[i][j];
	}
}
int main()
{
string s1,s2;
cin>>s1>>s2;
memset(dp,-1,sizeof(dp));
cout<<editdist(0,0,s1,s2);
return 0;
}