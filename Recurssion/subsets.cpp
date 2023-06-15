class Solution {
public:
    void func(int ind,vector<int>& nums,int n,set<vector<int>>& ans, vector<int> op){
        if(ind==n){
            sort(op.begin(),op.end());
            ans.insert(op);
            return;
        }
        vector<int> op1=op,op2=op;
        op2.push_back(nums[ind]);
        ind++;
        func(ind,nums,n,ans,op1);
        func(ind,nums,n,ans,op2);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> op;
        int n=nums.size();
        func(0,nums,n,ans,op);
        vector<vector<int>> final(ans.begin(),ans.end());
        
        return final;
    }
};