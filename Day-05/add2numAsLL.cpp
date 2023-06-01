#include <bits/stdc++.h> 

Node *addTwoNumbers(Node *head1, Node *head2){
    int carry=0;
    Node* head=NULL; Node* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        int sum=(*head1).data+(*head2).data+carry;
        if(sum>9){
            sum=sum%10; carry=1;
        }
        else{ carry=0; }
        Node* newNode= new Node(sum);
        if(head==NULL){
            head=newNode; tail=newNode;
        }
        else{
            (*tail).next=newNode;
            tail=(*tail).next;
        }
        head1=(*head1).next; head2=(*head2).next;
    }

    while(head1!=NULL){
        int sum=(*head1).data+carry;
        if(sum>9){
            sum=sum%10; carry=1;
        }
        else{ carry=0; }
        Node* newNode=new Node(sum);
        if(head==NULL){
            head=newNode; tail=newNode;
        }
        else{
            (*tail).next=newNode;
            tail=(*tail).next;
        }
        head1=(*head1).next;
    }

    while(head2!=NULL){
        int sum=(*head2).data+carry;
        if(sum>9){
            sum=sum%10; carry=1;
        }
        else{ carry=0; }
        Node* newNode=new Node(sum);
        if(head==NULL){
            head=newNode; tail=newNode;
        }
        else{
            (*tail).next=newNode;
            tail=(*tail).next;
        }
        head2=(*head2).next;
    }

    if(carry==1){
        Node* newNode=new Node(carry);
        (*tail).next=newNode;
        tail=(*tail).next;
    }
    return head;
}

// Time Complexity: O(max(size of head1, size of head2))
// Space Complexity: O(1)