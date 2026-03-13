#include <iostream>
#include <vector>
#include <queue>
#include <climits>
 
using namespace std;
 
// each edge is represented as (neighbor, weight)
using Edge = pair<int, int>;
 
// adjacency list each index is a node, containing a list of its edges
using Graph = vector<vector<Edge>>;
 
vector<int> dijkstra(const Graph& adj, int src) {
    int V = adj.size();
 
    vector<int> dist(V, INT_MAX); // fill distances with infinity at the start
    dist[src] = 0; // distance from source to itself is 0
 
    // min-heap priority queue to select the edge with the smallest distance
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, src});
 
    // continue until all reachable nodes are processed
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        if (d > dist[u]) // if this distance is outdated (a better path was found), skip it
            continue;
 
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
 
    return dist;
}
 
void print_graph(const Graph& adj) {
    cout << "Graph (adjacency list):\n";
    for (int u = 0; u < (int)adj.size(); ++u) {
        for (auto [v, w] : adj[u]) {
            cout << u << " --(" << w << ")--> " << v << "\n";
        }
    }
}
 
int main() {
    Graph adj = {
        {{1, 2}, {2, 9}},
        {{0, 2}, {4, 7}, {2, 1}},
        {{0, 9}, {3, 5}, {1, 1}},
        {{2, 5}, {4, 11}},
        {{1, 7}, {3, 11}}
    };

    print_graph(adj);
    
    int src;
    cout << "Enter source node (0-" << adj.size() - 1 << "): ";
    cin >> src;

    if (src < 0 || src >= (int)adj.size()) {
    cout << "Invalid source node.\n";
    return 1;
    }

    vector<int> result = dijkstra(adj, src);
 
    cout << "\nSource node: " << src << "\n\n";
    cout << "Dijkstra's shortest path distances:\n";
    for (int i = 0; i < (int)result.size(); ++i) {
        if (i == src) continue;
        cout << "  " << src << " -> " << i << " distance is " << result[i] << "\n";
    }
 
    return 0;
}