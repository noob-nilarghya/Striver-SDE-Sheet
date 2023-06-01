int deno[]={1,2,5,10,20,50,100,500,1000};
// We think greedyly. For any amount, we pick that denomination which is less than amount but most closest to amount, 
//and pass rest of the amount to recursion

int findMinimumCoins(int amount) {
    if(amount==0){ return 0; }
    int idx=-1;
    for(int i=0; i<9; i++){ // we pick that denomination which is less than amount but most closest to amount
        if(amount <= deno[i]){
            if(amount==deno[i]){ return 1; }
            idx=i-1; break;
        }
    }
    if(idx==-1){ // amount is >1000
        amount-=1000;
    }
    else{
        amount-=deno[idx];
    }
    return 1+findMinimumCoins(amount);
}
