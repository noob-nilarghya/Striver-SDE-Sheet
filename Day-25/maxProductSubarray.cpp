// BRUTE FORCE
int maximumProduct(vector<int> &arr, int n){
	int mxPr=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        int prdt=1;
        for(int j=i; j<arr.size(); j++){
            prdt*=arr[j];
            mxPr=max(mxPr,prdt);
        }
    }
    return mxPr;
}

// OPTIMIZED
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        // Left Scan
        int maxi=1; int finalMax=INT_MIN;
        for(int i=0; i<arr.size(); i++){
            maxi*=arr[i];
            finalMax=max(finalMax, maxi);
            if(maxi==0){
                maxi=1;
            }
        }
        
        // Right Scan
        int maxi2=1; int finalMax2=INT_MIN;
        for(int i=arr.size()-1; i>=0; i--){
            maxi2*=arr[i];
            finalMax2=max(finalMax2, maxi2);
            if(maxi2==0){
                maxi2=1;
            }
        }
        
        return max(finalMax, finalMax2);
    }
};