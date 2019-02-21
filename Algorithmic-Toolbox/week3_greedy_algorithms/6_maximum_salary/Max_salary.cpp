#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;

inline bool sby(string a,string b)
{
 string ab=a.append(b);
 string ba=b.append(a);
 return ab.compare(ba)>0;

}
int main()
{   //system("cls");
    long int n,i;
    cin>>n;
   // ios::sync_with_stdio(0);

    vector<string> v;

    long int j;
    string x;
     
   for(i=0;i<n;++i)
   {
       cin>>x;

       v.push_back(x);
	}
    sort(v.begin(),v.end(),sby);

    for(i=0;i<v.size();++i)
    {
      cout<<v[i];
    }
    cout<<endl;

    return 0;
}
/*
30
2 8 2 3 6 4 1 1 10 6 3 3 6 1 3 8 4 6 1 10 8 4 10 4 1 3 2 3 2 6
*/
