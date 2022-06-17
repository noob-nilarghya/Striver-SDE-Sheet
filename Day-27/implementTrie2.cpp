/*            [ MOST MOST IMPORTANT (considering all edge cases needed to be covered) ]                */

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
class Trie{

    public:
    TrieNode* root;
    unordered_map<string, int> m;
    Trie(){
        root= new TrieNode('\0');
    }
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
    void insert(string &word){
        m[word]++;
        if(m[word]==1){
            insertHelper(word, this->root);
        }
    }
   
    int countWordsEqualTo(string &word){
        if(m.count(word)>0){ // that word is existing in our trie
            return m[word];
        }
        return 0; // that word is not existing in our trie
    }
    TrieNode* lastNode(string word, TrieNode* root){
        // BASE CASE
        if(word.size()==0){
            return root;
        }
        char c=word[0]; int idx=c-'a';
        TrieNode* child;
        if((*root).children[idx] == NULL ){ return NULL; }
        child=(*root).children[idx];
        return lastNode(word.substr(1), child);
    }
    int cnt=0;
    void nodeToLeafPath(TrieNode* root, string output){
        
        if((*root).isTerminal==true){  // ye BASE CASE nhi hai
            // isTerminal true ka matlab ye nhi hai ki yhi pe trie khatam ho gya, iske neeche aur baccha ho skta hai
            cnt+= m[output];
        }
        for(int i=0; i<26; i++){
            TrieNode* child= (*root).children[i];
            if(child != NULL){
                nodeToLeafPath(child, output+(*child).data);
            }
        }
        return;
    }
    int countWordsStartingWith(string &word){
        TrieNode* endNode= lastNode(word, this->root);
        if(endNode == NULL){ return 0; }
        cnt=0; // reset
        nodeToLeafPath(endNode, word);
        return cnt;
    }
    void eraseHelper(string word, TrieNode* root){
        // BASE CASE
        if(word.size()==0){
            if((*root).isTerminal==false){
                return;
            }
            (*root).isTerminal=false;
        }
        if(word.size()>0){
            char c=word[0]; int idx=c-'a';
            TrieNode* child;
            if((*root).children[idx] == NULL){ return; }
            child=(*root).children[idx];
            eraseHelper(word.substr(1), child);
        
        
            // Age ka kaam base case ke baad karenge
            if((*root).children[idx]->isTerminal == false){
                TrieNode* baccha= (*root).children[idx];
                for(int i=0; i<26; i++){
                    if((*baccha).children[i] != NULL){ return; }
                }
                // baccha to me: mera isTerminal false hai aur mera sara baccha NULL hai, to mai is duniya me kaya kar rha hu ?
                delete(baccha);
                (*root).children[idx]=NULL;
            }
            else{ return; }
        }
    }
    void erase(string &word){
        if(m.count(word)>0){ // word we are wanting to delete is valid
            m[word]--;
            if(m[word]==0){ // no instance of word is remained
                m.erase(word);
                eraseHelper(word, this->root);
            }
        }
    }
};
