#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=107;
int main()
{
  ll n;
  cin>>n;
ll fib[mx]={0};
ll sum[mx]={0};
fib[1]=1;
sum[1]=1;
for(ll i=2;i<mx;++i)
{
  fib[i]=(fib[i-1]+fib[i-2])%10;
  sum[i]=(fib[i]+sum[i-1])%10;
}
//cout<<fib[mx-1]<<endl;
if(n<=60)
{
  cout<<sum[n]<<"\n";
  return 0;
}
ll k=1;
for(ll i=2;i<mx;++i)
{
if(sum[i]==1)
{
if(sum[i+1]==2 && sum[i+2]==4 && sum[i+3]==7)
break;
}
k++;
}
//cout<<k<<"\n";
n=n%k;
cout<<sum[n]<<"\n";

}
