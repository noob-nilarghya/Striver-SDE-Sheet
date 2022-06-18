#include <stack>
// Solution 1: (less optimized)

class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    int size;
    public:
    Queue() {
        size=0;
    }

    void enQueue(int val) {
        while(!s1.empty()){   // s1 ----> s2
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);         // s1 <--- val
        while(!s2.empty()){   // s2 ----> s1
            s1.push(s2.top());
            s2.pop();
        }
        size++;
    }

    int deQueue() {
        if(isEmpty()==true){
            return -1;
        }
        int temp=s1.top();
        s1.pop();
        size--;
        return temp;
    }

    int peek() {
        if(isEmpty()==true){
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return (size==0);
    }
};
// Time Complexity : Enqueue: O(N), Dequeue: O(1), Peek: O(1)

//-------------------------------------------------------------------------------

// Solution 2: (most optimized)
class Queue {
    // Define the data members(if any) here.
    stack<int> input;
    stack<int> output;
    int size;
    public:
    Queue() {
        size=0;
    }

    void enQueue(int val) {
        input.push(val);
        size++;
    }

    int deQueue() {
        if(isEmpty()==true){
            return -1;
        }
        if(output.empty()==true){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int temp=output.top();
        output.pop();
        size--;
        return temp;
    }

    int peek() {
        if(isEmpty()==true){
            return -1;
        }
        if(output.empty()==true){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int temp=output.top();
        return temp;
    }

    bool isEmpty() {
        return (size==0);
    }
};
// Time Complexity: Enqueue: O(1), Dequeue: O(1)[Amortized O(N)], Peek: O(1)[Amortized O(N)]
