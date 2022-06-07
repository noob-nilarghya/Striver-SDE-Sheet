#include <bits/stdc++.h> 

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int maxLen=INT_MIN;
    unordered_map<int, int> m;
    for(auto it: arr){  m[it]++;  }

    while(!m.empty()){
        auto it=m.begin(); int num=(*it).first;
        int len=0; 
        if(m.count(num)>0){
            len++;
            m.erase(num);
            int temp1=num-1;
            while(m.count(temp1)>0){
                m.erase(temp1);
                temp1--;
                len++;
            }
            int temp2=num+1;
            while(m.count(temp2)>0){
                m.erase(temp2);
                temp2++;
                len++;
            }
            maxLen=max(len, maxLen);
        }
    }
    if(maxLen==INT_MIN){ return 0; }
    return maxLen;
}

// Time Complexity: O(N)
// Space Complexity: O(N)