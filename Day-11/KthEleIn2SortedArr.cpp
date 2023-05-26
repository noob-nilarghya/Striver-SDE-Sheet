#include <bits/stdc++.h>
// Same as median of 2 sorted array [except starting low and high value]

int ninjaAndLadoos(vector<int> &a, vector<int> &b, int m, int n, int k) {
    
    if(a.size() > b.size()){ return ninjaAndLadoos(b, a, n, m, k); } 
    int totalSize=m+n;
    int leftPartSize=k;
    int low=max(0,k-n); int high=min(m,k);
    
    while(low<=high){
        int cut1=low+(high-low)/2; int cut2=leftPartSize-cut1;
        int l1; int l2; int r1; int r2;
        //------------------------------------------------------
        if(cut1==0){ l1=INT_MIN; } // no ele in left part of 'a'
        else{ l1=a[cut1-1]; }
        
        if(cut2==0){ l2=INT_MIN; } // no ele in left part of 'b'
        else{ l2=b[cut2-1]; }
        
        if(cut1==m){ r1=INT_MAX; } // no ele in right part of 'a' 
        else{ r1=a[cut1]; }
        
        if(cut2==n){ r2=INT_MAX; } // no ele in right part of 'b'
        else{ r2=b[cut2]; }
        //--------------------------------------------------------
        if(l1>r2){ // need to decrease l1 and increase r2 --> move left of 'a'
            high=cut1-1;
        }
        else if(l2>r1){ // need to decrease l2 and increase r1 --> move left of 'b' OR in other word: move right of 'a'
            low=cut1+1;
        }
        else if(l1 <= r2 && l2 <= r1){ // required condition satisfied ! [no odd/ even case]
            return max(l1, l2);  // take max(l1,l2) from left half
        }
    }
}
