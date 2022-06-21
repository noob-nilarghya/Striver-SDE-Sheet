vector<int>* pathHelper(TreeNode<int>* root, int x){
    if(root==NULL){
        return NULL;
    }
    if((*root).data==x){
        vector<int>* ans=new vector<int>(); (*ans).push_back((*root).data);
        return ans;
    }
    vector<int>* left=pathHelper((*root).left, x);
    if(left != NULL){
        (*left).push_back((*root).data);
        return left;
    }
    vector<int>* right=pathHelper((*root).right, x);
    if(right != NULL){
        (*right).push_back((*root).data);
        return right;
    }
    return NULL;
}

vector<int> pathInATree(TreeNode<int> *root, int x){
    vector<int>* ans=pathHelper(root, x);
    if(ans==NULL){ vector<int> vec; return vec; }
    reverse((*ans).begin(), (*ans).end());
    return *ans;
}
