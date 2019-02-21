#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pcs
{
ll id;
ll pt;
ll at;
};
int main()
{
	ll s,n;
	cin>>s>>n;
	queue<pcs> q;
	vector<pcs>v;
	ll i;
	pcs tmp;
	for(i=0;i<n;++i)
	{
		tmp.id=i;
		cin>>tmp.at>>tmp.pt;
		v.push_back(tmp);
	}
	bool busy=false;
	ll cmp=0,ans[n+1],tim=0;
	pcs cur;
	while(true)
	{   
		if(cmp>=n)
			break;
		for(i=0;i<n;++i)
		{   
			if(v[i].at==tim)
			{	if(!busy && v[i].pt==0 && q.size()<s)
				{
					ans[v[i].id]=tim;
					cmp++;
				}
				else if(q.size()<s)
				{	
					q.push(v[i]);
				}
				else
				{
					ans[i]=-1;
					cmp++;
				}
			}

		}
		
		if(cmp>=n)
			break;
		if(busy)
		{

			cur.pt--;
			if(cur.pt==0)
			{
			cmp++;
			q.pop();
			busy=false;
			}
		}

		if(!busy && !q.empty())
		{
			cur=q.front();
			busy=true;
			ans[cur.id]=tim;
			while(cur.pt==0)
			{
			cmp++;
			q.pop();
			busy=false;
			if(!q.empty())
			{
			cur=q.front();
			busy=true;
			ans[cur.id]=tim;
			}
			else
				break;
			}


		}
		if(cmp>=n)
			break;

		tim++;
	}
	for(i=0;i<n;++i)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
