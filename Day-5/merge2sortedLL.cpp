#include <bits/stdc++.h> 

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if(first==NULL && second!=NULL){ return second; }
    if(first!=NULL && second==NULL){ return first; }
    if(first==NULL && second==NULL){ return NULL; }
    
    Node<int>* head=NULL;  Node<int>* tail=NULL;
    if((*first).data < (*second).data){
        head=first; tail=first;
        first=(*first).next;
    }
    else{
        head=second; tail=second;
        second=(*second).next;
    }

    while(first!=NULL && second!=NULL){
        if((*first).data < (*second).data){
            (*tail).next=first;
            tail=(*tail).next;
            first=(*first).next;
        }
        else{
            (*tail).next=second;
            tail=(*tail).next;
            second=(*second).next;
        }
    }
    
    if(first!=NULL){
        (*tail).next=first;
    }
    if(second!=NULL){
        (*tail).next=second;
    }
    return head;
}
