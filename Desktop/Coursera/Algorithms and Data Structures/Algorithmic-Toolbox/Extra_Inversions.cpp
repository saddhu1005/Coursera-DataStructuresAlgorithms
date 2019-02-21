#include<bits/stdc++.h>
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
            cnt++;
            b[k++]=a[j++];
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
    cout<<cnt<<" "<<l<<" "<<mid<<" "<<r<<endl;
    return cnt;
}
ll inversions(vector<  ll> &a,   ll l,   ll r){
  ll cnt=0;
  if (l >= r) {
    return cnt;
  }
    ll mid=(l+r)/2;
    cnt+=inversions(a,l,mid-1);
    cnt+=inversions(a,mid,r);
    cnt+=merge(a,l,mid-1,r);
   return cnt;
}

  int main() {
    ll n;
    cin >> n;
  vector<  ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
// merge(a,l,mid,r)
   
  ll ans=inversions(a, 0, a.size() - 1);
  cout<<ans<<"\n";
   for (size_t i = 0; i < a.size(); ++i) {
      cout << a[i] << ' ';
  }
  return 0;
}
