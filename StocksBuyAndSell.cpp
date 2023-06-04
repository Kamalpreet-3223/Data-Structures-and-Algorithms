#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int n= prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            int p = prices[i] - mini;
            profit=max(profit,p);
            mini = min(mini, prices[i]);
        }
        return profit;
}

int main(){
    vector<int> nums;
    int n;
    cout<<"Enter no. of days: ";
    cin>>n;
    int num[n];
    cout<<"Enter prices: ";
    for(int i=0;i<n;i++){
        cin>>num[i];
        nums.push_back(num[i]);
    }
    int maxP = maxProfit(nums);
    cout<<"Max is "<<maxP<<endl;
    return 0;
}