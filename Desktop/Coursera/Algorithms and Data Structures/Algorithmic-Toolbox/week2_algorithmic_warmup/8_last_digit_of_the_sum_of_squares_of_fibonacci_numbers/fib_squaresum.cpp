#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=107;
int main()
{
ll fib[mx]={0};
fib[1]=1;
for(ll i=2;i<mx;++i)
{
  fib[i]=(fib[i-1]+fib[i-2])%10;
}
ll n;
cin>>n;
ll k=n+1;
n=n%60;
k=k%60;
ll ans=fib[n]*fib[k];
ans%=10;

cout<<ans<<"\n";
return 0;
}
