
int Floor(BinaryTreeNode<int> *node, int input)
{
    if(node==NULL)
        return INT_MAX;
    
    if(node->data == input)
        return node->data;
    if(node->data > input)
        return Floor(node->left,input);
    
    int floor = Floor(node->right,input);
    
    // terminating call 
    return (floor <= input)?floor:node->data;
}
