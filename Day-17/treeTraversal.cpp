// 3 Traversal (Normal Way - any one can do !)

vector<int> in; vector<int> pre; vector<int> post;

void inOrder(BinaryTreeNode<int>* root){
    if(root==NULL){  return;  }
    inOrder((*root).left);
    in.push_back((*root).data);
    inOrder((*root).right);
    return;
}

void preOrder(BinaryTreeNode<int>* root){
    if(root== NULL){ return; }
    pre.push_back((*root).data);
    preOrder((*root).left);
    preOrder((*root).right);
    return;
}

void postOrder(BinaryTreeNode<int>* root){
    if(root== NULL){ return; }
    postOrder((*root).left);
    postOrder((*root).right);
    post.push_back((*root).data);
    return;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    in.clear(); pre.clear(); post.clear();
    inOrder(root);
    preOrder(root);
    postOrder(root);
    vector<vector<int>> ans;
    ans.push_back(in); ans.push_back(pre); ans.push_back(post);
    return ans;
}

//-------------------------------------------------------------------------------

// Single Traversal ( VERY IMP fot interview point of view )

#include <bits/stdc++.h>

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(root==NULL){ vector<vector<int>> ans; return ans; }
    
    vector<int> in, pre, post;
    stack<pair<BinaryTreeNode<int>*, int>> s;
    
    s.push({root,1});
    while(!s.empty()){
        pair<BinaryTreeNode<int>*, int> p=s.top(); s.pop();
        int num=p.second; BinaryTreeNode<int>* front=p.first;
        
        if(num==1){
            pre.push_back((*front).data);
            s.push({front, num+1});
            if((*front).left != NULL){
                s.push({(*front).left, 1});
            }
        }
        else if(num==2){
            in.push_back((*front).data);
            s.push({front, num+1});
            if((*front).right != NULL){
                s.push({(*front).right, 1});
            }
        }
        else if(num==3){
            post.push_back((*front).data);
        }
    }
    vector<vector<int>> ans; ans.push_back(in); ans.push_back(pre); ans.push_back(post);
    return ans;
}