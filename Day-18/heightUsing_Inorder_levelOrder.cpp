//                    code Studio --> [ IMP QUESTION ]

// Less optimised. TC: O(N^2)
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





// MOST OPTIMISED: TC:O(N)
// Basically try to traverse in level order with the help of level order array. 
// While traversing, maintain start and end of inOrder index of the subtree you are currently in.
#include <bits/stdc++.h>

class Temp {
public:
    int height; // height of node [root ka height 0, leaf ka height is maximum]
    int leftIndex; // startIndex of subtree headed by node 
    int rightIndex; // endIndex of subtree headed by node 
    Temp(int h, int li, int ri) {
        height = h;
        leftIndex = li;
        rightIndex = ri;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    int maxHeight = 0;
    queue<Temp> q;

    Temp temp(0, 0, N - 1);
    q.push(temp);
    
    unordered_map<int, int> map; // {ele, inOrderIndex}
    for(int i = 0;i < N; i++) {
        map[inorder[i]] = i;
    }

    for(int i = 0;i < N; i++) {
        Temp temp = q.front();
        q.pop();

        maxHeight = max(temp.height, maxHeight);

        int li = temp.leftIndex;
        int ri = temp.rightIndex;
        int rootIndex;

        rootIndex = map[levelOrder[i]];

        if(rootIndex - 1 >= li) { // has left subtree
            Temp leftSubTree(temp.height + 1, li, rootIndex - 1);
            q.push(leftSubTree);
        }

        if(rootIndex + 1 <= ri) { // has right subtree
            Temp rightSubTree(temp.height + 1, rootIndex + 1, ri);
            q.push(rightSubTree);
        }
    }

    return maxHeight;
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