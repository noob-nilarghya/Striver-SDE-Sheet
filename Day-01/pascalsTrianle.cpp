#include <bits/stdc++.h> 
// Do as pascals triangle actually works! Don't do factorial way (Time taking)

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> ans;
    
    for(long long int i=0; i<n; i++){
        vector<long long int> vec(i+1, (long long int)0);
        vec[0]=1; vec[i]=1;
        for(long long int j=1; j<=i-1; j++){
            vec[j]=ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(vec);
    }
    return ans;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)