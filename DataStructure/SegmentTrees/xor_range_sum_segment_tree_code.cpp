#include<bits/stdc++.h>
using namespace std;



struct SegmentTree {
    int n;
    vector<int> st;

    void init(int _n) {
        n = _n;
        st.assign(4 * n, 0);
    }

    void buildUtil(int start, int end, int node, const vector<int>& v) {
        if (start == end) {
            st[node] = v[start];
            return;
        }

        int mid = (start + end) / 2;
        buildUtil(start, mid, 2 * node + 1, v);
        buildUtil(mid + 1, end, 2 * node + 2, v);

        st[node] = st[2 * node + 1] ^ st[2 * node + 2];
    }

    void build(const vector<int>& v) {
        buildUtil(0, n - 1, 0, v);
    }

    int queryUtil(int start, int end, int l, int r, int node) {
        if (r < start || l > end)
            return 0;

        if (l <= start && end <= r)
            return st[node];

        int mid = (start + end) / 2;
        int q1 = queryUtil(start, mid, l, r, 2 * node + 1);
        int q2 = queryUtil(mid + 1, end, l, r, 2 * node + 2);

        return q1 ^ q2;
    }

    int query(int l, int r) {
        return queryUtil(0, n - 1, l, r, 0);
    }

    void updateUtil(int start, int end, int node, int index, int value) {
        if (start == end) {
            st[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid)
            updateUtil(start, mid, 2 * node + 1, index, value);
        else
            updateUtil(mid + 1, end, 2 * node + 2, index, value);

        st[node] = st[2 * node + 1] ^ st[2 * node + 2];
    }

    void update(int index, int value) {
        updateUtil(0, n - 1, 0, index, value);
    }
};

vector<int>solve(int n, vector<int>a, vector<vector<int>> queries){
    
    SegmentTree tree;
    int sz = a.size();
    tree.init(sz);
    
    tree.build(a);
    
    vector<int> ans;
    
    for(vector<int> q : queries){
        ans.push_back(tree.query(q[0]-1,q[1]-1));
    }
    
    
    return ans;
}