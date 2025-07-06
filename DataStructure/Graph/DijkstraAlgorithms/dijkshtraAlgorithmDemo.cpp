#include <bits/stdc++.h>
using namespace std;

// Alias for readability: {weight, node}
typedef pair<int, int> PII;

vector<int> dijkstra(int start, int V, vector<vector<PII>>& adj) {
  // Distance array, initialize all distances as infinity
  vector<int> dist(V, INT_MAX);
  dist[start] = 0;

  // Min-heap priority queue: {distance, node}
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int currDist = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    // Explore neighbors
    for (auto& [weight, v] : adj[u]) {
      if (dist[v] > currDist + weight) {
        dist[v] = currDist + weight;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}

int main() {
  int V = 5;  // Number of nodes (0 to 4)
  vector<vector<PII>> adj(V);

  // Example graph (undirected for simplicity)
  // edge: u --(w)--> v
  adj[0].push_back({2, 1});
  adj[0].push_back({4, 2});
  adj[1].push_back({1, 2});
  adj[1].push_back({7, 3});
  adj[2].push_back({3, 3});
  adj[3].push_back({1, 4});
  adj[2].push_back({5, 4});

  int start = 0;
  vector<int> distances = dijkstra(start, V, adj);

  cout << "Shortest distances from node " << start << ":\n";
  for (int i = 0; i < V; ++i) {
    cout << "To node " << i << " = " << distances[i] << endl;
  }

  return 0;
}
