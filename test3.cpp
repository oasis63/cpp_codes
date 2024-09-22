//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> primes{2, 3};
    bool isPrime(int n) {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    void precompute() {
        for (int i = 4; i < 10001; i++) {
            if (isPrime(i))
                primes.push_back(i);
        }
    }

    void dfsUtil(vector<vector<int>> &g, int src, vector<bool> &visited,
                 int &maxConnect, int currCount) {

        cout << " src : " << src << "  ";
        visited[src] = true;

        // cout << src << "  ";

        // currCount++;
        // maxConnect = max(maxConnect, currCount);
        for (int elem : g[src - 1]) {
            if (!visited[elem - 1])
                dfsUtil(g, elem, visited, maxConnect, currCount);
        }
    }

    int dfs(vector<vector<int>> &g, int n, int m) {
        int maxConnect = 0;

        // for (int i = 0; i < n; i++) {
        vector<bool> visited(n + m, false);
        dfsUtil(g, 0, visited, maxConnect, 0);
        // }
        return maxConnect;
    }

    int helpSanta(int n, int m, vector<vector<int>> &g) {
        // Code here
        int maxConnection = dfs(g, n, m);
        cout << "maxConnection : " << maxConnection << endl;
        return primes[maxConnection - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t = 2;
    Solution ob;
    // ob.precompute();
    // while (t--) {
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> g;

    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        cout << " u " << u << " v : " << v << endl;
        // g.push_back({u, v});
        // 			g[u].push_back(v);
        // 			g[v].push_back(u);
    }
    int ans = ob.helpSanta(n, e, g);
    cout << "\n ans : " << ans << endl;
    // }
}
