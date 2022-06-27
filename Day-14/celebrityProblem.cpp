// Approach 1:

int findCelebrity(int n) {
 	vector<int> inDeg(n, 0);
    vector<int> outDeg(n, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j && knows(i,j)==true){
                // i know j [ i-->j ]
                outDeg[i]++;
                inDeg[j]++;
            }
        }
    }
    // Every persons inDeg and outDeg has been stored.

    // Now we need to find celebrity [whose inDeg is n-1 but outDeg is 0]
    for(int i=0; i<n; i++){
        if(inDeg[i]==n-1 && outDeg[i]==0){
            return i;
        }
    }
    return -1; // no celebrity found
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)

//-----------------------------------------------------------------------------------------------------

// Approach 2: 

// This is something like Moore Vooting Algorithm. Where whe assume something as our answer & then verify it
// We will somewhat approach greedily !

int findCelebrity(int n) {
 	int c=0;
    for(int i=1;i<n;i++){
        if(knows(c,i)==true){ // c knows i
            c=i;
        }
    }
    // Our assumption: 'c' is celebrity
    
    for(int i=0;i<n;i++){
        if(i!=c && (knows(c,i)==1 || knows(i,c)==0)){
            // If 'c' knows anyone OR anyone don't know 'c' --> Our assumption was wront
            return -1;
        }
    }
    return c;
}