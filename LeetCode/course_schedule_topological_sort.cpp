class Solution {
 public:
  stack<int> stk;

  bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
      for (int& v : adj[i]) {
        indegree[v]++;
      }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    // number of successfull processed nodes
    int count = 0;

    while (!q.empty()) {
      int t = q.front();
      q.pop();

      count++;
      for (int& v : adj[t]) {
        indegree[v]--;
        if (indegree[v] == 0) {
          q.push(v);
        }
      }
    }

    cout << "count : " << count << "  n : " << n << endl;

    return count != n;
  }

  void dfs(int src, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[src] = true;

    for (int& neigh : adj[src]) {
      if (!visited[neigh]) {
        dfs(neigh, visited, adj);
      }
    }

    stk.push(src);
  }

  vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    for (auto& p : prerequisites) {
      int u = p[0];
      int v = p[1];
      adj[v].push_back(u);
    }

    //

    bool cyclic = hasCycle(n, adj);

    cout << "cyclic : " << cyclic << endl;

    if (cyclic)
      return {};

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, visited, adj);
      }
    }

    int stkSize = stk.size();

    vector<int> elems;

    while (!stk.empty()) {
      elems.push_back(stk.top());
      stk.pop();
    }

    // cout << "" << endl;
    // for (int& elem : elems) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    return elems;
  }
};