#include <iostream>
#include <vector>

class UnionFind {
  private:
    // Parent vector to store the parent of each element
    vector<int> parent;
    vector<int> rank; // Rank vector to keep track of the tree height

  public:
    // Constructor to initialize the Union-Find structure with 'n' elements
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Rank is initially zero for all elements

        // Each element is its own parent initially (self loop)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the root of the set containing element 'x' (with path compression)
    int find(int x) {
        if (parent[x] != x) {
            // Path compression: make the parent of 'x' point directly to the
            // root
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union the sets containing elements 'x' and 'y' (with union by rank)
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank: attach smaller tree under the root of the larger
            // tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach rootY's tree under rootX
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY; // Attach rootX's tree under rootY
            } else {
                parent[rootY] = rootX; // Attach rootY under rootX and increment
                                       // rootX's rank
                rank[rootX]++;
            }
        }
    }

    // Check if two elements 'x' and 'y' belong to the same set
    bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    // Create a Union-Find structure with 7 elements (0 to 6)
    UnionFind uf(7);

    // Perform some union operations
    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);
    uf.unionSets(4, 5);
    uf.unionSets(6, 5);

    // Check if two elements are in the same set
    cout << "Are 0 and 2 in the same set? "
              << (uf.connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 3 and 6 in the same set? "
              << (uf.connected(3, 6) ? "Yes" : "No") << endl;

    // Perform a find operation (with path compression)
    cout << "Root of 6: " << uf.find(6) << endl;

    return 0;
}
