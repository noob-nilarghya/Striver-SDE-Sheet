
long double mul(double mid, int n){
    long double res=1.0;
    while(n--){
        res*=mid;
    }
    return res;
}
double findNthRootOfM(int n, long long m) {
    long double low=1; long double high=m; long double mid; double e=1e-7;
    while(high-low > e){
        mid=(high+low)/2.0;
        long double num=mul(mid,n);
        
        if(num > m){ // decrese mid, go left
            high=mid;
        }else{
            low=mid;
        }
    }
    return low;
}