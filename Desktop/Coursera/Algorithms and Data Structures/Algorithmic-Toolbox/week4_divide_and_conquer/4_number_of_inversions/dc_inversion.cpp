#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll merge(vector<  ll> &a,ll l, ll mid, ll r)
{
    ll i=l,j=mid+1,k=0;
    ll cnt=0;
    ll b[r-l+3];
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];   
        }
        else 
        {  
            b[k++]=a[j++];
            cnt+=(mid+1-i);
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=r)
    {
        b[k++]=a[j++];
    }
    i=l,j=0;
    while(i<=r)
    {
        a[i++]=b[j++];
    }
  
    return cnt;
}
ll inversions(vector<  ll> &a,   ll l, ll r){
  ll mid,cnt=0;
  
  if (r>l ) {
    
     mid=(l+r)/2;
    cnt=inversions(a,l,mid);
    cnt+=inversions(a,mid+1,r);
    cnt+=merge(a,l,mid,r);
  
 }
  return cnt;
}

  int main() {
    ll n;
    cin >> n;
  vector<  ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
      {cin >> a[i];
 
      }
  }
  ll ans=inversions(a, 0, a.size() - 1);
  cout<<ans<<"\n";

  return 0;

}
