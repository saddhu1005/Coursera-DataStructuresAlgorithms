#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

const ll p=10000019;
 const ll x=31;
struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}
ll polyhash(string s)
{
    ll i;
    ll hash=0;
    for(i=s.size()-1;i>=0;--i)
    {
        hash=(hash*x +s[i])%p;
    }
    return hash;

}
const vector<ll> precomputehash(string t,string s)
{

    string st;
    st.resize(s.size());
    ll i,j;
    ll y=1;
    for(i=1;i<=s.size();++i)
        y=(y*x)%p;
    for(j=0,i=t.size()-s.size();i<t.size();++i,j++)
        st[j]=t[i];

   // cout<<st<<" "<<y<<"\n";

    vector<ll> H(t.size()-s.size()+1);

    H[t.size()-s.size()]=polyhash(st);

    //cout<<H[t.size()-s.size()]<<"\n";

    for(i=t.size()-s.size()-1;i>=0;--i)
    {
        H[i]=(x*H[i+1]+t[i]-(y*t[i+s.size()])%p+p)%p;

       // cout<<H[i]<<"\n";
    }
    return H;
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    vector<ll> H= precomputehash(t,s);
    ll hash=polyhash(s);
    //cout<<hash<<" pattern\n";
    for (size_t i = 0; i<=t.size()-s.size() ; ++i)
    {   
        if(hash==H[i])
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);

    print_occurrences(get_occurrences(read_input()));
    return 0;
}
