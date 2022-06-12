#include <bits/stdc++.h>

// METHOD 1: GENERATE ALL PERMUTATION IN LEXI ORDER & RETURN (k-1)th INDEX
vector<string> ans;
void helper(string input, string output){
    if(input.length()==0){
        ans.push_back(output);
        return;
    }
    for(int i=0; i<input.length(); i++){
        output.push_back(input[i]);
        string ip=input;
        ip.erase(ip.begin()+i);
        helper(ip, output);
        output.pop_back();
    }
    return;
}

string kthPermutation(int n, int k) {
    string input="";
    for(int i=1; i<=n; i++){
        char y= i+'0';
        input.push_back(y);
    }
    ans.clear();
    helper(input, "");
    return ans[k-1];

    /*
    // METHOD 2: USING NEXT PERMUTATION
    k--;
    while(k--){
        next_permutation(input.begin(), input.end());
    }
    return input;
    */
}

//---------------------------------------------------------------

// METHOD3: MATHEMATIAL INTUTION [ BEST ]
int factorial(int n){
    if(n==0 || n==1){ return 1; }
    return n*factorial(n-1);
}
string ans="";
void helper(string input, string output, int k){
    if(input.length()==0){ ans=output; return; }
    int fact=factorial(input.size()-1);
    int idx= k/fact;
    if(idx==0){
        output.push_back(input[idx]);
        string ip=input;  ip.erase(ip.begin()+idx);
        helper(ip, output, k);
        output.pop_back();
    }
    else{
        output.push_back(input[idx]);
        string ip=input;  ip.erase(ip.begin()+idx);
        helper(ip, output, k%fact);
        output.pop_back();
    }
    return;
}
string kthPermutation(int n, int k) {
    string input="";
    for(int i=1; i<=n; i++){
        char y= i+'0';
        input.push_back(y);
    }
    string output="";
    helper(input, output, k-1);
    return ans;
}

