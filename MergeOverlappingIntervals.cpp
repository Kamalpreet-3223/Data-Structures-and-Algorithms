vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            vector<int> interval;
            interval.push_back(intervals[i][0]);
            
            if(!ans.empty() && ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=(max(intervals[i][1],ans.back()[1]));
            }
            else{
                interval.push_back(intervals[i][1]);
                ans.push_back(interval);
            }
        }
        return ans;
    }