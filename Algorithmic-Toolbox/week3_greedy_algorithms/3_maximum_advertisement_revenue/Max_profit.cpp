#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{   //system("cls");
    long int n,i;
    cin>>n;
    
    vector<long int > a,b;
    a.resize(n);
    b.resize(n);
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long int ans=0;
    for(i=0;i<n;++i)
    {
        ans+=a[i]*b[i];
    }
    cout<<ans<<"\n";
    return 0;
}