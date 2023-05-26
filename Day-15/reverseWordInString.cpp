#include <bits/stdc++.h>

string reverseString(string str){
    stack<string> st;
    int idx=0; int len=str.length();
    while(idx<len){
        if(str[idx]==' '){
            while(idx<len && str[idx]==' '){ idx++; }
        }
        // now str[idx] != ' '
        else if(str[idx]!=' '){
            string temp="";
            while(idx<len && str[idx]!=' '){
                temp.push_back(str[idx]); idx++;
            }
            st.push(temp);
        }
        // now s[str] == ' '
    }
    string s;
    while(!st.empty()){
        s.append(st.top()); st.pop();
        s.push_back(' ');
    }
    return s;
}
// Time Complexity : O(N)
// Space Complexity: O(N)

//---------------------------------------------------------

// Approach 2: Efficient (In-Place)
    
    void reverseStr( string& ans, int start, int end){
        int i=start; int j=end;
        while(i<=j){
            swap(ans[i], ans[j]);
            i++; j--;
        }
        return;
    }
    
    string reverseWords(string str) {
        int idx=0; int i=0; int len=str.length();
        reverseStr(str, 0, str.length()-1);
        string ans=str;
        while(i<len){
            if(str[i]==' '){
                i++;
            }
            else if(str[i]!= ' '){
                int start=idx;
                while(i<len && str[i] != ' '){
                    ans[idx]=str[i];
                    i++; idx++;
                }
                reverseStr(ans, start, idx-1);
                ans[idx]=' '; idx++;
            }
        }
        for(int i=idx; i<str.length(); i++){
            ans.pop_back();
        }
        if(ans[ans.size()-1]==' '){ ans.pop_back(); }
        
        return ans;
    }
    // Time Complexity: O(N)
    // Space Complexity: O(1) [constant]
