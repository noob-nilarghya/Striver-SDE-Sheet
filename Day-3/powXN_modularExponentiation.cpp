#include <bits/stdc++.h> 

long long int modularExponentiation(int a, int n, int m) { // (a^n)%m
	long long int res=(long long int)1; // identity
    long long int mod=(long long int)m;
    
    while(n!=0){
        if((n&1)!=0){ // odd
            res=((res%mod)*(a%mod))%mod;
            n--;
        }
        else if((n&1)==0){ // even
            a=((a%mod)*(a%mod))%mod;
            n=n>>1; // n=n/2
        }
        res=res%mod;
    }
    return res;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)