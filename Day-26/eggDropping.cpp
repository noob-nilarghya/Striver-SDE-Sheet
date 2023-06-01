#include <bits/stdc++.h>


//                           ----------  EGG DROPPING PROBLEM ----------------
// K number of eggs, N floors. we need to use egg wisely to find minimum # of attempts to find threshold floor in worst case
// (Note: we are not asked to find the threshold floor, we are just asked to return min attempts in WC)

int helper(int n, int eggs){
    if(eggs==1){ // we have only 1 egg
        // so to use it wiesely we have to drop it from ground floor and move one floor up at every attempt.
        // So, in worst case, threshold floor would be top floor, so we need 'n' attempts
        return n;
    }
    if(n==0 || n==1){ // we have only one or no floor
        // so, for zero floor, I need 0 attempt, for 1 floor, I need 1 attempt
        return n;
    }

    int minAttempt= INT_MAX;
    // Now this is an MCM pattern question.
    // That is from [1-n], we will throw egg from every possible floor and pass remaining 2 half to recursion
    for(int k=1; k<n; k++){
        
        int ifBreak= helper(k-1, eggs-1); // try to drop it from floor [1, (i-1)] with 'k-1' remaining eggs
        int ifNotBreak= helper(n-k, eggs); // try to drop it from floor [i+1, n] with 'k' remaining eggs
        int attempt=1 + max(ifBreak, ifNotBreak); // throwing from ith floor is one attempt + max of 2 half because we want worst case

        minAttempt= min(minAttempt, attempt);
    }

    return minAttempt;
}

int cutLogs(int k, int n){
    return helper(n, k);
}

// laude memoize it, ye intutuin interview mein ana tere bas ka nhi hai
