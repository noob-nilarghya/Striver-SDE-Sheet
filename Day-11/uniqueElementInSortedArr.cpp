// XOR OPERATION: O(N)
int uniqueElement(vector<int> arr, int n){
    int Xor=0;
    for(int i=0; i<n; i++){
        Xor=Xor^arr[i];
    }
    return Xor;
}

// BINARY SEARCH: O(logN)
int uniqueElement(vector<int> arr, int n){
    if(n==1){ return arr[0]; }
	int low=0; int high=n-1; int mid;
    
    while(low<=high){
        mid=low+(high-low)/2;
        if( (mid==0 && arr[mid] != arr[mid+1]) ||
            (mid==n-1 && arr[mid] != arr[mid-1]) ||
            (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) ){
            return arr[mid];
        }
        else if(mid %2 ==0){ // I am at even index
            if(mid+1<n && arr[mid] != arr[mid+1]){ // we are in right half, so go to left half
                high=mid-1;
            }
            else{ // go to right half
                low=mid+1;
            }
        }
        else if( mid%2 == 1){ // I am at odd index
            if(mid-1>=0 && arr[mid] != arr[mid-1]){ // we are in right half, so go to left half
                high=mid-1;
            }
            else{ // go to right half
                low=mid+1;
            }
        }
    }
    return arr[mid];
}
