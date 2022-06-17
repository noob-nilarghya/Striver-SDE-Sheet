//                        [ VERY IMPORANT ]
#include <bits/stdc++.h>

//-----------------Class Template same as maxXorOf2NumINArr---------------
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
//----------------------------------------------------------------------------

static bool comparator(vector<int>& v1, vector<int>& v2){
    return v1[1]<v2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &query){
	// QUERIES[i]’ = [‘Xi’, ‘Ai’],  maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.

    vector<int> ans(query.size(), -1);
    sort(arr.begin(), arr.end());
    for(int i=0; i<query.size(); i++){
        query[i].push_back(i); // query[i]={xi, ai, i}
    }
    sort(query.begin(), query.end(), comparator); // sort in increasing order of ai
    
    int idx=0; Trie t;
    for(int i=0; i<query.size(); i++){
        int xi=query[i][0]; int ai=query[i][1]; int index=query[i][2];
        
        while(idx<arr.size() && arr[idx]<= ai){
            t.insert(arr[idx]);
            idx++;
        }
        // Now trie would only contain ele less than ai. We can search through whole trie to get best num in trie to xor with xi to get max xor
        //--> Question boils down to: MaxXorOf2NumINArr

        if(idx==0){ // if there is no less no
            ans[index]=-1;
        }
        else{
            int reqNum= (~xi);
            int closestReqNum= t.search(reqNum);
            int mxXor=(xi^closestReqNum);
            ans[index]=mxXor;
        }
    }
    return ans;
}