class Solution {
public:
    void func(int ind, int n,int target, vector<int>& candidates, vector<vector<int>>& ans,vector<int> op){
        if(ind==n){
            if(target==0){
                ans.push_back(op);
                return;
            }
            else{
                return;
            }
        }

        vector<int> op1=op,op2=op;
        if(target-candidates[ind]>=0){
            op1.push_back(candidates[ind]);
            func(ind,n,target-candidates[ind],candidates,ans,op1);
        }
        func(ind+1,n,target,candidates,ans,op2);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int n=candidates.size();
        func(0,n,target,candidates,ans,op);
        return ans;
    }
};