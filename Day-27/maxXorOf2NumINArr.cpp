class TrieNode{
    public:
    int data;
    TrieNode** children;
    TrieNode(int bit){
        data=bit;
        children= new TrieNode*[2];
        children[0]=NULL;  children[1]=NULL;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root= new TrieNode(-1);
    }
    void insertHelper(TrieNode* root, int num, int i){
        // BASE CASE
        if(i<0){ return; }
        
        int ithBit;
        if((num&(1<<i)) == 0){ ithBit=0; }
        else if((num&(1<<i)) != 0){ ithBit=1; }
        
        TrieNode* child;
        if((*root).children[ithBit] == NULL){
            child= new TrieNode(ithBit);
            (*root).children[ithBit]=child;
        }
        else if((*root).children[ithBit] != NULL){
            child=(*root).children[ithBit];
        }
        insertHelper(child, num, i-1);
    }
    void insert(int num){
        // prefix insertion
        insertHelper(this->root, num, 31);
    }
    int searchHelper(TrieNode* root, int reqNum, int i){
        //BASE CASE
        if(i<0){ return 0; }
        int ithBit;
        if( (reqNum&(1<<i)) == 0){ ithBit=0; }
        else if( (reqNum&(1<<i)) != 0){ ithBit=1; }
        int sum=0;
        TrieNode* child;
        if((*root).children[ithBit] == NULL){ // ithBit is not present
            if(ithBit==1){ ithBit=0; }
            else if(ithBit==0){ ithBit=1; }
            child=(*root).children[ithBit];
            sum+=(ithBit*(1<<i));
        }
        else if((*root).children[ithBit] != NULL){
            child=(*root).children[ithBit];
            sum+=(ithBit*(1<<i));
        }
        return sum+searchHelper(child, reqNum, i-1);
    }
    int search(int reqNum){
        return searchHelper(this->root, reqNum, 31);
    }
};

int maximumXor(vector<int> A){
    Trie t;
    for(int i=0; i<A.size(); i++){
        t.insert(A[i]);
    }
    int Xor=0;
    for(int i=0; i<A.size(); i++){
        int reqNum= (~A[i]);
        int closestReqNum= t.search(reqNum);
        Xor= max(Xor, (A[i]^closestReqNum));
    }
    return Xor;
}