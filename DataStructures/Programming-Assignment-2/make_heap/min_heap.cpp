#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void swap(ll *x,ll *y)
{
	ll z=*x;
	*x=*y;
	*y=z;
}
class minheap
{	private:
	vector<ll> heap;
	vector< pair<ll,ll> > ans;
	ll n;
	vector<ll> data;
	protected :
	ll parent(ll i)
	{
		return (i-1)/2;
	}
	ll left(ll i)
	{
		return 2*i+1;
	}
	ll right(ll i)
	{
		return 2*i+2;
	}
	void insert(ll e)
	{
		data.push_back(e);
		ll i=data.size()-1;
		while(i>0 && data[i]<data[parent(i)])
			{
				ans.push_back(make_pair(i,parent(i)));
			swap(&data[i],&data[parent(i)]);
			i=parent(i);
			}
			

	}
	void shift_up(ll i)
	{
		ll e=i;

		while(e>0 && heap[parent(e)]>heap[e])
		{	
			ans.push_back(make_pair(e,parent(e)));
			swap(&heap[e],&heap[parent(e)]);
			e=parent(e);

		}

	}
	void shift_down(ll i)
	{
		ll size=n-1;
		ll mi=i;
		ll lchild=left(i);
		while(lchild<=size && heap[lchild]<heap[mi])
		{
			mi=lchild;
		}
		ll rchild=right(i);
		while(rchild<=size && heap[rchild]<heap[mi])
		{
			mi=rchild;
		}

		if(i!=mi)
		{
			ans.push_back(make_pair(i,mi));
			swap(&heap[i],&heap[mi]);
			shift_down(mi);
		}
	}
	void printans()
	{
		cout<<ans.size()<<"\n";
		for(ll i=0;i<ans.size();++i)
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	void input()
	{
		ll i;
		cin>>i;
		n=i;
		heap.resize(n);
		for(i=0;i<n;++i)
			cin>>heap[i];
	}
	void buildheap()
	{	ans.clear();
		ll i;
		ll mid=n/2;
		for(i=mid;i>=0;--i)
		{
			shift_down(i);
		}
		/*
		for(i=0;i<n;++i)
		{
			insert(heap[i]);
		}
		*/
		
	}
	public :
	void solve()
	{
		input();
		buildheap();
		printans();

	}
};
int main()
{
	minheap hp;
	hp.solve();

	return 0;
}