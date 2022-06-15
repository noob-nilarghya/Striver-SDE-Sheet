#include <bits/stdc++.h>
// [MOST IMP]
// we traverse BS through cut1 (partition index of a), where a.size()<=b.size() [TC: O(min(logm, logn))]

double median(vector<int> a, vector<int> b){
    if(a.size() > b.size()){ return median(b, a); } 
    
    int m=a.size(); int n=b.size(); 
    int totalSize=m+n;
    int leftPartSize=(totalSize+1)/2; //both applicable for odd OR even size
    int low=0; int high=m; // as [a.size()<=b.size()], so m has to be <= leftPartSize, thats why I take high=m
    
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
        else if(l1 <= r2 && l2 <= r1){ // required condition satisfied !
            if(totalSize % 2 ==0){ // even sized, take mean of 2 median
                int a= max(l1, l2);
                int b= min(r1, r2);
                return (a+b)/2.0;
            }
            else if(totalSize % 2 ==1){ // even sized, take max(l1,l2) from left half
                return max(l1, l2);
            }
        }
    }
}

// Time Complexity: O(min(logm, logn))
