
TreeNode<int>* helper(vector<int>& arr, int start, int end){
    if(start>end){
        return NULL;
    }

    int mid=start+(end-start)/2;
    TreeNode<int>* newNode= new TreeNode<int>(arr[mid]);
    
    TreeNode<int>* leftTree= helper(arr, start, mid-1);
    TreeNode<int>* rightTree= helper(arr, mid+1, end);
    (*newNode).left=leftTree; (*newNode).right=rightTree;
    
    return newNode;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n){
    return helper(arr, 0, n-1);
}