#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c;
ll ismajor(vector<ll> v,ll l,ll r,ll e)
{   
 if(l>r || l<0 || r>=v.size())
 return 0;
 
 if(l==r)
 {
     if(v[l]==e)
     return 1;
     return 0;
 }
 ll mid=(l+r)/2;

 ll x=ismajor(v,l,mid,e);
 ll y=ismajor(v,mid+1,r,e);
 if(x>(mid-l+1)/2 || y>(r-mid)/2)
 return x+y;
 else
 return 0;
}
int main()
{
    ll n;
    cin>>n;
    ll i;
    vector<ll> v;
    map<ll,ll> mp;
    ll e;
    for(i=0;i<n;++i)
    {
        cin>>e;
        v.push_back(e);
        mp[e]++;
    }
   ll ans=0;
  /*  for(i=0;i<n;++i)
    {   
    e=v[i];
    ll x=ismajor(v,0,n-1,e);
    if(x>n/2)
    {
        ans=1;
         break;
    }
   
    }
    */
   map<ll,ll>:: iterator it;
   for(it=mp.begin();it!=mp.end();++it)
   {
       if(it->second>n/2)
       {
           ans=1;
           break;
       }
   }
    cout<<ans<<"\n";
    return 0;

}