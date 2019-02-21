#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
struct Node
{
int key;
int vertex;
Node(int k=0,int v=0)
{
  key=k;
  vertex=v;
}
};
struct compare
{
  bool operator()(const Node &a,const Node &b)
  {   return a.key>b.key;
  }
};
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  priority_queue<Node,vector<Node> ,compare> pq;
  vector<int > dist;
  dist.resize(adj.size());
  for(int i=0;i<dist.size();++i)
    dist[i]=-1;
  vector<int> parent(adj.size());
  Node node;
 dist[s]=0;
 pq.push(Node(0,s));
 while(!pq.empty())
 {
  node=pq.top();
  pq.pop();
  if(node.key!=dist[node.vertex])
    continue;
  for(int u=0;u<adj[node.vertex].size();++u)
  { int v=adj[node.vertex][u];
    if(dist[v]==-1)
    {
      dist[v]=dist[node.vertex]+cost[node.vertex][u];
      parent[v]=node.vertex;
      pq.push(Node(dist[v],v));
    }
    else if(dist[v]>dist[node.vertex]+cost[node.vertex][u])
    {
      dist[v]=dist[node.vertex]+cost[node.vertex][u];
      pq.push(Node(dist[v],v));
      parent[v]=node.vertex;
    }
  }
 }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
