// complete solution
#include <bits/stdc++.h>
using namespace std;

struct Clause {
    int firstVar;
    int secondVar;
};

struct TwoSatisfiability {
    int numVars;
    vector<Clause> clauses;
    vector<set<int> > sccs;

    TwoSatisfiability(int n, int m) :
        numVars(n),
        clauses(m)
    {  }
    

    void constructImplicationGraph(vector<vector<int> > &adj, vector<vector<int> > &adjR)
    {
        //vector<Clause> ::iterator it=clauses.begin(); it!=clauses.end(); ++it
        for (int i = 0; i < clauses.size(); ++i)
        {   Clause clause = clauses[i];
            int x, y, notX, notY;

            if (clause.firstVar > 0)
            {
                x = clause.firstVar - 1;
                notX = x + numVars;
            }
            else
            {
                x = -clause.firstVar - 1 + numVars;
                notX = x - numVars;
            }

            if (clause.secondVar > 0)
            {
                y = clause.secondVar - 1;
                notY = y + numVars;
            }
            else
            {
                y = -clause.secondVar - 1 + numVars;
                notY = y - numVars;
            }

            adj[notX].push_back(y);
            adj[notY].push_back(x);
            adjR[y].push_back(notX);
            adjR[x].push_back(notY);
        }
    }

    void dfs1(vector<vector<int>> &adj, bool *visited, int x, vector<int> &order)
    {
        for (int i=0; i<adj[x].size(); ++i)
        {   int nextX = adj[x][i];
            if (!visited[nextX])
            {
                visited[nextX] = true;
                dfs1(adj, visited, nextX, order);
                order.push_back(nextX);
            }
        }
    }

    void dfs2(vector<vector<int> > &adj, bool *visited, int x, set<int> &scc)
    {
        scc.insert(x);
        for (int i = 0; i < adj[x].size() ; ++i)
        {   int nextX = adj[x][i];
            if (!visited[nextX])
            {
                visited[nextX] = true;
                dfs2(adj, visited, nextX, scc);
            }
        }
    }

bool isSatisfiable(vector<int> &result)
{   set<int> ::iterator it;
    for (int i = 0; i<sccs.size(); ++i)
    {   set<int> scc = sccs[i];
        for (it = scc.begin();it!=scc.end(); ++it)
        {   int x = *it;
            if (scc.find(x + numVars) != scc.end() || scc.find(x - numVars) != scc.end())
                return false;
        }

    }

    for (int i = 0; i < result.size(); i++)
        result[i] = -1;
    for (int i = 0; i < sccs.size(); ++i)
    {
        set<int> scc = sccs[i];
        for (it = scc.begin(); it != scc.end(); ++it)
        {
            int i = *it;
            int x;
            bool isNegative;
            if (i >= numVars)
            {
                x = i - numVars;
                isNegative = true;
            }
            else
            {
                x = i;
                isNegative = false;
            }
            if (result[x] == -1)
            {
                if (isNegative)
                    result[x] = 1;
                else
                    result[x] = 0;
            }
        }
    }
    return true;
}

void setup()
{
    vector<vector<int> > adj(2 * numVars), adjR(2 * numVars);
    constructImplicationGraph(adj, adjR);
    vector<int> order ;
    bool *visited = new bool[2 * numVars];
    for(int i = 0; i < 2 * numVars; ++i)
        visited[i] = false;
    for (int i = 0; i < 2 * numVars; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs1(adjR, visited, i, order);
            order.push_back(i);
        }
    }
    reverse(order.begin(),order.end());
    for (int i = 0; i < adj.size(); i++)
        visited[i] = false;

    for (int i = 0; i < order.size(); ++i)
    {   int x = order[i];
        if (!visited[x])
        {
            set<int> scc;
            visited[x] = true;
            dfs2(adj, visited, x, scc);
            sccs.push_back(scc);
        }
    }
}
};
void run()
{
    int n, m;
    cin >>n >> m;

    TwoSatisfiability twoSat(n, m);
    int u, v;
    for (int i = 0; i < m; ++i)
    {   cin >> u >> v;
        twoSat.clauses[i].firstVar = u;
        twoSat.clauses[i].secondVar = v;
    }

    twoSat.setup();

    vector<int> result(n);
    if (twoSat.isSatisfiable(result))
    {
        cout << "SATISFIABLE\n";
        for (int i = 1; i <= n; ++i)
        {
            if (result[i - 1] == 1)
            {
                cout << -i; 
            }
            else
            {
                cout << i;
            }
            if (i < n)
            {
                cout << " ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
    else
    {
        cout << "UNSATISFIABLE\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    run();
    return 0;
}
