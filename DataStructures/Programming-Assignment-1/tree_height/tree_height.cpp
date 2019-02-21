#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a,b) make_pair(a,b)
int main()
{
	ll n;
	cin>>n;
	vector<ll> v[n+1];
	ll node;
	ll ele;
	ll i;
	for(i=0;i<n;++i)
	{
		cin>>ele;
		if(ele==-1)
		{
			node=i;
		}
		else
		{
			v[ele].push_back(i);
			v[i].push_back(ele);
		}
	}
	ll ans=0;
	ll dp[n+1]={0};
	queue<pair<ll,ll> > q;
	q.push(mp(node,1));
	ll visit[n+1]={0};
	pair<ll,ll> p;
	ans++;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		node=p.first;
		visit[node]=1;
		ans=max(ans,p.second);
		for(i=0;i<v[node].size();++i)
		{	if(!visit[v[node][i]])
				{	
					q.push(mp(v[node][i],p.second+1));

				}
		}
	}
	cout<<ans<<"\n";
}