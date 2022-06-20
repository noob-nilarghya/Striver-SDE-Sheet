/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void helper(TreeNode* root, vector<int>& vec){
    if(root==NULL){
        return;
    }
    helper((*root).left, vec);
    helper((*root).right, vec);
    vec.push_back((*root).data);
    return;
}
vector<int> getPostOrderTraversal(TreeNode *root){
    vector<int> vec;
    helper(root, vec);
    return vec;
}