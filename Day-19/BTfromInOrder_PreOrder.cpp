
TreeNode<int>* helper(vector<int> &inOrder, int inS, int inE, vector<int> &preOrder, int preS, int preE){
    if(inS>inE || preS>preE){
        return NULL;
    }
    int leftInS=inS;
    int leftInE;
    int rightInS;
    int rightInE=inE;
    
    int leftPreS=preS+1;
    int leftPreE;
    int rightPreS;
    int rightPreE=preE;
    
    int root=preOrder[preS];
    TreeNode<int>* newNode=new TreeNode<int>(root);
    int idx=inS; int len=0;
    while(idx<inE && inOrder[idx] != root){
        len++;
        idx++;
    }
    // inOrder[idx]==root;
    
    leftInE=idx-1; 
    rightInS=idx+1;
    leftPreE=preS+len;
    rightPreS=leftPreE+1;
    
    TreeNode<int>* leftTree= helper(inOrder, leftInS, leftInE, preOrder, leftPreS, leftPreE);
    TreeNode<int>* rightTree= helper(inOrder, rightInS, rightInE, preOrder, rightPreS, rightPreE);
    (*newNode).left=leftTree; (*newNode).right=rightTree;
    
    return newNode;
}

TreeNode<int> *buildBinaryTree(vector<int> &inOrder, vector<int> &preOrder){
	return helper(inOrder, 0, inOrder.size()-1, preOrder, 0, preOrder.size()-1);
}