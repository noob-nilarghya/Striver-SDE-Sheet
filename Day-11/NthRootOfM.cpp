
// Assuming m<=1e11

long long modExp(int base, int power){
    if(power==0){ return 1; }
    long long res=1;
    while(power){
        if(power&1==0){
            base= (base*base);
            if(base>1e11){ return LLONG_MAX; }
            power= power>>1;
        }
        else{
            res= (res*base);
            if(res>1e11){ return LLONG_MAX; }
            power--;
        }
    }
    return res;
}

int NthRoot(int n, int m) {
  // we need to find M^(1/N). so we would go in reverse
  // Using binary search we would try to find that value val where val^N == M
  if(n==1){ return m; }
  
  int power=n; int low= 1; int high=m;
  while(power>1){
    power= power>>1;
    high= (int)(sqrt(high));
  }

  while(low<=high){
    int mid= low+ (high-low)/2;
    long long tempVal= modExp(mid, n);  // mid^n
    if(tempVal==m){ return mid; }
    else if(tempVal<m){ low= mid+1; }
    else if(tempVal>m){ high= mid-1; }
  }
  return -1;
}