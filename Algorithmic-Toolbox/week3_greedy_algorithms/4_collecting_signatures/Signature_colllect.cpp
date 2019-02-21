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
    vector<p> a;
    //a.resize(n);
    long long int x,y;
    for(i=0;i<n;++i)
   {
       cin>>x>>y;
       a.push_back(p(x,y));
   }
    sort(a.begin(),a.end(),sby);
    
    long long int ans=0;
    vector<long long int> v;
    y=a[0].b;
    x=a[0].b;
 
    for(i=1;i<n;++i)
    {
        if(a[i].a<=y)
        {   y=min(a[i].b,y);
            continue;
        }
        else
        {
        v.push_back(y);
        y=a[i].b; 
       
        }
    }
    v.push_back(y);
    ans=v.size();
    cout<<ans<<"\n";
    for(i=0;i<ans;++i)
    cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}