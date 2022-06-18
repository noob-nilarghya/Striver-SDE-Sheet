// Using Stack
bool isValidParenthesis(string exp){
    stack<char> s;
    for(int i=0; i<exp.size(); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){ // opening parenthesis -> push
            s.push(exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){ // closing parenthseis
            if(s.empty()==true){ return false; }
            else if(s.top()==')' || s.top()=='}' || s.top()==']'){ return false; }
            else if(exp[i]==')' && s.top()=='('){ s.pop(); }
            else if(exp[i]=='}' && s.top()=='{'){ s.pop(); }
            else if(exp[i]==']' && s.top()=='['){ s.pop(); }
            else{ return false; }
        }
    }
    if(!s.empty()){ return false; }
    return true; 
}

//--------------------------------------------------------------------------------------

// Without Using Stack [ VERY VERY IMPORTANT ]
bool isMatch(char c1, char c2){
    if(c1=='(' && c2==')'){ return true; }
    if(c1=='{' && c2=='}'){ return true; }
    if(c1=='[' && c2==']'){ return true; }
    return false; 
}
bool isValidParenthesis(string exp){
    int top=-1;
    for(int i=0; i<exp.size(); i++){
        if(top<0 || ! isMatch(exp[top], exp[i])){
            top++;
            exp[top]=exp[i];
        }
        else{
            top--;
        }
    }
    return (top== -1);
}