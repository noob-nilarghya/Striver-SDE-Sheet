// According to question from:  LeetCode [IMP]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        if(arr.size()<4){ return ans; }
        sort(arr.begin(), arr.end()); int n=arr.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                // Now Apply simple 2 pointer technique
                int low=j+1; int high=n-1; int newTarget=target-(arr[i]+arr[j]);

                while(low<high){
                    if(arr[low]+arr[high]<newTarget){
                        int temp=arr[low];
                        while(low<high && arr[low]==temp){ low++; }
                    }
                    else if(arr[low]+arr[high]>newTarget){
                        int temp=arr[high];
                        while(low<high && arr[high]==temp){ high--; }
                    }
                    else if(arr[low]+arr[high]==newTarget){
                        vector<int> temp={arr[i], arr[j], arr[low], arr[high]}; ans.push_back(temp);
                        int lowTemp=arr[low]; int highTemp=arr[high];
                        while(low<high && arr[low]==lowTemp){ low++; }
                        while(low<high && arr[high]==highTemp){ high--; }
                    }
                }
                int temp=arr[j];
                while(j<n && arr[j]==temp){
                    j++;
                }// Now arr[j]!=temp
                j--;
            }
            int temp=arr[i];
            while(i<n && arr[i]==temp){
                i++;
            }// Now arr[i]!=temp
            i--;
        }
        return ans;
    }
};


// According to codestudio
#include <bits/stdc++.h> 

string fourSum(vector<int>& arr, int target, int n) {
    if(arr.size()<4){ return "No"; }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            
            // Now Apply simple 2 pointer technique
            int low=j+1; int high=n-1; int newTarget=target-(arr[i]+arr[j]);
            while(low<high){
                if(arr[low]+arr[high]<newTarget){
                    int temp=arr[low];
                    while(low<high && arr[low]==temp){ low++; }
                }
                else if(arr[low]+arr[high]>newTarget){
                    int temp=arr[high];
                    while(low<high && arr[high]==temp){ high--; }
                }
                else if(arr[low]+arr[high]==newTarget){
                    return "Yes";
                }
            }
            int temp=arr[j];
            while(j<n && arr[j]==temp){
                j++;
            }// Now arr[j]!=temp
            j--;
        }
        int temp=arr[i];
        while(i<n && arr[i]==temp){
            i++;
        }// Now arr[i]!=temp
        i--;
    }
    return "No";
}

// Time Complexity: O(N^3)+O(NlogN)
// Space Complexity: O(1)

// Time Complexity: O(N^3)+O(NlogN)
// Space Coplexity: O(1)