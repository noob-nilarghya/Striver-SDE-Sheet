#include <bits/stdc++.h> 

int maximumProfit(vector<int> &price){
    /* we want that when we are at 'i', we can know the maximum price of stock from [i+1, size-1]. So that we can know the maximum profit I can make if I buy the stock on 'i'th day. We we then fin max of all maximum profit to get ans */
    
        int maxi= INT_MIN; // keep a track of maximum value 
        int profit=0; // initially profit is 0
        
        for(int i=price.size()-1; i>=0; i--){
            
            maxi=max(maxi, price[i]);
            profit= max(profit, maxi-price[i]);
        }
        
    return profit;
}

// Time Complexity: O(n)
// Space Complexity: O(1)