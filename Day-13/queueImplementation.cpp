// Implementing queue using circular array [ space optimized ]

class Queue {
public:
    int* arr;
    int firstIndex;
    int lastIndex;
    int size;
    int capacity;
    Queue() {
        capacity=5; // initial capacity
        size=0;
        firstIndex=0;
        lastIndex=0;
        arr= new int[capacity];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (size==0);
    }

    void enqueue(int data) { // insert from back
        if(size==capacity){ // array full ho chuka hai, resize karne ka zaroorat hai
            int* temp=arr;
            arr=new int[2*capacity];
            int oldCapacity=capacity; capacity*=2;
            int idx=0;
            for(int i=firstIndex; i<oldCapacity; i++){
                arr[idx]=temp[i];
                idx++;
            }
            for(int i=0; i<firstIndex; i++){
                arr[idx]=temp[i];
                idx++;
            }
            firstIndex=0;
            lastIndex=oldCapacity;
        }
        arr[lastIndex]=data;
        lastIndex=(lastIndex+1)%capacity;
        size++;
    }

    int dequeue() { // pop out from front
        if(isEmpty()==true){
            return -1;
        }
        int temp=arr[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        return temp;
    }

    int front() {
        if(isEmpty()==true){
            return -1;
        }
        return arr[firstIndex];
    }
};

//----------------------------------------------------------------------------

// Implementing queue using Linked List [ space optimized ]
// Insert from tail, delete from head
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    int size;
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (size==0);
    }

    void enqueue(int data) { //insert from tail
        Node* newNode= new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            (*tail).next=newNode;
            tail=(*tail).next;
        }
        size++;
    }

    int dequeue() { // delete from head
        if(isEmpty()==true){
            return -1;
        }
        int temp=(*head).data;
        Node* toBeDel=head;
        head=(*head).next;
        (*toBeDel).next=NULL;
        delete(toBeDel);
        size--;
        return temp;
    }

    int front() {
        if(isEmpty()==true){
            return -1;
        }
        return (*head).data;
    }
};