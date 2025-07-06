#include<bits/stdc++.h>
using namespace std;


// summation
struct SegmentTree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void buildUtil(int start, int ending, int node, vector<int> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		buildUtil(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		buildUtil(mid + 1, ending, 2 * node + 2, v);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	int queryUtil(int start, int ending, int l, int r, int node) {
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;

		int q1 = queryUtil(start, mid, l, r, 2 * node + 1);
		int q2 = queryUtil(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void updateUtil(int start, int ending, int node, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			updateUtil(start, mid, 2 * node + 1, index, value);
		}
		else {
			// right
			updateUtil(mid + 1, ending, 2 * node + 2, index, value);
		}

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<int> &v) {
		buildUtil(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return queryUtil(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		updateUtil(0, n - 1, 0, x, y);
	}
};

vector<int>solve(int n, vector<int>a, vector<vector<int>> queries){
    
    SegmentTree tree;
    
    int sz = a.size();

    tree.init(sz);
    
    tree.build(a);
    
    cout<<"build segment tree" <<endl;
    for(int i : tree.st){
        cout<< i<<  "   ";
    }
    cout<<endl;
    
    vector<int> ans;
    
    for(vector<int> q : queries){
        ans.push_back(tree.query(q[0],q[1]));
    }
    
    
    return ans;
}


int main(){

    int n = 5;
    // vector<int> nums  = {3, 2, 4, 5, 1, 1, 5, 3};
    vector<int> nums  = {1,2,3,4,5,6};

    cout<<"input array :" << endl;
    for(int i : nums){
        cout<<i<<"  ";
    }
    cout<<endl;

    // vector<vector<int>> queries = {
    //     {2, 4},
    //     // {5, 6},
    //     // {1, 8},
    //     // {3, 3}
    // };


     vector<vector<int>> queries = {
        {2, 4},
        {4,5},
        {1, 3},
        {2,5}
    };

    vector<int> ans = solve(n, nums, queries);

    for(int j=0;j<ans.size();j++){
        cout<<queries[j][0] << "   " << queries[j][1]  << " ---> " << ans[j]<<endl;
    }
    

    return 0;
}