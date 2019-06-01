# python3


class Edge:

    def __init__(self, u, v, capacity):
        self.u = u
        self.v = v
        self.capacity = capacity
        self.flow = 0

# This class implements a bit unusual scheme for storing edges of the graph,
# in order to retrieve the backward edge for a given edge quickly.


class FlowGraph:

    def __init__(self, n):
        # List of all - forward and backward - edges
        self.edges = []
        # These adjacency lists store only indices of edges in the edges list
        self.graph = [[] for _ in range(n)]

    def add_edge(self, from_, to, capacity):
        # Note that we first append a forward edge and then a backward edge,
        # so all forward edges are stored at even indices (starting from 0),
        # whereas backward edges are stored at odd indices.
        forward_edge = Edge(from_, to, capacity)
        backward_edge = Edge(to, from_, 0)
        self.graph[from_].append(len(self.edges))
        self.edges.append(forward_edge)
        self.graph[to].append(len(self.edges))
        self.edges.append(backward_edge)

    def size(self):
        return len(self.graph)

    def get_ids(self, from_):
        return self.graph[from_]

    def get_edge(self, id):
        return self.edges[id]

    def add_flow(self, id, flow):
        # To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
        # due to the described above scheme. On the other hand, when we have to get a "backward"
        # edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
        # should be taken.
        #
        # It turns out that id ^ 1 works for both cases. Think this through!
        self.edges[id].flow += flow
        self.edges[id ^ 1].flow -= flow


def bipartite_graph(adj_matrix):
    n = len(adj_matrix)
    m = len(adj_matrix[0])
    vertex_count = n + m + 2
    graph = FlowGraph(vertex_count)
    for _ in range(1, n + 1):
        u, v, capacity = 0, _, 1
        graph.add_edge(u, v, capacity)
    for i in range(n):
            for j in range(m):
                if adj_matrix[i][j] :
                    u, v, capacity = i + 1, n + j + 1, 1
                    graph.add_edge(u, v, capacity)
    for _ in range(1, m + 1):
        u, v, capacity = n + _, n + m + 1, 1
        graph.add_edge(u, v, capacity)
    return graph


def max_flow(graph, from_, to):
    # your code goes here
    while True:
        # print('stps')
        q = []
        q.append(from_)
        visited = [False] * graph.size()
        minedge = 10 ** 5
        parent = [(None, None)] * graph.size()
        parent[from_] = (from_, -1)
        visited[from_] = True
        path_found = False
        while q and not path_found:
            s = q.pop(0)
            ids = graph.get_ids(s)
            for id in ids:
                edge = graph.get_edge(id)
                if not visited[edge.v] and edge.flow < edge.capacity:
                    visited[edge.v] = True
                    parent[edge.v] = (edge.u, id)
                    q.append(edge.v)
                    minedge = min(minedge, edge.capacity-edge.flow)
                    if edge.v == to:
                        path_found = True
                        break
        if not path_found:
            break
        s = to
        u, id = parent[s]
        while s is not from_:
            graph.add_flow(id, minedge)
            s = u
            u, id = parent[s]

    return graph.edges


class MaxMatching:
    def read_data(self):
        n, m = map(int, input().split())
        adj_matrix = [list(map(int, input().split())) for i in range(n)]
        return adj_matrix

    def write_response(self, matching):
        line = [str(-1 if x == -1 else x + 1) for x in matching]
        print(' '.join(line))

    def find_matching(self, adj_matrix):
        # Replace this code with an algorithm that finds the maximum
        # matching correctly in all cases.
        n = len(adj_matrix)
        m = len(adj_matrix[0])
        matching = [-1] * n
        graph = bipartite_graph(adj_matrix)
        edges = max_flow(graph, 0, n + m + 1)
        start, end =2 * n, len(edges) - m * 2
        for id in range(start, end, 2):
            edge = edges[id]
            u, v = edge.u - 1, edge.v - n - 1
            if edge.flow == edge.capacity:
                matching[u] = v

        '''
        busy_right = [False] * m
        for i in range(n):
            for j in range(m):
                if adj_matrix[i][j] and matching[i] == -1 and (not busy_right[j]):
                    matching[i] = j
                    busy_right[j] = True
        '''
        return matching

    def solve(self):
        adj_matrix = self.read_data()
        matching = self.find_matching(adj_matrix)
        self.write_response(matching)

if __name__ == '__main__':
    max_matching = MaxMatching()
    max_matching.solve()
