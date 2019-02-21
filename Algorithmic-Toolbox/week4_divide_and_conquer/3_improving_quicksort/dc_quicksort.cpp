#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll *partition2(vector< ll> &a,ll l,ll r){
    ll x = a[l];
    ll j = l;
    ll k = r;
  for (  ll i = l; i <= k;) {
    if (a[i] < x) {
       swap(a[i], a[j]);
       j++;
       i++;
    }
    else if(a[i]>x)
    {
      swap(a[i],a[k]);
      k--;
    }
    else
      i++;
    }
 // swap(a[l], a[j+1]);
  ll *m=new ll[2];
  m[1]=k;

  m[0]=j;
  return m;
}

void quick_sort(vector<  ll> &a,   ll l,   ll r) {
  if (l >= r) {
    return;
  }

    ll k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
    ll *m=new ll[2];
    m = partition2(a, l, r);

  quick_sort(a, l, m[0] - 1);
  quick_sort(a, m[1] + 1, r);
}

  int main() {
    ll n;
    cin >> n;
  vector<  ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
  // ll *m=new ll[2];
    //m = partition2(a, 0, a.size()-1);
    //cout<<m[0]<<" "<<m[1]<<"\n";
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
      cout << a[i] << ' ';
  }
  return 0;
}
