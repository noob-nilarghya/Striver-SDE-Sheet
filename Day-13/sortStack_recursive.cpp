// we will do it using recursion

void insert(int ele, stack<int>& s){ // insert ele in sorted stack using recursion
    if(s.empty()==true){
        s.push(ele);
        return;
    }
    if(s.top()<ele){
        s.push(ele);
        return;
    }
    int temp=s.top(); s.pop();
    insert(ele, s);
    s.push(temp);
    return;
}

void sortStack(stack<int> &s){ // sort stack using recusion
	if(s.size()==0 || s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    sortStack(s);
    insert(temp, s);
}