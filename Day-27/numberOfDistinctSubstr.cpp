// NAIVE

#include <bits/stdc++.h>
int distinctSubstring(string &word) {
    set<string> s;
    for(int i=0; i<word.size(); i++){
        for(int j=i; j<word.size(); j++){
            s.insert(word.substr(i, (j-i+1)));
        }
    }
    return s.size();
}


// USING TRIE

#include <bits/stdc++.h>
class TrieNode{
    public:
    char data;
    TrieNode** children;
    TrieNode(char c){
        this->data=c;
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

    int cnt=0;
    /** Returns if the word is in the trie. */
    void searchHelper(TrieNode* root){
        for(int i=0; i<26; i++){
            if((*root).children[i] != NULL){
                cnt++;
                searchHelper((*root).children[i]);
            }
        }
    }
    int search() {
        cnt=0;
        searchHelper(this->root);
        return cnt;
    }
};

int distinctSubstring(string &word) {
    string s=word; Trie t;
    while(s.length() != 0){
        t.insert(s);
        s=s.substr(1);
    }
    return t.search();
}
