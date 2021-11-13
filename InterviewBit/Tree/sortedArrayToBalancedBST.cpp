

TreeNode* helper(const vector<int>&A,int start,int end){
    
    if(start > end){
      return NULL;
    }
    
    int mid = (start + end)/2;

    TreeNode* root = new TreeNode(A[mid]);
    
    root->left = helper(A,start,mid-1);
    
    root->right = helper(A,mid+1,end);
    
    return root;
}

 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    if(A.size() == 0)
    return NULL;

    return helper(A,0,(int)A.size()-1);    
}