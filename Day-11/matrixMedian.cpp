// VERY VERY IMP 
int lessThanEqualTo(vector<int>& vec, int num){
    int low=0; int high=vec.size()-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(vec[mid] < num){
            low=mid+1;
        }
        else if(vec[mid]==num){
            low=mid+1;
        }
        else if(vec[mid] > num){
            high=mid-1;
        }
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix){
    int low=1; int high=1e5; int row=matrix.size(); int col=matrix[0].size();
    
    while(low<=high){
        int mid= low+(high-low)/2; int cnt=0;
        for(int i=0; i<row; i++){
            cnt+=lessThanEqualTo(matrix[i], mid);
        }
        if(cnt <= (row*col)/2){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
