// Acording to question from: Code Studio - by Coding Ninjas [IMP]
#include <bits/stdc++.h> 

vector<vector<int>> pairSum(vector<int> &arr, int s){
    unordered_map<int, int> m; int target=s;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(auto it: arr){
       m[it]++;
    }
    for(auto it: arr){
       m[it]--;
       if(m.count(target-it)>0 && m[target-it]>0){
           for(int i=0; i<m[target-it]; i++){
               vector<int> vec={min(it, target-it), max(it, target-it)}; ans.push_back(vec);
           }
       }
   }
   return ans;
}

// Time Complexity: O(NlogN)
// Space Complexity: O(N)

//------------------------------------------------------------------------------------------------
// According to question from: LeetCode

#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]=i;
        }
        
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            int temp=target-nums[i];
            if(m.count(temp)>0 && m[temp]!=i){
                ans={i,m[temp]};
                return ans;
            }
        }
        return ans;
    }
};