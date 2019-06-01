#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

#define f(i, m) for(int i = 0; i < m; i++)

class FlowGraph {
public:
	struct Edge {
		int from, to, capacity, flow;

		int getResidual() const {return capacity - flow;};
	};
	vector<Edge> edges;
	vector<vector<size_t> > graph;

	explicit FlowGraph(size_t n): graph(n) {}

	void add_edge(int from, int to, int capacity) {
		Edge forward_edge = {from, to, capacity, 0};
		Edge backward_edge = {to, from, 0, 0};
		graph[from].push_back(edges.size());
		edges.push_back(forward_edge);
		graph[to].push_back(edges.size());
		edges.push_back(backward_edge);
	}

	size_t size() const {
		return graph.size();
	}

	const vector<size_t>& get_ids(int from) const {
		return graph[from];
	}

	const Edge& get_edge(size_t id) const {
		return edges[id];
	}

  vector<bool> dfs_visited;
	bool dfs_path_helper(int vertex, int target, vector<int>& path, vector<size_t>& edgeIndices) {
    dfs_visited[vertex] = true;

		if (vertex < 0 || vertex >= graph.size()) {
			return false;
		}

		if (vertex == target) {
			path.push_back(vertex);
			return true;
		}

		vector<size_t> ids = get_ids(vertex);
		for (auto id : ids) {
			Edge e = edges[id];
			int residual_flow = 0;
      residual_flow = e.getResidual();
			if (residual_flow > 0) {
        if (!dfs_visited[e.to]) {
  				if (dfs_path_helper(e.to, target, path, edgeIndices)) {
  					path.push_back(vertex);
  					edgeIndices.push_back(id);
  					return true;
  				}
        }
			}
		}

		return false;
	}

	void dfs_path(vector<int>& path, vector<size_t>& edgeIndices, int start, int end) {
    dfs_visited.clear();
    dfs_visited = vector<bool>(graph.size(), false);
		dfs_path_helper(start, end, path, edgeIndices);
	}

	void add_flow(size_t id, int flow) {
		edges[id].flow += flow;
		edges[id ^ 1].flow -= flow; // toggles the first bit
	}
};

struct BitMatrix {
	bool* data;
	size_t s;
};

void BM_Init(BitMatrix& bm, int size) {
	bm.data = new bool[size * size];
  memset(bm.data, 0, size * size);
	bm.s = size;
}

void BM_Deinit(BitMatrix& bm) {
	delete bm.data;
	bm.s = 0;
}

void BM_Clear(BitMatrix& bm) {
	memset(bm.data, 0, bm.s * bm.s);
}

bool BM_Get(BitMatrix& bm, int row, int col) {
	return bm.data[row + col * bm.s];
}

void BM_Set(BitMatrix& bm, int row, int col, bool val) {
	bm.data[row + col * bm.s] = val;
}

int max_flow(FlowGraph& graph, int from, int to) {
	int flow = 0;
	BitMatrix edgeTracker;
	BM_Init(edgeTracker, graph.size());

	while(true) {
		vector<int> path;
		vector<size_t> edges;
		BM_Clear(edgeTracker);

		graph.dfs_path(path, edges, from, to);

		if (path.size() == 0) {
			return flow;
		}

		int min_cap = INT_MAX;
		for (auto eid : edges) {
			if (graph.get_edge(eid).getResidual() < min_cap) {
				min_cap = graph.get_edge(eid).getResidual();
			}
		}

		for (auto e_id : edges) {
			FlowGraph::Edge e = graph.get_edge(e_id);
			if (!BM_Get(edgeTracker, e.from, e.to)) {
				graph.add_flow(e_id, min_cap);
				BM_Set(edgeTracker, e.from, e.to, true);
			}
		}

		flow += min_cap;
	}

	return flow;
}

struct RawBoundedEdge {
  int u, v, l, c;
};

int main(void) {

	int n_vertices, n_edges;
	cin >> n_vertices >> n_edges;
	vector<RawBoundedEdge> raw_edges;
	vector<pair<int, int>> source_vertices;
	vector<pair<int, int>> sink_vertices;
	int total_demand = 0;

	f(i, n_edges) {
		RawBoundedEdge e;
		cin >> e.u >> e.v >> e.l >> e.c;
		e.u--;
		e.v--;
		raw_edges.push_back(e);
	}

	vector<int> t_out(n_vertices, 0);
	vector<int> t_in(n_vertices, 0);

	// find source and sink vertices
	for (auto& e : raw_edges) {
		t_out[e.u] += e.l;
		t_in[e.v] += e.l;
	}

	f(i, n_vertices) {
		if (t_out[i] == t_in[i]) continue;
		if (t_out[i] > t_in[i]) {
			sink_vertices.push_back({i, t_out[i] - t_in[i]});
			total_demand += (t_out[i] - t_in[i]);
		} else {
			source_vertices.push_back({i, t_in[i] - t_out[i]});
		}
	}


	// translate to max-flow problem
	int global_src = n_vertices;
	int global_snk = n_vertices + 1;
	FlowGraph fg(n_vertices + 2); // add global source and global sink
	// find source and sink vertices
	for (auto& e : raw_edges) {
		fg.add_edge(e.u, e.v, e.c - e.l);
	}

	for (auto& sc : source_vertices) {
		fg.add_edge(global_src, sc.first, sc.second);
	}

	for (auto& snk : sink_vertices) {
		fg.add_edge(snk.first, global_snk, snk.second);
	}


	if (total_demand != max_flow(fg, global_src, global_snk)) {
		cout << "NO" << endl;
		return 1;
	}


	f(i, n_edges) {
		RawBoundedEdge e = raw_edges[i];
		FlowGraph::Edge f_e = fg.edges[i * 2];
		raw_edges[i].l += f_e.flow;
	}

	// check edges are good or not
	fill(t_out.begin(), t_out.end(), 0);
	fill(t_in.begin(), t_in.end(), 0);

	for (auto& e : raw_edges) {
		t_out[e.u] += e.l;
		t_in[e.v] += e.l;
	}

	bool isbalanced = true;
	f(i, t_out.size()) {
		if (t_out[i] != t_in[i]) {
			isbalanced = false;
			break;
		}
	}

	for (auto& e : raw_edges) {
		if (e.l > e.c) {
			isbalanced = false;
			break;
		}
	}

	if (isbalanced) {
		cout << "YES" << endl;
		for (auto& e : raw_edges) {
			cout << e.l << endl;
		}
	} else {
		cout << "NO" << endl;
	}

  return 0;
}