// Approach 1:

int binarySearch(BinaryTreeNode<int>* root, int key){
    if(root==NULL){
        return -1;
    }
    if((*root).data==key){
        return key;
    }
    else if(key < (*root).data){
        return binarySearch((*root).left, key);
    }
    return binarySearch((*root).right, key);
}

bool helper(BinaryTreeNode<int>* mainRoot,BinaryTreeNode<int>* root, int k){
    if(root==NULL){
        return false;
    }
    int a=(*root).data;
    int res= binarySearch(mainRoot, k-a);
    if(res != -1){ return true; }
    
    bool leftAns=helper(mainRoot, (*root).left, k);
    if(leftAns==true){ return true; }
    
    bool rightAns= helper(mainRoot, (*root).right, k);
    if(rightAns==true){ return true; }
    
    return false;
}

bool pairSumBst(BinaryTreeNode<int>* root, int k){
    return helper(root, root, k);
}
// Time Complexity: O(nlogn)
// Space Complexity: O(1)


// Approach 2: 

#include <bits/stdc++.h>

void helper(BinaryTreeNode<int>* root, int k, unordered_map<int, int>& m){
    if(root==NULL){
        return;
    }
    helper((*root).left, k, m);
    m[(*root).data]++;
    helper((*root).right, k, m);
}

bool pairSumBst(BinaryTreeNode<int>* root, int k){
    unordered_map<int, int> m;
    helper(root, k, m);
    
    for(auto it: m){
        int a=it.first;
        if(m.count(k-a)>0){ return true; }
    }
    return false;
}
// Time Complexity: O(n)
// Space Complexity: O(n)