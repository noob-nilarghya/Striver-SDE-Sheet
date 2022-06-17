#include <bits/stdc++.h>
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode** children;
    TrieNode(char c){
        this->data=c;
        this->isTerminal=false;
        children= new TrieNode*[26];
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};
class Trie {

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root= new TrieNode('\0'); // root node containing NULL terminating characer
    }

    /** Inserts a word into the trie. */
    void insertHelper(string word, TrieNode* root){
        // BASE CASE
        if(word.size()==0){
            (*root).isTerminal=true;
            return;
        }
        char c=word[0]; int idx=c-'a';
        TrieNode* child;
        if((*root).children[idx]==NULL){ // we need to make a new TrieNode
            child= new TrieNode(c);
            (*root).children[idx]=child;
        }
        else if((*root).children[idx]!=NULL){ // TrieNode with char c is already present
            child=(*root).children[idx];
        }
        insertHelper(word.substr(1), child);
    }
    void insert(string word) {
        insertHelper(word, this->root);
    }
    bool searchHelper(string word, TrieNode* root){
        //BASE CASE
        if(word.size()==0){
            if((*root).isTerminal==false){ return false; }
            return true;
        }
        char c= word[0]; int idx=c-'a';
        if((*root).children[idx] == NULL){ return false; }
        TrieNode* child=(*root).children[idx];
        // for every prefix of this string to be present in trie, we have to encounter isTerminal true for every child of that string, if it is not the case --> return FALSE 
        if((*child).isTerminal==false){ return false; }
        return searchHelper(word.substr(1), child);
    }
    bool search(string word) {
        return searchHelper(word, this->root);
    }
};

string completeString(int n, vector<string> &s){
    Trie t;
    for(int i=0; i<s.size(); i++){
        t.insert(s[i]);
    }
    int mxLen=INT_MIN; vector<string> vec;
    for(int i=0; i<n; i++){
        int len=0;
        bool a= t.search(s[i]);
        if(a==true){
            len=s[i].length();
            if(len==mxLen){
                vec.push_back(s[i]);
            }
            else if(len > mxLen){ // bigger length found
                vec.clear();
                mxLen=max(mxLen, len);
                vec.push_back(s[i]);
            }
        }
    }
    if(mxLen==INT_MIN){ return "None"; }
    sort(vec.begin(), vec.end()); // if multiple ans exist, it will sort the string in lexi order
    return vec[0];
}

