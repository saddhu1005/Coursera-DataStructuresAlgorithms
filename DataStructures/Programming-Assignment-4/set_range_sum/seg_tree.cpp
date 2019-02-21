#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class SegTree{
	ll tree[200007];
	ll *arr;
	ll size;
public:
	SegTree()
	{
		size=0;
	}
	void read_input()
	{
		
		cin>>size;
		arr=new ll[size];
		for(int i=0;i<size;++i)
		cin>>arr[i];

	}
	int left(int i)
	{
		return 2*i+1;
	}
	int right(int i)
	{
		return 2*i+2;
	}
	int parent(int i)
	{
		if(i==0)
			return 0;
		return (ceil(i/2.0)-1);
	}
	int mid(int i,int j)
	{
		return (i+j)/2;
	}
	void buildTree(int node,int start,int end)
	{
		if(start==end)
			tree[node]=arr[start];
		else
		{
			buildTree(left(node),start,mid(start,end));
			buildTree(right(node),mid(start,end)+1,end);
			tree[node]=tree[left(node)]+tree[right(node)];
		}
	}
	void update(int node,int start,int end,int idx,ll val)
	{
		if(start==end)
		{
			arr[idx]+=val;
			tree[node]+=val;
		}
		else
		{
			if(start<=idx && idx<=mid(start,end))
			{
				update(left(node),start,mid(start,end),idx,val);
			}
			else
			{
				update(right(node),mid(start,end)+1,end,idx,val);
			}
			tree[node]=tree[left(node)]+tree[right(node)];
		}
	}
	ll range_sum(int node,int start,int end,int l,int r)
	{
		if(r<start || l>end)
			return 0;
		if(l<=start && end<=r)
			return tree[node];
		ll p1=range_sum(left(node),start,mid(start,end),l,r);
		ll p2=range_sum(right(node),mid(start,end)+1,end,l,r);
		return (p1+p2);
	}
	void rangeupdate_notlazy(int node,int start,int end,int l,int r,int val)
	{
		if(start>r || l>end || start>end)
			return ;
		if(start==end)
		{
			tree[node]+=val;
			return;
		}
		rangeupdate_notlazy(left(node),start,mid(start,end),l,r,val);
		rangeupdate_notlazy(right(node),mid(start,end)+1,end,l,r,val);
		tree[node]=tree[left(node)]+tree[right(node)];
	}
	void read_query()
	{
		int q;
		cin>>q;
		ll type,l,r,idx,val;
		/*
		type=0 : update value of idx with val
		type=1 : rangesum from l to r
		idx and l,r are 1-based indexed.
		*/
		for(int i=0;i<q;++i)
		{
			cin>>type;
			if(type)
			{
				cin>>l>>r;
				cout<<range_sum(0,0,size-1,l-1,r-1);
			}
			else
			{
				cin>>idx>>val;
				update(0,0,size-1,idx-1,(val-arr[idx-1]));
			}
		}
	}
	void process()
	{
		read_input();
		buildTree(0,0,size-1);
		read_query();
	}
};
int main()
{
	SegTree t;
	t.process();


	return 0;
}