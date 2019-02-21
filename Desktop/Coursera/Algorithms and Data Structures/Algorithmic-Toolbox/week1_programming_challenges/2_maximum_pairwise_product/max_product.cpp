#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
    ll n,i,e,max1=0,max2=0,result;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>e;
        if(e>max1)
        {   max2=max1;
            max1=e;
        }
        else if(e>max2)
        {
            max2=e;
        }
    }
    result=max1*max2;
    cout<<result<<"\n";
   return 0;
}


