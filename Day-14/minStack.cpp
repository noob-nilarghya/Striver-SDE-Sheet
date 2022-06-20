// Method 1:  using 2 stack Approach
class minStack{
	
	stack<int> main;
    stack<int> mini;
	public:
		
		// Constructor
		minStack() { 
			// do nothing
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num){
			main.push(num);
            if(mini.size()==0){
                mini.push(num);
            }
            else if(num <= mini.top()){
                mini.push(num);
            }
		}
		
		// Function to remove the top element of the stack.
		int pop(){
			if(main.empty()==true){ return -1; }
            if(main.top()==mini.top()){
                mini.pop();
            }
            int temp=main.top(); main.pop();
            return temp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top(){
			if(main.empty()==true){ return -1; }
            return main.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin(){
            if(mini.empty()==true){ return -1; }
			return mini.top();
		}
};

//--------------------------------------------------------------------------------------------------------

// Methode 2:  Using single stack & corrupt value
#include<bits/stdc++.h>

class minStack{
	stack<int> s;
    int mini;
	
	public:
		
		// Constructor
		minStack() { 
			mini=INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num){
			if(s.empty()==true){
                s.push(num);
                mini=num;
            }
            else{
                if(num <= mini){
                    int corruptVal=2*num-mini; // 2*currMin-oldMin
                    s.push(corruptVal);
                    mini=num;
                }
                else{
                    s.push(num);
                }
            }
		}
		
		// Function to remove the top element of the stack.
		int pop(){
			if(s.empty()==true){ return -1; }
            if(s.top() <= mini){
                // reove that corrupt value
                int temp=s.top();
                int oldMini=2*mini-temp;
                s.pop(); 
                int tmp=mini;
                mini=oldMini;
                return tmp;
            }
            int temp=s.top();
            s.pop();
            return temp;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top(){
			if(s.empty()==true){
                return -1;
            }
            if(s.top() <= mini){ // stack top has corrupted value, return mini
                return mini;
            }
            return s.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin(){
			if(s.empty()==true){
                return -1;
            }
            return mini;
		}
};