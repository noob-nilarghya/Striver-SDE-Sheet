#include <bits/stdc++.h> 
//Let arr[]= { 1 3 4 5 5 }

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	int originalXor=0;
    for(int i=1; i<=n; i++){
        originalXor=originalXor^i;
    }
    int xorRes=0;
    for(auto it: arr){
        xorRes=xorRes^it;
    }
    xorRes=xorRes^originalXor; // (1^2^3^4^5)^(1^3^4^5^5)== 2^5

    // now we need to find the binary equivalent whose all bit are reset except least significant set bit of 2^5 
    int num= xorRes&(~(xorRes-1));
    // only least significant set bit of 2^5 is set in num. So bit at that position in 2 and 5 are different.
    /* So, if we group array based on wheater that bit of arr[i] is set or reset, 
     missing & repeating number belongs to different groups */
    int grp1=0; int grp2=0;
    
    for(int i=0; i<arr.size(); i++){
        if((arr[i]&num)==0){ // that bit pos of arr[i] is reset
            grp1=grp1^arr[i];
        }
        else{ // that bit pos of arr[i] is reset
            grp2=grp2^arr[i];
        }
    }
    // Also group [1-N]
    for(int i=1; i<=n; i++){
        if((i&num)==0){ grp1=grp1^i; }
        else{ grp2=grp2^i; }
    }
	// grp1= (4)^(2^4) = 2
    // grp2= (1^3^5^5)^(1^3^5) = 5

    int var=grp1;
    for(auto it: arr){
        if(it==var){ // rpeating number
            return {grp2, grp1};
        }
    }
    return {grp1, grp2};
}

// Time Complexity: O(n)
// Space Complexity: O(1)
