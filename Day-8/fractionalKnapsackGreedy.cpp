#include <bits/stdc++.h>

bool comparator(pair<double, int>& p1, pair<double, int>& p2){
    return p1.first>p2.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w){
    // ITEMS contains {weight, value} pairs.
    // We will pick guy with "MAX VAL/WT" guy !
    vector<pair<double, int>> vec;
    for(int i=0; i<items.size(); i++){
        double valPerWt= (double)items[i].second/items[i].first;
        vec.push_back({valPerWt, i});
    }
    
    // Now we will sort vec in ascending val/wt ratio
    sort(vec.begin(), vec.end(), comparator);
    double profit=0;
    for(int i=0; i<vec.size(); i++){ // pairs will come in max val/wt pattern
        int idx=vec[i].second; 
        int weight=items[idx].first;
        int val=items[idx].second;
        if(weight>=w){
            double fractionalVal= ((double)val*w)/weight;
            profit+=fractionalVal;
            w=0; return profit;
        }
        else if(weight < w){
            w-=weight;
            profit+=val;
        }
    }
    return profit;
}