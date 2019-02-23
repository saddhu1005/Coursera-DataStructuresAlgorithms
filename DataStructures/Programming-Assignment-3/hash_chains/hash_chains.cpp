#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Query {
    string type, s;
    size_t ind;
};
struct data{
    list<string> s;
    
};

class QueryProcessor {
    ll bucket_count;
    // storing all strings in one vector
    vector<data> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (ll i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(ll bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        
        if (query.type != "check")
           cin >> query.s; 
            
        else
            cin >> query.ind;
        
        return query;
    }

    void writeSearchResult(bool was_found) const {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
         
        if (query.type == "check") {
            ll hash=query.ind;
             
            list<string> :: iterator itr;
            for(itr=(elems[hash].s).begin();itr!=(elems[hash].s).end();++itr){
                    
                    cout << *itr<< " ";
                }
            cout << "\n";
        } else {
            ll hash=hash_func(query.s);
            
            
           list<string> :: iterator itr=find((elems[hash].s).begin(),(elems[hash].s).end(),query.s);

            bool it=false;  
            if(itr!=(elems[hash].s).end())
                it=true;
            if (query.type == "find"){

                writeSearchResult(it);


            }
            else if (query.type == "add") {
                if (!it)
                    {   
                        (elems[hash].s).push_front(query.s);
                    }
            } else if (query.type == "del") {
                if (it)
                {

                 (elems[hash].s).erase(itr);
            
                }
            }   
        }
    }

    void processQueries() {
        elems.resize(bucket_count);
        ll n;
        cin >> n;
        for (ll i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    //ios_base::sync_with_stdio(false);
    ll bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
