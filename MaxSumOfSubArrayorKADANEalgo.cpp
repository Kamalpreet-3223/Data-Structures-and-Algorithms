#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    int n = nums.size();
    
    for(int i = 1; i < n; i++){
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main(){
    vector<int> nums;
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int num[n];
    cout<<"Enter vector: ";
    for(int i=0;i<n;i++){
        cin>>num[i];
        nums.push_back(num[i]);
    }
    int maxSumSubArray = maxSubArray(nums);
    cout<<"Max is "<<maxSumSubArray<<endl;
    return 0;
}