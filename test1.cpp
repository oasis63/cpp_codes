#include<bits/stdc++.h>
using namespace std;

// lazy segment tree 

struct SegmentTree{
    vector<int> st;
    int n;

    void init(int _n){
        this->n = _n;
        st.resize(4*n, 0);
    }

    void buildUtil(int start, int ending, int node, vector<int> &v){
        
        // base case
        if(start == ending){
            st[node] = v[start];
            return;
        }

        // find mid, as we need to go to right and left subtree
        int mid = (start + ending)/2;

        // left subtree
        buildUtil(start, mid, 2*node+1, v);

        // right subtree
        buildUtil(mid+1,ending, 2*node+2, v);

        st[node] = st[2*node+1] + st[2*node+2];
    }

    int queryUtil(int start, int ending, int l, int r , int node){
        // non overlapping case
        if(start > r || ending < l){
            return 0;
        }

        // complete overlapping 
        if(start >= l && ending <= r){
            return st[node];
        }

        // partial case 
        int mid = (start + ending)/2;

        int q1 = queryUtil(start, mid, l , r, 2*node + 1);
        int q2 = queryUtil(mid+1, ending, l, r, 2*node + 2);

        return q1 + q2;
    }

    void updateUtil(int start, int ending, int node, int index, int value){
        if(start == ending){
            st[node] = value;
            return;
        }

        int mid = (start + ending)/2;

        if( index <= mid){
            updateUtil(start, mid, 2*node+1, index, value);
        }else{
            updateUtil(mid+1, ending, 2*node+2, index, value);
        }

        st[node] = st[2*node + 1] + st[2*node+2];

        return ;
    }

    void build(vector<int> &v){
        // buidling the tree from 0
        buildUtil(0, n-1, 0, v); 
    }

    int query(int l, int r){
        // start searching from 0th node
        return queryUtil(0,n-1, l, r, 0);
    }

    void update(int x,int y){
        updateUtil(0,n-1, 0, x, y);
    }
};

vector<int> solve(int n, vector<int>arr, vector<vector<int>> queries){
      
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
        int type = q[0];
        if(type == 1){
            tree.query(q[1],q[2]);
        }else{
            ans.push_back(tree.query(q[1],q[2]));
        }
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