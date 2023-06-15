class Solution {
public:
    void func(int ind, int n,int target, vector<int>& candidates, set<vector<int>>& ans,vector<int> op){
        if(target==0){
            sort(op.begin(),op.end());
            ans.insert(op);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            op.push_back(candidates[i]);
            func(i+1,n,target-candidates[i],candidates,ans,op);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int> op;
        int n=candidates.size();
        func(0,n,target,candidates,ans,op);
        vector<vector<int>> final(ans.begin(),ans.end());
        return final;
    }
};