// Stack class using array
class Stack {
public:
    int* arr;
    int size;
    int index;
    int capacity;
    Stack(int capacity) {
        this->capacity=capacity;
        index=0;
        arr= new int[capacity];
        size=0;
    }

    void push(int num) {
        if(isFull()==1){
            return;
        }
        arr[index]=num; 
        index++; size++;
    }

    int pop() {
        if(isEmpty()==1){
            return -1;
        }
        int temp=arr[index-1];
        index--; size--;
        return temp;
    }
    
    int top() {
        if(isEmpty()==1){
            return -1;
        }
        return arr[index-1];
    }
    
    int isEmpty() {
        if(size==0){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(size==capacity){
            return  1;
        }
        return 0;
    }
};