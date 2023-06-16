class Solution {
public:
    int fact(int n){
        if(n==0) return 1;
        return n*fact(n-1);
    }
    void func(int n, string s, int k, string & ans){
        if(n==1){
            ans+=s[0];
            return;
        }
        int x=fact(n-1);
        int y=k/x;
        ans+=s[y];
        k=k%x;
        s.erase(y,1);
        func(n-1,s,k,ans);

    }

    string getPermutation(int n, int k) {
        string s,ans;
        for(int i=0;i<n;i++){
            s+=to_string(i+1);
        }
        func(n,s,k-1,ans);
        return ans;
    }
};