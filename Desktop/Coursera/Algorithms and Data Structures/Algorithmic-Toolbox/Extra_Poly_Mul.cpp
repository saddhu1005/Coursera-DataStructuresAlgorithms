#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll * multp(ll a[],ll b[],ll n,ll l, ll r)
{
    ll *rs=new ll[n*2-1];
    for(ll i=0;i<n*2-1;++i)
    rs[i]=0;
    if(n==1)
    {
        rs[0]=a[l]*b[l];
        return rs;
    }
    rs=multp(a,b,n/2,l,r);
    rs=multp(a,b,n/2,l+n/2,r+n/2);
    ll *d0e=new ll[n/2];
    for(ll i=0;i<n/2;++i)
        d0e[i]=0;
    d0e=multp(a,b,n/2,l,r+n/2);
    ll *d1e=new ll[n/2];
    for(ll i=0;i<n/2;++i)
        d1e[i]=0;
    d1e=multp(a,b,n/2,l+n/2,r);
   for(ll i=n/2;i<n+n/2;++i)
   {
       rs[i]+=d1e[i-n/2]+d0e[i-n/2];
   }
    return rs;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n+1],b[n+1];
    ll i;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(i=0;i<n;++i)
    {
        cin>>b[i];
    }
    ll *r=new ll[2*n-1];
    r=multp(a,b,4,0,0);
    for(i=2*n-2;i>=0;--i)
    {
        cout<<r[i]<<" ";
    }
    cout<<endl;
}