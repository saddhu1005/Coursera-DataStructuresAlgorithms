#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max(ll a,ll b,ll c)
{
    return a>b?(a>c?a:c):(b>c?b:c);
}
ll dp[103][103][103];
ll lcs3(ll m,ll n,ll l,ll a[],ll b[],ll c[])
{
    
for (ll i=0; i<=m; i++) 
    { 
        for (ll j=0; j<=n; j++) 
        { 
            for (ll k=0; k<=l; k++) 
            { 
                if (i == 0 || j == 0||k==0) 
                    dp[i][j][k] = 0; 
  
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1]) 
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1; 
  
                else
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]); 
            } 
        } 
    }
return dp[m][n][l] ;
}
int main()
{
ll m,n,l;
ll a[103],b[103],c[103];
ll i;
cin>>m;

for(i=0;i<m;++i)
{
cin>>a[i];
}
cin>>n;

for(i=0;i<n;++i)
{
cin>>b[i];
}
cin>>l;

for(i=0;i<l;++i)
{
cin>>c[i];
}

cout<<lcs3(m,n,l,a,b,c);
return 0;
}