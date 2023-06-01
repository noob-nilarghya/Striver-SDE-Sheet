#include <bits/stdc++.h>

bool comparator(vector<int>& v1, vector<int>& v2){
    return v1[1]>v2[1]; // sort by profit
}
int jobScheduling(vector<vector<int>> &jobs){
    // each job takes 1 day to complete & we can schedule only one job at a time. So, for each day, we can do atmax 1 job. 
    //So we pick the job with max profit & do it on the last day deadline. And we will perform the remaining most profitable job on previous days
    sort(jobs.begin(), jobs.end(), comparator); int profit=0; vector<int> schedule(3001, 0);
    for(int i=0; i<jobs.size(); i++){
        int deadLine=jobs[i][0]; int jobProfit=jobs[i][1];  // job with max profit comes first
        if(schedule[deadLine]==0){ // that day was not scheduled
            schedule[deadLine]=1;
            profit+=jobProfit;
        }
        else if(schedule[deadLine]==1 ){ 
        // That day was already occupied by some other job before [which has more profit than current job], 
        // so we can't reschedule this day for this job and have to find some other day from last for this job
            while(deadLine>0 && schedule[deadLine]==1){
                deadLine--;
            }
            if(deadLine>0 && schedule[deadLine]==0){ // we found a day
                schedule[deadLine]=1;
                profit+=jobProfit;
            }
        }
    }
    return profit;
}
