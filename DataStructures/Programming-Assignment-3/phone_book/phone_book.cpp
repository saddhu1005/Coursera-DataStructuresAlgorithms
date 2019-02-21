#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Query {
    string type, name;
    ll number;
};
struct contac {
    string name;
    ll number;
    contac()
    {
        number=-1;
    }
    
};
//vector<contac> hash(100003);
ll gethash(ll number)
{
    ll hash=0;
    ll a=31;
    ll p=10000019;
    ll b=7;
   
    return ((a*number+b)%p);

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
    vector<contac> contacts(10000019);
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            ll hash=gethash(queries[i].number);
                if (contacts[hash].number!=-1 && contacts[hash].number == queries[i].number) {
                    contacts[hash].name = queries[i].name;
                    was_founded = true;
                  
                }
            // otherwise, just add it
            if (!was_founded)
                {contacts[hash].number=queries[i].number;
                    contacts[hash].name=queries[i].name;
                }
        } else if (queries[i].type == "del") {
            ll hash=gethash(queries[i].number);
                if (contacts[hash].number!=-1 && contacts[hash].number == queries[i].number) {
                    contacts[hash].name="";
                    contacts[hash].number=-1;
                   
                }
        } else {
            string response = "not found";
            ll hash=gethash(queries[i].number);
                if (contacts[hash].number!=-1 && contacts[hash].number == queries[i].number) {
                    response = contacts[hash].name;
                    
                }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
