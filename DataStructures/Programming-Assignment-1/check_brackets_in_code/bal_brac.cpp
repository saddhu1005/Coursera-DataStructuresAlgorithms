#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin>>s;
	ll i;
	char ch;
	bool ans=true;
	stack<pair<char,ll> > st;
	for(i=0;i<s.size();++i)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
			{st.push(make_pair(s[i],i+1));
			}
		if(s[i]==')' || s[i]=='}' || s[i]==']' )
			{	if(st.empty())
				{
					cout<<i+1<<'\n';
						ans=false;
						break;
				}
				else
				{
					ch=st.top().first;
					st.pop();
					switch(ch)
					{
					case '(': if(s[i]!=')')
								ans=false;
								break;
					case '{':if(s[i]!='}')
								ans=false;
								break;
					case '[':if(s[i]!=']')
								ans=false;
								break;
					}
					if(!ans)
					{
						cout<<i+1<<"\n";
						break;
					}
				}
			}
	}
	if(ans && st.empty())
	{
		cout<<"Success"<<'\n';
	}
	else if(ans)
	{
		while(!st.empty())
			{	i=st.top().second;
				st.pop();
			}
			cout<<i<<'\n';
	}
	return 0;
}