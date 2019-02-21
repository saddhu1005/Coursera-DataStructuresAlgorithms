#include <bits/stdc++.h>
#include<algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long int ll;

struct Query {
    string type, name;
    ll number;
};
struct contac {
    list<pair <ll,string> > s;
    
};
//vector<contac> hash(100003);
ll gethash(ll number)
{
    ll hash=0;
    ll a=31;
    ll p=10000019;
    ll b=7;
    ll m=100003;
    return ((((a*number)%p)+b)%p)%m;

}
vector<Query> read_queries() {
    ll n;
    cin >> n;
    vector<Query> queries(n);
    for (ll i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<contac> contacts(100003);
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            ll hash=gethash(queries[i].number);
            list< pair<ll,string> > :: iterator itr;
            for(itr=(contacts[hash].s).begin();itr!=(contacts[hash].s).end();++itr){

                if (itr->first == queries[i].number) {
                    itr->second = queries[i].name;
                    was_founded = true;
                  
                }
            }
            // otherwise, just add it
            if (!was_founded)
                {
                    (contacts[hash].s).push_front(make_pair(queries[i].number,queries[i].name));
                }
        } else if (queries[i].type == "del") {
            ll hash=gethash(queries[i].number);
                list< pair<ll,string> > :: iterator itr;
            for(itr=(contacts[hash].s).begin();itr!=(contacts[hash].s).end();++itr){

                if (itr->first == queries[i].number) {
                   (contacts[hash].s).erase(itr);
                   break;
                }
            }
        } else {
            string response = "not found";
            ll hash=gethash(queries[i].number);
            list< pair<ll,string> > :: iterator itr;
                for(itr=(contacts[hash].s).begin();itr!=(contacts[hash].s).end();++itr){
                    
                if (itr->first == queries[i].number) {
                    response = itr->second;
                    
                }
            }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
