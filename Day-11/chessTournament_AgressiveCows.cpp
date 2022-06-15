// I wants to assign the players to the hotel rooms, such that the MINIMUM DISTANCE between any two of them is AS LARGE AS POSSIBLE. What is the largest minimum distance?
// We are performing BS over that minimum distance & try to hit that largest minimum distance through BS
// Problem on "BS ON ANS". Similar to: coco eating banana, Allocate pages .

bool isPossible(vector<int>& position, int c, int gap){
    int cnt=1; int prev=position[0];
    for(int i=1; i<position.size(); i++){
        if(position[i]-prev >=gap ){
            cnt++; // place another chess player there
            prev=position[i];
        }
        if(cnt==c){ return true; }
    }
    return false;
}

int chessTournament(vector<int> position , int n ,  int c){
	sort(position.begin(), position.end());
    int low=1; int high=position[n-1]-position[0];  // BS over the gap
    int ans=-1;
    
    while(low<=high){
        int mid=low+(high-low)/2; 
        if(isPossible(position, c, mid)==true){
            ans=mid;
            low=mid+1; // as we have to maximise the profit
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}