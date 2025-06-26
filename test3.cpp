// ...TOPOLOGICAL SORT
#include <bits/stdc++.h>
using namespace std;

/*
    In topological sort

    Each node comes before all the nodes to which it has outgoing edges.

*/

class Graph {
  int vertices;
  vector<int> *adj;
  stack<int> topoStack;

  void dfsUtil(int src, bool *visited);
  void topoDfs(int src, bool *visited);

 public:
  Graph(int v) {
    vertices = v;
    adj = new vector<int>[v];
  }

  void addEdge(int src, int dest);
  void printGraph();
  void dfs(int src);
  void bfs(int src);
  void topologicalSort();
};

void Graph::addEdge(int src, int dest) {
  adj[src].push_back(dest);  // Directed Graph
}

void Graph::printGraph() {
  for (int i = 0; i < vertices; i++) {
    cout << "\nNode : " << i << endl;
    cout << "....Its children are" << endl;

    for (int j = 0; j < adj[i].size(); j++) {
      cout << adj[i][j] << " ";
    }
  }

  cout << endl;
}

void Graph::bfs(int src) {
  bool *visited = new bool[vertices];
  for (int i = 0; i < vertices; i++) visited[i] = false;

  queue<int> q;  // contains the visited node values
  q.push(src);

  while (!q.empty()) {
    int value = q.front();
    q.pop();
    cout << value << " ";

    // printing all the children of the node value
    for (int i = 0; i < adj[value].size(); i++) {
      if (!visited[adj[value][i]]) {
        visited[adj[value][i]] = true;
        q.push(adj[value][i]);
      }
    }
  }

  cout << endl;
}

void Graph::dfsUtil(int src, bool *visited) {
  visited[src] = true;

  cout << src << " ";

  for (int i = 0; i < adj[src].size(); i++) {
    if (!visited[adj[src][i]]) {
      dfsUtil(adj[src][i], visited);
    }
  }
}

void Graph::dfs(int src) {
  bool *visited = new bool[vertices];

  for (int i = 0; i < vertices; i++) {
    visited[i] = false;
  }

  dfsUtil(src, visited);
}

/*
    In topological sort
    Each node comes before all the nodes to which it has outgoing edges.
    So we have to reach to the node which has no children and push
    to a stack
*/

void Graph::topoDfs(int src, bool *visited) {
  visited[src] = true;

  for (int i = 0; i < adj[src].size(); i++) {
    if (!visited[adj[src][i]]) {
      // dfsUtil(adj[src][i],visited);
      topoDfs(adj[src][i], visited);
    }
  }

  topoStack.push(src);
  // visited[src] = true;
}

void Graph::topologicalSort() {
  bool *visited = new bool[vertices];

  for (int i = 0; i < vertices; i++) visited[i] = false;

  for (int i = 0; i < vertices; i++) {
    if (!visited[i]) {
      // cout<<"Executed"<<endl;
      topoDfs(i, visited);
    }
  }

  /*for(int i=0;i<vertices;i++)
      cout<<visited[i]<<" ";

  cout<<endl;*/

  int sizeOfStack = topoStack.size();

  // cout<<"\nSize of the stack : "<<sizeOfStack<<endl;

  for (int i = 0; i < sizeOfStack; i++) {
    cout << topoStack.top() << " ";
    topoStack.pop();
  }
}

int main() {
  Graph graph(6);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(4, 2);
  graph.addEdge(4, 5);
  // graph.addEdge(5,4);
  graph.addEdge(5, 2);

  graph.printGraph();

  cout << "\n====BFS====" << endl;

  graph.bfs(0);

  cout << "\n====DFS====" << endl;

  graph.dfs(0);

  cout << "\n====Topological Sort====" << endl;

  graph.topologicalSort();

  cout << endl;
  return 0;
}