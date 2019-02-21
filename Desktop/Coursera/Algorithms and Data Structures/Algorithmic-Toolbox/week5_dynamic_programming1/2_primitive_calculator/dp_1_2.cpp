#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000007]={0};
vector<ll> v;
void cal(ll m)
{
for(ll i=4;i<=m;++i){
	ll x=dp[i-1]+1,y=dp[i/2]+1+i%2,z=dp[i/3]+1+i%3;
	x=min(x,y);
	dp[i]=min(x,z);

	}
}
int main()
{
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	
	

ll n;
cin>>n;
if(n<=3)
	{
	cout<<dp[n]<<"\n";
if(n!=1)
	cout<<"1 "<<n<<"\n";
else
	cout<<1<<"\n";
	}
else
	{	cal(n);
	cout<<dp[n]<<"\n";
	ll m=n;
	v.push_back(n);
	for(ll i=0;m>1;++i)
	{	ll d;
		ll x=dp[m-1]+1,y=dp[m/2]+1+m%2,z=dp[m/3]+1+m%3;
		d=min(x,y);
		d=min(d,z);
		if(d==x)
		{
			m=m-1;
		}
		else if(d==y)
		{
		m=m/2+m%2;	
		}
		else
		{
			m=m/3+m%3;
		}
		v.push_back(m);

	}
	reverse(v.begin(),v.end());
	for(ll i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n";
	}
return 0;
}