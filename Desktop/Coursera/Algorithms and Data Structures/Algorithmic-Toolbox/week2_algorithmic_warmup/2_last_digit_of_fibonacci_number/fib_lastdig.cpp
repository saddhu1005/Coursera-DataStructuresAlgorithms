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
ll t;
cin>>t;
t=t%60;
cout<<fib[t]<<'\n';
return 0;
}
