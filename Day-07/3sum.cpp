#include <bits/stdc++.h> 

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++){
        // Now apply simple 2 pointer technique
        int low= i+1; int high=n-1; int target=K-arr[i];
        
        while(low<high){
            if(arr[low]+arr[high]<target){ // move low -->
                int temp=arr[low];
                while(low<high && arr[low]==temp){ low++; }
            }
            else if( arr[low]+arr[high] > target){ // move high <---
                int temp=arr[high];
                while(low<high && arr[high]==temp){ high--; }
            }
            else if( arr[low]+arr[high]== target){
                vector<int> vec={arr[i], arr[low], arr[high]}; ans.push_back(vec);
                int tempLow=arr[low]; int tempHigh=arr[high];
                while(low<high && arr[low]==tempLow){ low++; }
                while(low<high && arr[high]==tempHigh){ high--; }
            }
        }
        int temp=arr[i];
        while(i<n && arr[i]==temp){ i++; }
        //now arr[i] != temp
        i--;
    }
    return ans;
}

// Time Complexity: O(N^2)+O(NlogN)
// Space Complexity: O(1)