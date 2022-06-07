#include <bits/stdc++.h> 
// This is a typical question of variable sized sliding window

int uniqueSubstrings(string arr){
    unordered_map<char, int> m; int n=arr.size(); int len=INT_MIN;
    int i=0; int j=0;

    while(j<n){
        m[arr[j]]++;  // calculation for j
        if(m.size()==(j-i+1)){ // Substring Without Repeating Characters
            len=max(len, (j-i+1));
            j++; // try to get more long window size
        }
        else if(m.size()<(j-i+1)){ // we have repeating character, reduce window size
            while(i<j && m.size()!=(j-i+1)){
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
            }
            if(m.size()==(j-i+1)){
                len=max(len, (j-i+1));
            }
            j++;
        }
    }
    return len;
}

// Time Complexity: O(N)
// Space Complexity: O(N)