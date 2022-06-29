#include <bits/stdc++.h>
// slight variation of Longest Increasing Sub-sequence (LIS)

int maxIncreasingDumbbellsSum(vector<int> &rack, int n){
	vector<int> sum(n);
    sum[0]=rack[0];
    for(int i=1; i<rack.size(); i++){
        int mx=INT_MIN;
        for(int j=0; j<i; j++){
            if(rack[j]<rack[i]){
                mx=max(mx,sum[j]);
            }
        }
        if(mx==INT_MIN){ // no ele less than rack[i] from 0 to i-1
            sum[i]=rack[i];
        }else{
            sum[i]=mx+rack[i];
        }
    }
    return *max_element(sum.begin(), sum.end());
}