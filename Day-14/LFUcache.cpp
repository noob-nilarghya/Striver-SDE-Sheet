#include <bits/stdc++.h>

class Node{
    public:
    int key; int value; int frequency;
    Node* next; Node* prev;
    Node(int key, int val){
        this->key=key;
        this->value=val;
        frequency=1;
        next=NULL; prev=NULL;
    }
};

class DLL{
    public:
    Node* dummyHead;
    Node* dummyTail;
    int size;
    DLL(){
        dummyHead=new Node(-1, -1);
        dummyTail=new Node(-1, -1);
        (*dummyHead).next=dummyTail;
        (*dummyTail).prev=dummyHead;
        size=0;
    }
    void insert(Node* newNode){ // insert node right after dummyHead
        Node* headNxt=(*dummyHead).next;
        (*dummyHead).next=newNode;
        (*newNode).prev=dummyHead;
        (*newNode).next=headNxt;
        (*headNxt).prev=newNode;
        size++;
    }
    void remove(Node* delNode){ // remove node from any position
        Node* delPrev=(*delNode).prev;
        Node* delNxt=(*delNode).next;
        (*delPrev).next=delNxt;
        (*delNxt).prev=delPrev;
        (*delNode).next=NULL; (*delNode).prev=NULL;
        size--;
    }
    Node* removeEnd(){ // remove node from last (right before dummyTail)
        Node* delNode=(*dummyTail).prev;
        Node* delPrev=(*delNode).prev;
        (*delPrev).next=dummyTail;
        (*dummyTail).prev=delPrev;
        (*delNode).next=NULL; (*delNode).prev=NULL;
        size--;
        return delNode;
    }
};

class LFUCache{
public:
    unordered_map<int, Node*> m;
    unordered_map<int, DLL*> freq;
    int size;
    int capacity;
    int minFreq;
    LFUCache(int capacity){
        size=0;
        minFreq=0;
        this->capacity=capacity;
    }
    void updateNode(Node* reqNode){
            // 1. remove from existing DLL
            // 2. Check wheather this node belongs to minFreq DLL && is this the last node remaining on minFreq DLL --> Then update minFreq
            // 3. Update(increase) reqNode's frquency
            // 4. Insert this node at updated DLL at front (right after dummyHead)
        int oldFreq=(*reqNode).frequency;
        DLL* oldDLL=freq[oldFreq];
        (*oldDLL).remove(reqNode);
        if(oldFreq==minFreq && (*oldDLL).size==0){
            minFreq++;
        }
        (*reqNode).frequency++; int newFreq=(*reqNode).frequency;
        DLL* newDLL;
        if(freq.count(newFreq)>0){ // newFreq DLL already existed, so just insert the node in newFreq DLL
            newDLL=freq[newFreq];
        }
        else{
            newDLL= new DLL();
            freq[newFreq]=newDLL;
        }
        (*newDLL).insert(reqNode);
    }
    void put(int key, int value){
        if(capacity==0){ return; }
        if(m.count(key) >0){ // key already present
              // 1. Update its value
              // 2. Update node status
            Node* myNode=m[key]; (*myNode).value=value;
            updateNode(myNode);
        }
        else{ // key is not present
            Node* newNode= new Node(key, value);
            if(size==capacity){
                // --> Go to DLL of minFreq and DELETE node just before dummyTail 
                  //[Even if minFreq DLL got empty, no need to update minFreq, as with the insertion of newNode, 
                  // we update minFreq=1, & min value of minFreq is 1 itself]
                
                DLL* ourDLL=freq[minFreq];
                Node* delNode=(*ourDLL).removeEnd();
                int delKey=(*delNode).key; delete(delNode); m.erase(delKey);
                size--;
            }
              // 1. Update minFreq=1
              // 2. insert newNode in new minFreq DLL
            minFreq=1;
            DLL* newDLL;
            if(freq.count(minFreq)>0){
                newDLL=freq[minFreq];
            }
            else{
                newDLL= new DLL();
                freq[minFreq]=newDLL;
            }
            (*newDLL).insert(newNode);
            m[key]=newNode;
            size++;
        }
    }

    int get(int key){
        if(m.count(key)==0){
            return -1;
        }
        Node* reqNode=m[key];
        int temp=(*reqNode).value;
        updateNode(reqNode);
        return temp;
    }

};
