//                          [ VERY VERY IMPORTANT ]

#include <bits/stdc++.h>
// Left Boundary (without leaf node)
// Leaf node (basically do inOrder traversal & include only leaf nodes)
// Right boundary (without leaf node) [in reverse]

void leftBoundary(TreeNode<int>* root, vector<int>& ans){
    if(root==NULL){ return; }
    if((*root).left==NULL && (*root).right==NULL){ // if leaf --> return
        return;
    }
    ans.push_back((*root).data); // include the data
    leftBoundary((*root).left, ans); // go to left
    if((*root).left==NULL){ // If left is not available then move to right
        leftBoundary((*root).right, ans);
    }
    return;
}
void inOrderLeaf(TreeNode<int>* root, vector<int>& ans){
    if(root==NULL){ return; }
    inOrderLeaf((*root).left, ans);
    if((*root).left==NULL && (*root).right==NULL){ // only include the root if it is a leaf
        ans.push_back((*root).data);
    }
    inOrderLeaf((*root).right, ans);
    return;
}
void rightBoundary(TreeNode<int>* root, stack<int>& s){
    if(root==NULL){ return; }
    if((*root).left==NULL && (*root).right==NULL){ // if leaf --> return
        return;
    }
    s.push((*root).data); // include the data
    rightBoundary((*root).right, s); // go to right
    if((*root).right == NULL){ // If right is not available then move to left
        rightBoundary((*root).left, s);
    }
    return;
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans; ans.push_back((*root).data); // as root will always come in boundary traversal
    // as we included root, so we will only call other function by (*root).left OR (*root).right
    
    leftBoundary((*root).left, ans);
    inOrderLeaf((*root).left, ans);
    inOrderLeaf((*root).right, ans);
    stack<int> s;
    rightBoundary((*root).right, s);
    while(!s.empty()){ // to reverse the order
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}