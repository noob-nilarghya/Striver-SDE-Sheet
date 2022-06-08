#include <bits/stdc++.h> 
/****************************************************************

    // Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
// The problem is just like merge Sort algorithm. 

Node* merge(Node* flattenList, Node* recursionList){ // Normal merge function (merge 2 sorted LL using bottom(child) pointer)
    Node* head=NULL; Node* bottom=NULL; 
    // Acc to Qn: The flattened list will be printed using the bottom pointer instead of the next pointer.
    
    Node* i=flattenList; Node* j=recursionList; // apply normal merge sort
    if((*i).data < (*j).data){
        head=i; bottom=i;
        i=(*i).child;
    }
    else{
        head=j; bottom=j;
        j=(*j).child;
    }
    while(i!=NULL && j!=NULL){
        if((*i).data < (*j).data){
            (*bottom).child=i;
            bottom=(*bottom).child; i=(*i).child;
        }
        else{
            (*bottom).child=j;
            bottom=(*bottom).child; j=(*j).child;
        }
    }
    if(i!=NULL){
        (*bottom).child=i;
    }
    if(j!=NULL){
        (*bottom).child=j;
    }
    (*head).next=NULL;
    return head;
}

Node* flattenLinkedList(Node* head) {
	if((*head).next==NULL){ // when I have a single flatten list
        return head;
    }
    Node* recursionList= flattenLinkedList((*head).next); (*recursionList).next=NULL;
    Node* flattenList=head; (*head).next=NULL;
    // Now I have 2 separate flattened list. I have to merge them
    
    Node* mergedList= merge(flattenList,recursionList);
    return mergedList;
}

// Time Complexity: O(N)
// Space Complexity: O(1)