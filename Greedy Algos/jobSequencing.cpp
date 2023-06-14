#include <bits/stdc++.h> 
bool comparison(vector<int> a, vector<int> b){
    return (a[1]>b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comparison);
    int n=jobs.size();
    int maxi=jobs[0][0];
    for(int i=1;i<n;i++){
        if(maxi<jobs[i][0]) maxi=jobs[i][0];
    }
    int slots[maxi+1];
    for(int i=0;i<maxi+1;i++){
        slots[i]=-1;
    }
    int maxProfit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(slots[j]==-1){
                slots[j]=jobs[i][1];
                maxProfit+=jobs[i][1];
                break;
            }
        }
    }
    return maxProfit;

}
