#include <bits/stdc++.h> 

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head){
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> m;
    
    // step1: Traverse original LL, & create new node at the same time & connect all the next pointers (dont think of random pointer as if now). 
    //Also map currentNode with newNode in hashmap
    LinkedListNode<int>* temp=head; LinkedListNode<int>* newHead=NULL; LinkedListNode<int>* newTail=NULL;
    while(temp!=NULL){
        LinkedListNode<int>* newNode= new LinkedListNode<int>((*temp).data);
        if(newHead==NULL){ // very first insertion
            newHead=newNode;
            newTail=newNode;
        }
        else{
            (*newTail).next=newNode;
            newTail=(*newTail).next;
        }
        m[temp]=newNode;
        temp=(*temp).next;
    }
    
    // Step2: Traverse both LL simultanously & fetch original node's corresponding random pointer, 
    // search it in hashmap, go to corresponding key & make that node(at key) as randomPtr of corresponding newNode
    temp=head; LinkedListNode<int>* temp2=newHead;
    while(temp!=NULL){
        LinkedListNode<int>* randomPtr=(*temp).random;
        if(randomPtr==NULL){
            (*temp2).random=NULL;
        }
        else{
            LinkedListNode<int>* newRandom=m[randomPtr];
            (*temp2).random= newRandom;
        }
        temp=(*temp).next; temp2=(*temp2).next;
    }
    return newHead;
}

// Time Complexity: O(N) [AUXILIARY]
// Space Complexity: O(1)
