#include <bits/stdc++.h>

vector<int> countDistinctElements(vector<int> &arr, int k) {
    unordered_map<int, int> m; vector<int> ans;
    int i=0; int j=0;
    while(j<arr.size()){
        m[arr[j]]++;
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 ==k){
            ans.push_back(m.size());
            m[arr[i]]--;
            if(m[arr[i]]==0){
                m.erase(arr[i]);
            }
            i++; j++;
        }
    }
	return ans;
}
