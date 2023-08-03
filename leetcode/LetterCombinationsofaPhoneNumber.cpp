class Solution {
public:
    void func(vector<string> & ans,vector<string> vec){
        vector<string> ans2;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<vec.size();j++){
                ans2.push_back(ans[i]+vec[j]);
            }
        }
        ans=ans2;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char,vector<string>> mpp;
        mpp['2']={"a","b","c"};
        mpp['3']={"d","e","f"};
        mpp['4']={"g","h","i"};
        mpp['5']={"j","k","l"};
        mpp['6']={"m","n","o"};
        mpp['7']={"p","q","r","s"};
        mpp['8']={"t","u","v"};
        mpp['9']={"w","x","y","z"};
        if(digits.size()==1) return mpp[digits[0]];
        if(digits.size()==0) return ans;
        for(int i=0;i<digits.size()-1;i++){
            if(i==0) ans=mpp[digits[0]];
            func(ans,mpp[digits[i+1]]);
        }
        return ans;
    }
};