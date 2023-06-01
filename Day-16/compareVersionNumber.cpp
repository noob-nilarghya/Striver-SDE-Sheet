// Leetcode Version

#include <bits/stdc++.h>
#include <sstream>

class Solution {
public:
    int stringToInt(string s){   stringstream nil(s);  int x = 0;   nil >> x;   return x;  }
    
    int compareVersionHelper(string version1,int start1, int size1, string version2, int start2, int size2) {
        if(start1>=size1 && start2>=size2){
            return 0;
        }
        else if(start1>=size1){
            for(int j=start2; j<size2; j++){
                if(!(version2[j]=='.' || version2[j]=='0')){ return -1; }
            }
            return 0;
        }
        else if(start2>=size2){
            for(int i=start1; i<size1; i++){
                if(!(version1[i]=='.' || version1[i]=='0')){ return 1; }
            }
            return 0;
        }
        
        int i; string s1="";
        for( i=start1; i<size1; i++){
            if(version1[i]=='.'){ break; }
            s1.push_back(version1[i]);
        }
        
        int j; string s2="";
        for( j=start2; j<size2; j++){
            if(version2[j]=='.'){ break; }
            s2.push_back(version2[j]);
        }
        
        int num1= stringToInt(s1);
        int num2= stringToInt(s2);
        if(num1<num2){  return -1; }
        else if(num1>num2){ return 1; }
        
        return compareVersionHelper(version1,i+1, size1, version2, j+1, size2);
    }
    int compareVersion(string version1, string version2){
        return compareVersionHelper(version1,0, version1.length(), version2,0, version2.length());
    }
};


// Codestudio Version

#include <bits/stdc++.h> 
int compareVersions(string a, string b) {
   int i=0,j=0, aLen = a.length(), bLen = b.length();
    while(i<aLen || j<bLen){
       long long n1 = 0,n2 = 0;
       while(i<aLen && a[i] != '.'){
           n1 = n1 * 10 + 1ll*(a[i] - '0');
           i++;
       }
       while(j<bLen && b[j] != '.'){
           n2 = n2*10 + 1ll*(b[j] - '0');
           j++;
       }
       if(n1 < n2) return -1;
       else if(n1 > n2) return 1;
       i++; j++;
    }
    return 0;
}