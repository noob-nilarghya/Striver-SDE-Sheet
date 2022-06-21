#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root) {
    if(root==NULL){ vector<int> vec; return vec; }
    
    queue<pair<TreeNode<int>*, int>> q;
    map<int, int> m;
    
    q.push({root, 0});
    while(!q.empty()){
        pair<TreeNode<int>*, int> p=q.front(); q.pop();
        int vertical=p.second; TreeNode<int>* front=p.first;
        if(m.count(vertical)==0){ // we only want firt entry corresponding to each vertical (unlike bottom view)
            m[vertical]=(*front).val;
        }
        
        if((*front).left != NULL){
            q.push({(*front).left, vertical-1});
        }
        if((*front).right != NULL){
            q.push({(*front).right, vertical+1});
        }
    }
    
    vector<int> ans;
    for(auto it : m){
        ans.push_back(it.second);
    }
    return ans;
}

