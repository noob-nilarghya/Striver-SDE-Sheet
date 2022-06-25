#include <bits/stdc++.h>
#include <sstream>

string intToString(int k){   stringstream nil;   nil<<k;   string s;  nil>>s;  return s;  }
int stringToInt(string s){   stringstream nil(s);  int x = 0;   nil >> x;   return x;  }

string serializeTree(TreeNode<int>* root){
    string s="";
    if(root==NULL){
        return s;
    }
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* front=q.front(); q.pop();
        if(front==NULL){
            s.push_back('#'); 
            s.push_back(',');
        }
        else{ 
            int data=(*front).data;
            string eqData=intToString(data);
            s=s+eqData;
            s.push_back(',');
        }

        if(front != NULL){
            if((*front).left != NULL){
                q.push((*front).left);
            }
            else{ q.push(NULL); }

            if((*front).right != NULL){
                q.push((*front).right);
            }
            else{ q.push(NULL); }
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string& s){
    if(s==""){
        return NULL;
    }
    int idx=0;
    while(s[idx]!=','){ idx++; }
    string temp=s.substr(0,idx); int dat=stringToInt(temp);
    idx++; // to eliminate ','
    TreeNode<int>* root= new TreeNode<int>(dat);
    queue<TreeNode<int>*> q;  q.push(root);


    while(!q.empty() && idx!=s.length()){
        TreeNode<int>* front=q.front(); q.pop();

        TreeNode<int>* leftNode;
        if(s[idx]!='#'){
            int i=idx;
            while(s[idx]!=','){ idx++; }
            string temp=s.substr(i,idx-i); int dat=stringToInt(temp);
            idx++; // to eliminate ','
            leftNode= new TreeNode<int>(dat);
            (*front).left=leftNode;
            q.push(leftNode);
        }
        else if(s[idx]=='#'){ idx+=2; } // to eliminate '#' and then ','

        TreeNode<int>* rightNode;
        if(s[idx]!='#'){
            int i=idx;
            while(s[idx]!=','){ idx++; }
            string temp=s.substr(i,idx-i); int dat=stringToInt(temp);
            idx++; // to eliminate ','
            rightNode= new TreeNode<int>(dat);
            (*front).right=rightNode;
            q.push(rightNode);
        }
        else if(s[idx]=='#'){ idx+=2; } // to eliminate '#' and then ','
    }
    return root;
}




