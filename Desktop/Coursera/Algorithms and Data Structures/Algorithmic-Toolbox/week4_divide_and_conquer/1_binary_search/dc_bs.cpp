#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 ll bs(ll v[],ll n,ll e)
{
   
    ll mid,l,r;
    l=0;
    r=n-1;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(v[mid]==e)
        {
           return mid;
        }
        if(v[mid]<e)
        l=mid+1;
        else
        r=mid-1;
    }
    return -1;
}
int main()
{
    ll n,k;
    cin>>n;
    ll i;
    ll v[n+1];
    ll e;
    for(i=0;i<n;++i)
    {
        cin>>v[i];
    }
    cin>>k;
     ll tc[k+1];
    for(i=0;i<k;++i)
    {
       cin>>tc[i];
       
    }
    for(i=0;i<k;++i)
    {
        e=tc[i];
        cout<<bs(v,n,e)<<" ";
    }
    cout<<"\n";
    return 0;

}