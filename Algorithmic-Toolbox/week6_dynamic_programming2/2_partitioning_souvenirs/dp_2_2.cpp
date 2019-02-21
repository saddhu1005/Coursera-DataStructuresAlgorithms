#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100007][303]={0};
ll solverec(ll a[],ll subsum[],bool take[],ll sum,ll k,ll n,ll idx,ll ldx)
{

if(subsum[idx]==sum)
{

	if(idx==k-2)
		return 1;

	return solverec(a,subsum,take,sum,k,n,idx+1,n-1);
}
for(ll i=ldx;i>=0;--i)
{
	if(take[i])
		continue;
	ll temp=subsum[idx]+a[i];

	if(temp<=sum)
	{
		subsum[idx]+=a[i];
		take[i]=true;
		ll next=solverec(a,subsum,take,sum,k,n,idx,i-1);

		take[i]=false;
		subsum[idx]-=a[i];

		if(next)
			return 1;
	}
}
return 0;

}

ll solve(ll a[],ll n,ll sum)
{
	if(sum%3!=0)
		return 0;
	ll k=3;
	ll s=sum/3;
	ll subsum[k]={0};
	bool take[n+1];
	for(ll i=0;i<=n;++i)
		take[i]=false;
	subsum[0]=a[n-1];
	take[n-1]=true;

	return solverec(a,subsum,take,s,k,n,0,n-1);

}
int main()
{	
ll n;
cin>>n;
ll i=0;
ll s=0,a[30];
for(i=0;i<n;++i)
{
	cin>>a[i];
	s+=a[i];

}

	sort(a,a+n);
	cout<<solve(a,n,s)<<"\n";


return 0;
}