//                    code Studio --> [ IMP QUESTION ]
#include <bits/stdc++.h>

int helper(vector<int>& inOrder, int inS, int inE, vector<int>& levelOrder, int levS, int levE){
    if(inS>inE || levS>levE){
        return -1;
    }
    int root=levelOrder[levS];
    if(inOrder[inS]==root){ // No left subtree --> go to right
        return 1+helper(inOrder, inS+1, inE, levelOrder, levS+1, levE);
    }
    else if(inOrder[inE]==root){ // no right subtree --> go to left
        return 1+helper(inOrder, inS, inE-1, levelOrder, levS+1, levE);
    }
    int idx=inS;
    while(inOrder[idx] != root){
        idx++;
    }
    // Now inOrder[idx]==root;
    unordered_map<int, int> leftMP; // freq of left subtree in Inorder
    unordered_map<int, int> rightMP; // freq of right subtree in Inorder
    for(int i=inS; i<=idx-1; i++){
        leftMP[inOrder[i]]++;
    }
    for(int i=idx+1; i<=inE; i++){
        rightMP[inOrder[i]]++;
    }
    vector<int> leftLevelOrder; vector<int> rightLevelOrder;
    for(int i=levS; i<=levE; i++){
        if(leftMP.count(levelOrder[i])>0){ leftLevelOrder.push_back(levelOrder[i]); }
        else if(rightMP.count(levelOrder[i])>0){ rightLevelOrder.push_back(levelOrder[i]); }
    }
    
    int a= helper(inOrder, inS, idx-1, leftLevelOrder, 0, leftLevelOrder.size()-1);
    int b= helper(inOrder, idx+1, inE, rightLevelOrder, 0, rightLevelOrder.size()-1);
    return 1+max(a,b);
}
int heightOfTheTree(vector<int>& inOrder, vector<int>& levelOrder, int N){
	return helper(inOrder, 0, N-1, levelOrder, 0, N-1);
}

//--------------------------------------------------------------------------------------------------
// LeetCode -> Normal recursive algo to find height

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int a= maxDepth((*root).left);
        int b= maxDepth((*root).right);
        return max(a,b)+1;
    }
};