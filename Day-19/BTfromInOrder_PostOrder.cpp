
TreeNode<int>* helper(vector<int>& postOrder, int postS, int postE, vector<int>& inOrder, int inS, int inE){
    if(postS>postE || inS>inE){
        return NULL;
    }
    
    int leftPostS=postS;
    int leftPostE;
    int rightPostS;
    int rightPostE=postE-1;
    
    int leftInS=inS;
    int leftInE;
    int rightInS;
    int rightInE=inE;
    
    int root= postOrder[postE];
    TreeNode<int>* newNode= new TreeNode<int>(root);
    
    int idx=inS; int len=0;
    while(idx<inE && inOrder[idx]!=root){
        idx++;
        len++;
    }
    // inOrder[idx]==root
    leftInE=idx-1;
    rightInS=idx+1;
    leftPostE=postS+len-1;
    rightPostS=leftPostE+1;
    
    TreeNode<int>* leftTree= helper(postOrder, leftPostS, leftPostE, inOrder, leftInS, leftInE);
    TreeNode<int>* rightTree= helper(postOrder, rightPostS, rightPostE, inOrder, rightInS, rightInE);
    (*newNode).left=leftTree; (*newNode).right=rightTree;
    
    return newNode;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
	return helper(postOrder, 0, postOrder.size()-1, inOrder, 0, inOrder.size()-1);
}
