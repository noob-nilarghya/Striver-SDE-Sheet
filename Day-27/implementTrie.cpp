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
    /* Initialize your data structure here. */
    Trie() {
        root= new TrieNode('\0'); // root node containing NULL terminating characer
    }

    /* Inserts a word into the trie. */
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

    /* Returns if the word is in the trie. */
    bool searchHelper(string word, TrieNode* root){
        //BASE CASE
        if(word.size()==0){
            if((*root).isTerminal==false){ return false; }
            return true;
        }
        char c= word[0]; int idx=c-'a';
        if((*root).children[idx] == NULL){ return false; }
        TrieNode* child=(*root).children[idx];
        return searchHelper(word.substr(1), child);
    }
    bool search(string word) {
        return searchHelper(word, this->root);
    }

    /* Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWithHelper(string prefix, TrieNode* root){
        // BASE CASE
        if(prefix.size()==0){
            return true;
        }
        char c= prefix[0]; int idx=c-'a';
        if((*root).children[idx] == NULL){ return false; }
        TrieNode* child= (*root).children[idx];
        return startsWithHelper(prefix.substr(1), child);
    }
    bool startsWith(string prefix) {
        return startsWithHelper(prefix, this->root);
    }
};