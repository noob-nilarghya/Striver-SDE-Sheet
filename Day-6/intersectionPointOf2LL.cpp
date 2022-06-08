#include <bits/stdc++.h> 

int len(Node* head){
    Node* temp=head; int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=(*temp).next;
    }
    return cnt;
}

int findIntersection(Node *head1, Node *head2){
    if(head1==NULL || head2==NULL){ return -1; }
    int size1=len(head1); int size2=len(head2);
    if(size1>size2){
        int diff=size1-size2;
        while(diff--){  head1=(*head1).next;  }
    }
    else if(size1<size2){
        int diff=size2-size1;
        while(diff--){  head2=(*head2).next;  }
    }
    
    // Now head1 and head2 are at same distance from mergedNode
    while(head1!=NULL && head2!=NULL && head1!=head2){
        head1=(*head1).next;
        head2=(*head2).next;
    }
    if(head1==NULL || head2==NULL){ return -1; }
    if(head1==head2){ return (*head1).data; }
    return -1;
}

// Time Complexity: O(N)
// Space Complexity: O(1)