#include <bits/stdc++.h>
using namespace std; 

class TrieNode{
    public:
    char data; bool isTerminal; TrieNode** children; int cnt;
    TrieNode(char c){
        this->data=c; this->isTerminal=false; cnt=1; children= new TrieNode*[26];
        for(int i=0; i<26; i++){  children[i]=NULL;  }
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){  root= new TrieNode('\0'); }
    void insertHelper(TrieNode* root, int idx, string& word){
        if(idx>=word.size()){
            (*root).isTerminal=true;
            return;
        }
        char c=word[idx]; int index=(int)(c-'a'); TrieNode* child;
        if((*root).children[index]==NULL){ // we need to make a new TrieNode
            child= new TrieNode(c);
            (*root).children[index]=child;
        }
        else if((*root).children[index]!=NULL){ // TrieNode with char c is already present
            child=(*root).children[index];
            child->cnt++;
        }
        insertHelper(child, idx+1, word);
    }
    void insert(string &word){  insertHelper(this->root, 0, word);  }

    string ans="";
    void helperHelp(TrieNode* root, int idx, string& str, int n){
        if(idx>=str.size()){ return; }

        int index= (int)(str[idx]-'a');
        TrieNode* child= root->children[index];
        if(child==NULL || child->cnt!=n){ return; }
        ans.push_back(child->data);
        helperHelp(child, idx+1, str, n);
        return;
    }
    string helper(string& str, int n){
        ans="";
        helperHelp(this->root, 0, str, n);
        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie t; 
    for(int i=0; i<arr.size(); i++){
        t.insert(arr[i]);
    }
    return t.helper(arr[0], n);
}


