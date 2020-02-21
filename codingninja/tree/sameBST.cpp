void inorder(BinaryTreeNode<int>* root,unordered_set<int> &s1){
    if(root){
        inorder(root->left,s1);
        s1.insert(root->data);
        inorder(root->right,s1);
    }
    
}

bool checkBSTs(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    
    if(!root1 && !root2){
        return true;
    }
   
    if((root1 == NULL && root2!=NULL) || (root1 != NULL &&root2 == NULL)){
        return false;
    }
    
    
    unordered_set<int> s1,s2;
    inorder(root1,s1);
    inorder(root2,s2);
    
    return (s1==s2);
}
