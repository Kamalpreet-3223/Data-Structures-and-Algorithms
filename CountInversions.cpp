#include <bits/stdc++.h> 

long long cnt=0;

void merge(long long *arr, long long low, long long mid, long long high){
    long long left=low, right=mid+1;
    vector<long long> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(long long i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(long long *arr, long long low, long long high){
    if(low>=high) return;
    long long mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1,high);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n){
    mergeSort(arr,0,n-1);
    return cnt;
}