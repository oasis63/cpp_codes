void solve(BinaryTreeNode<int> *node, int input,int &temp)
{
    if(node){
        solve(node->left,input,temp);
        
        if(node->data == input){
            temp = input;
            return;
        }
        
        if(node->data < input){
            temp = node->data;
        }
        
        solve(node->right,input,temp);
    }
}


int Floor(BinaryTreeNode<int> *node, int input)
{
	int temp = -1;
    solve(node,input,temp);
    return temp;
}
