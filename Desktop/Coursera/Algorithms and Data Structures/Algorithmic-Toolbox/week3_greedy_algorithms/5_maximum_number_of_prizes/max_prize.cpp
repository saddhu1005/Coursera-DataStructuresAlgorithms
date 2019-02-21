#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct p
{
  long long int a;
  long long int b;
  p(long long int c,long long int d)
  {
    a=c;
    b=d;
  }
  p()
  {
      a=0;
      b=0;
  }
};
inline bool sby(p x,p y)
{
  if(x.a!=y.a)
  return x.a<y.a;
  return x.b<y.b;
}
int main()
{   //system("cls");
    long int n,i;
    cin>>n;
    ios::sync_with_stdio(0);
    long long int ans=0;
    vector<long long int> v;
    //v.resize(n);
    i=0;
    long long int x=1;
    while(n>0)
    {
    if(n-x>x)
    {
    v.push_back(x);
    n-=x;
    x++;
    }
    else
    {
        v.push_back(n);
        n-=n;
    }
    }

    ans=v.size();
    cout<<ans<<"\n";
    for(i=0;i<ans;++i)
    cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}