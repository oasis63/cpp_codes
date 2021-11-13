/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
void solve(TreeLinkNode* root){
    queue<TreeLinkNode*> currentLevel;
    queue<TreeLinkNode*> nextLevel;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        
        TreeLinkNode* temp = currentLevel.front();
        currentLevel.pop();
        temp->next = NULL;
        
        if(temp){
            if(temp->left)
                nextLevel.push(temp->left);
            if(temp->right)
                nextLevel.push(temp->right);
        }
        
        while(!currentLevel.empty()){
            TreeLinkNode* temp1 = currentLevel.front();
            currentLevel.pop();
            
            temp->next = temp1;

            
            temp = temp1;
            
            if(temp){
                // cout<<temp->val<<" ";
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            
        }
        
        if(currentLevel.empty()){
            swap(currentLevel,nextLevel);
        }
    }
}

 
 
void Solution::connect(TreeLinkNode* A) {
    solve(A);
}
