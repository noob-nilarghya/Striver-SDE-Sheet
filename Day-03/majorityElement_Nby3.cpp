#include <bits/stdc++.h> 
/* Here majority element means freq>n/3. So there would be at max, 2 elemnt possible to become majority element. 
   Here we will apply "Extended moore vooting algorithm". */
// Intution is more or less same as moore vooting algo. To understand better, DRY RUN !

vector<int> majorityElementII(vector<int> &arr) {
    int elem1=-1; int cnt1=0;
    int elem2=-1; int cnt2=0;
    int n=arr.size();
    
    for(int i=0; i<n; i++){
        if(arr[i]==elem1){
            cnt1++;
        }
        else if(arr[i]==elem2){
            cnt2++;
        }
        else if(cnt1==0){
            elem1=arr[i];
            cnt1=1;
        }
        else if(cnt2==0){
            elem2=arr[i];
            cnt2=1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    // Possible Candidate could be "elem1" and "elem2". Now verify 
    int count1=0; int count2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==elem1){count1++;}
        else if(arr[i]==elem2){count2++;}
    }

    vector<int> ans;
    if(count1> n/3){ ans.push_back(elem1); }
    if(count2> n/3){ ans.push_back(elem2); }
    return ans;
}

// Time Complexity: O(n)
// Space Complexity: O(1)