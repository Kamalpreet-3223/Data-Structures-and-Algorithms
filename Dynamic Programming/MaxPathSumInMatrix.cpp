#include <bits/stdc++.h> 
#include<vector>

int f(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp){
    if(j<0 || j>=m) return -1e9;
    if(i==0) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up = matrix[i][j] + f(i-1,j,matrix,n,m,dp);
    int dgleft = matrix[i][j] + f(i-1,j-1,matrix,n,m,dp);
    int dgright = matrix[i][j] + f(i-1,j+1,matrix,n,m,dp);
    return dp[i][j] = max({up, dgleft, dgright});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=INT_MIN;
    for(int i=0;i<m;i++){
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = f(n-1,i,matrix,n,m,dp);
        maxi=max(maxi,ans);
    }
    return maxi;
}

// TABULATION

// int getMaxPathSum(vector<vector<int>> &matrix)
// {
//     int n=matrix.size();
//     int m=matrix[0].size();
//     int maxi=-1e8;
//     vector<vector<int>>dp(n,vector<int>(m,0));
//     for(int j=0;j<m;j++) dp[0][j] = matrix[0][j];
//     for(int i=1;i<n;i++){
//         for(int j=0;j<m;j++){
//             int up=0,ld=0,rd=0;
//             up= matrix[i][j];
//             if(i>0) up += dp[i-1][j];
//             else up+= -1e8;
//             ld = matrix[i][j];
//             if(i>0 && j>0) ld+= dp[i-1][j-1];
//             else ld+=-1e8;
//             rd = matrix[i][j];
//             if(i>0 && j+1<m) rd+= dp[i-1][j+1];
//             else rd+=-1e8;
//             dp[i][j]= max({up,ld,rd});
//         }
//     }
//     for(int j=0;j<m;j++) maxi = max(maxi, dp[n-1][j]);
//     return maxi;
// }