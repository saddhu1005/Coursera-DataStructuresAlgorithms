#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx[30][30],mn[30][30];
ll min(ll a,ll b,ll c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
ll max(ll a,ll b,ll c)
{
    return a>b?(a>c?a:c):(b>c?b:c);
}
ll calc(ll a,char op,ll b)
{
	switch(op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
	}
}
void minmax(ll i,ll j,string s)
{
	ll minm=INT_MAX;
	ll maxm=INT_MIN;

	for(ll k=i;k<j;++k)
		{	
			ll a=calc(mx[i][k],s[k],mx[k+1][j]);
			ll b=calc(mn[i][k],s[k],mx[k+1][j]);
			ll c=calc(mx[i][k],s[k],mn[k+1][j]);
			ll d=calc(mn[i][k],s[k],mn[k+1][j]);
			minm=min(min(minm,d),min(a,b,c));
			maxm=max(max(maxm,d),max(a,b,c));
		}
		mn[i][j]=minm;
		mx[i][j]=maxm;
}
ll calmax(string s,ll n)
{
ll i,j,l;
for(l=1;l<=n-1;++l)
{

	for(i=1;i<=n-l;++i)
	{
		j=i+l;
		minmax(i,j,s);

	}
}
return mx[1][n];
}
int main()
{	
string s;
cin>>s;
string op;
op.resize(s.size());
ll i,j=1;
for(i=0;i<s.size();i+=2,j++)
{
	mx[j][j]=s[i]-'0';
	mn[j][j]=s[i]-'0';

}
op[0]=':';
 j=1;
 ll n=s.size()/2+1;
for(ll i=1;i<s.size();i+=2)
{
	op[j++]=s[i];
}



cout<<calmax(op,n)<<"\n";

return 0;
}