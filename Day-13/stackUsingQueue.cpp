// Using circular rotation of queue

#include <queue>

class Stack {
	queue<int> q;
    int size;
   public:
    Stack() {
        size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return (size==0);
    }

    void push(int element) { // circular rotation of queue
        int qSize=q.size();
        q.push(element);
        while(qSize--){
            int temp=q.front(); q.pop();
            q.push(temp);
        }
        size++;
    }

    int pop() {
        if(isEmpty()==true){
            return -1;
        }
        int temp=q.front();
        q.pop();
        size--;
        return temp;
    }

    int top() {
        if(isEmpty()==true){
            return -1;
        }
        return q.front();
    }
};