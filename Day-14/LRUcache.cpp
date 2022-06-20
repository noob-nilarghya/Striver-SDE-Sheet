#include <bits/stdc++.h>

class Node{
    public:
    int key; int value;
    Node* next; Node* prev;
    Node(int key, int val){
        this->key=key;
        this->value=val;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache{
public:
    unordered_map<int, Node*> m; // <key, Node*>
    Node* dummyHead;
    Node* dummyTail; 
    int size;
    int capacity;
    LRUCache(int capacity) {
        this->size=0;
        this->capacity=capacity;
        dummyHead= new Node(-1,-1);
        dummyTail= new Node(-1,-1);
        (*dummyHead).next=dummyTail;
        (*dummyTail).prev=dummyHead;
    }
    
    void put(int key, int value){
        if(capacity==0){ return; }
        
        if(m.count(key)>0){// key already existed
            // 1. remove its connection
            // 2. just update its value
            // 3. Bring it in front right after dummyHead
            Node* myNode= m[key];
            Node* delPrev=(*myNode).prev;
            Node* delNxt=(*myNode).next;
            (*delPrev).next=delNxt;
            (*delNxt).prev=delPrev;
            (*myNode).next=NULL; (*myNode).prev=NULL; (*myNode).value=value;
            Node* dummyHeadNxt=(*dummyHead).next;
            (*dummyHead).next=myNode;
            (*myNode).prev=dummyHead;
            (*myNode).next=dummyHeadNxt;
            (*dummyHeadNxt).prev=myNode;
        }

        else{ // key does not existed
            Node* newNode= new Node(key, value);
            if(size==capacity){ // size over flowed
                // 1. Cut connection of LRU guy (node right before dummyTail)
                // 2. Delete that node
                Node* delNode=(*dummyTail).prev;
                Node* delPrev=(*delNode).prev;
                (*delPrev).next=dummyTail;
                (*dummyTail).prev=delPrev;
                (*delNode).prev=NULL; (*delNode).next=NULL; m.erase((*delNode).key); delete(delNode); 
                size--;
            }
            // make this node & connect it in front (right after dummyHead)
            Node* headNxt=(*dummyHead).next;
            (*dummyHead).next=newNode;
            (*newNode).prev=dummyHead;
            (*newNode).next=headNxt;
            (*headNxt).prev=newNode;
            m[key]=newNode;
            size++;
        }
    }

    int get(int key){
        if(m.count(key)==0){
            return -1;
        }
        else{ // key exist
        //  1. Remove all connection
        //  2. bring it in front (right after dummyHead)
            Node* myNode= m[key];
            Node* delPrev=(*myNode).prev;
            Node* delNxt=(*myNode).next;
            (*delPrev).next=delNxt;
            (*delNxt).prev=delPrev;
            (*myNode).next=NULL; (*myNode).prev=NULL; int temp=(*myNode).value;
            Node* dummyHeadNxt=(*dummyHead).next;
            (*dummyHead).next=myNode;
            (*myNode).prev=dummyHead;
            (*myNode).next=dummyHeadNxt;
            (*dummyHeadNxt).prev=myNode;
            return temp;
        }
    }
};
