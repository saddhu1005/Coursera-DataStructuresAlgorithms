#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c;
ll getcount(vector<ll> v,ll l,ll r,ll e)
{
    ll cnt=0;
    ll n=r-l+1;
    for(ll i=l;i<=r;++i)
    {
        if(v[i]==e)
        cnt++;
    }
    if(cnt>n/2)
    return e;
    else
    return -1;
}
ll getmajor(vector<ll> v,ll l,ll r)
{   
 if(l==r)
 return v[l];
if(l>r)
return -1;
 ll mid=(l+r)/2;
 ll left=getmajor(v,l,mid);
 ll right=getmajor(v,mid+1,r);
if(left==-1 && right==-1)
return -1;
if(left==-1)
return getcount(v,l,r,right);
if(right==-1)
return getcount(v,l,r,left);
return max(getcount(v,l,r,left),getcount(v,l,r,right));
}
int main()
{
    ll n;
    cin>>n;
    ll i;
    vector<ll> v;
    
    ll e;
    for(i=0;i<n;++i)
    {
        cin>>e;
        v.push_back(e);
       
    }
   ll ans=0;
  if(getmajor(v,0,n-1)!=-1)
  ans=1;
    cout<<ans<<"\n";
    return 0;

}