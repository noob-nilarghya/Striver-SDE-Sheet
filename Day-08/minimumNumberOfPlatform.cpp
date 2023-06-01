int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n); // sort the arrival time
    sort(dt, dt+n); // sort the deprture time
    // Now apply 2 pointer technique to travel through times
    
    int platForm=0; int maxOccupancy=INT_MIN;
    int i=0; int j=0;
    while(i<n && j<n){
        if(at[i] <= dt[j]){
            platForm+=1; maxOccupancy=max(maxOccupancy, platForm);
            i++;
        }
        else if( at[i] > dt[j]){
            platForm-=1; maxOccupancy=max(maxOccupancy, platForm);
            j++;
        }
    }
    return maxOccupancy;
}