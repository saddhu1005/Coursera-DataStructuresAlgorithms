#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

#define f(i, m) for(int i = 0; i < m; i++)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class DeBruijnGraph {
public:
  // k-mer size and threshold t
  DeBruijnGraph(int k, int t) : k_(k), t_(t), v_(0) {

  }

  void addRead(const string& r) {
    f(i, r.size() - k_ + 1) {
      string k_mer = r.substr(i, k_);
      if (edge_set.find(k_mer) == edge_set.end()) {
        edge_set.insert(k_mer);
        edges_.push_back(k_mer);
      }
    }
  }

  void setup() {

    // generate all vertices from k_mers
    for (auto edge : edges_) {
      string pre = edge.substr(0, edge.size() - 1);
      string suf = edge.substr(1);

      prefix_map.insert({pre, v_});

      if (vertix_map.find(pre) == vertix_map.end()) {
        vertices_.push_back(pre);
        vertix_map[pre] = v_++;
      }

      if (vertix_map.find(suf) == vertix_map.end()) {
        vertices_.push_back(suf);
        vertix_map[suf] = v_++;
      }
    }

    adj_list.resize(v_);

    f(i, edges_.size()) {
      string pre = edges_[i].substr(0, edges_[i].size() - 1);
      string suf = edges_[i].substr(1);
      int to_vertex_index = vertix_map[suf];
      int from_vertex_index = vertix_map[pre];
      adj_list[from_vertex_index].push_back(to_vertex_index);
    }
  }

  int countAllBubbles() {
    int cnt = 0;
    f(i, adj_list.size()) // go through every vertices
      if (adj_list[i].size() >= 2) // if has more than 2 outgoing vertices
        cnt += countAllBubblesFromSource(i, t_);
    return cnt;
  }

private:
  void getNonOvePaths(vi& path, set<int>& visited, vvi& allPaths, vector<set<int>>& allSets, int l) {
    if (path.size() == l) {
      allPaths.push_back(path);
      allSets.push_back(visited);
      return;
    }

    int s = path.back();

    if (adj_list[s].size() == 0) {
        allPaths.push_back(path);
        allSets.push_back(visited);
        return;
    }

    f(i, adj_list[s].size()) {
      int v = adj_list[s][i];

      if (visited.find(v) == visited.end()) {
        visited.insert(v);
        path.push_back(v);
        getNonOvePaths(path, visited, allPaths, allSets, l);
        path.pop_back();
        visited.erase(v);
      } else {
        continue;
      }
    }
  }

  string getPathStr(vi& leftPath, vi& rightPath, int merge) {
    string ret;
    for (auto& p : leftPath)
      if (p == merge) {
        ret += to_string(p);
        break;
      }
      else
        ret += to_string(p) + ",";

      ret += ";";

      for (auto& p : rightPath)
        if (p == merge) {
          ret += to_string(p);
          break;
        }
        else
          ret += to_string(p) + ",";

      return ret;
  }


  int countAllBubblesFromLeftRightPaths(vector<set<int>>& leftSet, vector<set<int>>& rightSet, vvi& leftPaths, vvi& rightPaths) {
      bool merged;
      set<string> mergePaths;

      for (int i = 0; i < leftSet.size(); i++) {
          auto& s = leftSet[i];
          for (auto& p : rightPaths) {
              merged = false;
              for (auto& v : p) {
                  if (s.find(v) != s.end()) {
                      merged = true;
                      string pathStr = getPathStr(leftPaths[i], p, v);
                      mergePaths.insert(pathStr);
                      break;
                  }
              }

              if (merged) continue;
          }
      }

      return mergePaths.size();
  }

  int countAllBubblesFromSource(int s, int t) {
    int count = 0;
    vi path;
    vvi leftPaths, rightPaths;
    vector<set<int>> leftSet, rightSet;
    set<int> visited;
    int nPath = adj_list[s].size();

    for (int i = 0; i < (nPath - 1); i++) {
        for (int j = i + 1; j < nPath; j++) {
            path.clear();
            leftPaths.clear();
            visited.clear();
            leftSet.clear();
            path.push_back(adj_list[s][i]);
            visited.insert(adj_list[s][i]);
            getNonOvePaths(path, visited, leftPaths, leftSet, t);

            path.clear();
            rightPaths.clear();
            visited.clear();
            rightSet.clear();
            path.push_back(adj_list[s][j]);
            visited.insert(adj_list[s][j]);
            getNonOvePaths(path, visited, rightPaths, rightSet, t);

            count += countAllBubblesFromLeftRightPaths(leftSet, rightSet, leftPaths, rightPaths);
        }
    }

    return count;
  }

  int k_;
  int t_;

  // edkges
  vector<string> edges_;
  set<string> edge_set;

  // vertices
  int v_;
  vector<string> vertices_;
  multimap<string, int> prefix_map;
  unordered_map<string, int> vertix_map; 

  // graph
  vvi adj_list;
};

int main(void) {
  int k, t;
  string read;

  cin >> k >> t;
  DeBruijnGraph graph(k, t);
  while (cin >> read) {
    graph.addRead(read);
  }

  graph.setup();

  cout << graph.countAllBubbles() << "\n";

  return 0;
}