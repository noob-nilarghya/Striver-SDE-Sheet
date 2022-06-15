#include <bits/stdc++.h>

long long daysTook(vector<int>& page, int maxPagesADay){
    long long dayCount=1; long long pages=0;
    for(int i=0; i<page.size(); i++){
        pages+=page[i];
        if(maxPagesADay < pages){
            dayCount++;
            pages=page[i];
        }
    }
    return dayCount;
}

long long ayushGivesNinjatest(int n, int m, vector<int> page) {	
    long long sum=0; for(auto it: page){ sum+=it; }
	long long low=*max_element(page.begin(), page.end()); long long high=sum; int day=n; long long ans=-1;
    
    while(low<=high){
        long long mid=low+(high-low)/2; // assuming mid is the max pages he can read a day
        long long dayTook= daysTook(page, mid);
        
        if(dayTook > day){ // we need to icrease max pages he can read per day
            low=mid+1;
        }
        else if(dayTook < day){ // we need to decrease max pages he can read per day
            ans=mid;
            high=mid-1;
        }
        else if(dayTook == day){ // we need to decrease max pages he can read per day (as we have to minimise it)
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}