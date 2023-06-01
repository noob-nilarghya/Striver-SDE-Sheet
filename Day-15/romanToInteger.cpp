#include <bits/stdc++.h> 

int romanToInt(string s) {
    // Roman numerals are usually written largest to smallest from left to right
    // I can be placed before V (5) and X (10) to make 4 and 9. 
    // X can be placed before L (50) and C (100) to make 40 and 90. 
    // C can be placed before D (500) and M (1000) to make 400 and 900.
    
    unordered_map<char, int> m;
    m['I']=1; m['V']=5; m['X']=10; m['L']=50; m['C']=100; m['D']=500; m['M']=1000;

    int ans=0;
    for(int i=0; i<s.size()-1; i++){
        if(m[s[i]]>=m[s[i+1]]){
            ans+=m[s[i]];
        }
        else{
            ans-=m[s[i]];
        }
    }
    ans+=m[s.back()];
    return ans;
}
