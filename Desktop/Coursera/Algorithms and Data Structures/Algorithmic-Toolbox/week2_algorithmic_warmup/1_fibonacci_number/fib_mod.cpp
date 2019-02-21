#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=10007;
int main()
{
  ll n,m;
  cin>>n>>m;
ll fib[mx]={0};
fib[1]=1;
for(ll i=2;i<mx;++i)
{
  fib[i]=(fib[i-1]+fib[i-2])%m;
}
//cout<<fib[mx-1]<<endl;
ll k=1;
for(ll i=1;i<mx;++i)
{
fib[i]%=m;
if(fib[i]==0)
{
  if(fib[i+1]%m==1)
  break;
}
k++;
}
n=n%k;
//cout<<k<<"\n";
cout<<fib[n];
cout<<"\n";

}
