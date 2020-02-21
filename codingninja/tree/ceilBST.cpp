
int Ceil(BinaryTreeNode<int> *node, int input)
{
    if(node==NULL)
        return -1;
    if(node->data == input)
        return node->data;
    if(node->data < input)
        return Ceil(node->right,input);
    
    int ceil = Ceil(node->left,input);
    
    // terminating call 
    return (ceil > input)?ceil:node->data;
}
