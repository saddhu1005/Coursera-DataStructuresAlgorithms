#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll prio;
	ll id;
	Node()
	{
		prio=0;
		id=0;
	}
	Node(ll p,ll i)
	{
		prio=p;
		id=i;
	}
	friend bool operator<( const Node &first, const Node &second );

	friend bool operator==( const Node &first, const Node &second );

	friend bool operator>( const Node &first, const Node &second );

	friend bool operator!=( const Node &first, const Node &second );
};

bool operator<( const Node &first, const Node &second )
{
  if ( first.prio < second.prio )
	return true;
  else if ( first.prio == second.prio )
  {
	if ( first.id < second.id )
	  return true;
	else
	  return false;
  }
  return false;
}

bool operator==( const Node &first, const Node &second )
{
  return first.prio == second.prio;
}

bool operator>( const Node &first, const Node &second )
{
  return !( first < second ) && !( first == second );
}

bool operator!=( const Node &first, const Node &second )
{
  return !( first == second );
}

void swap(Node *x,Node *y)
{
	Node z=*x;
	*x=*y;
	*y=z;
}
class Heap
{	private:
	ll size;
	ll maxsize;
	vector<Node> data;
	public:
		Heap(ll s)
		{
			size=s;
			maxsize=s+10;
			data.resize(maxsize);
			for ( ll i = 0; i < size; ++i )
				{
				 data[ i ] = Node( 0, i );
				}
		}
	protected :
	ll parent(ll i)
	{	
		return i==0?0:(i-1)/2;
	}
	ll left(ll i)
	{
		return 2*i+1;
	}
	ll right(ll i)
	{
		return 2*i+2;
	}
	void shift_up(ll i)
	{

		while(i>0 && data[parent(i)]>data[i])
		{	
			
			swap(&data[i],&data[parent(i)]);
			i=parent(i);

		}

	}
	void shift_down(ll i)
	{
		ll mi=i;
		ll lchild=left(i);
		while(lchild<size && data[lchild]<data[mi])
		{
			mi=lchild;
		}
		ll rchild=right(i);
		while(rchild<size && data[rchild]<data[mi])
		{
			mi=rchild;
		}

		if(i!=mi)
		{
			
			swap(&data[i],&data[mi]);
			shift_down(mi);
		}
	}
	public:
		void buildheap()
		{
			ll mi=size/2;
			ll i;
			for(i=mi;i>=0;--i)
			{
				shift_down(i);
			}
		}
		void insert(const Node &n)
		{
			size+=1;
			data[size-1]=n;
			shift_up(size-1);
		}
		void changeprio(ll i,ll prio)
		{
			Node &n=data[i];
			ll oldp=n.prio;
			n.prio=prio;
			if(prio>oldp)
				shift_down(i);
			else
				shift_up(i);
		}
		Node GetMax()
		{
			const Node &n=data[0];
			return n;
		}
};
class jobqueue
{
	private:
	ll jobs;
	ll threads;
	vector<ll> job;
	vector<ll> job_thread;
	vector<ll> times;

private:
	void printans()
	{
		for(ll i=0;i<jobs;++i)
		{
			cout<<job_thread[i]<<" "<<times[i]<<"\n";
		}
	}
	void input()
	{
		cin>>threads>>jobs;
		job.resize(jobs);
		for(ll i=0;i<jobs;++i)
		{
			cin>>job[i];
		}
	}
	void assignment()
	{
		job_thread.resize(jobs);
	times.resize(jobs);
	vector<ll> next_free_time(threads, 0);
	Heap heap(threads);
	for (ll i = 0; i < jobs; ++i) {
	  ll duration = job[i];
	  
	  Node node=heap.GetMax();
	  job_thread[i] = node.id;
	  times[i] = next_free_time[node.id];
	  next_free_time[node.id] += duration;

	  heap.changeprio(0,node.prio + duration);
	
		}
	}
public:
	void solve()
	{
		input();
		assignment();
		printans();
	}
};
int main()
{
	
 ios_base::sync_with_stdio(false);
 jobqueue jq;
 jq.solve();
 return 0;
}