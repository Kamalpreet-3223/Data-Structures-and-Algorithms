#include<iostream>
#include<vector>
using namespace std;

void generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 1){
            vector<int> row2;
            row2.push_back(1);
            ans.push_back(row2);
        }
        else if(numRows == 2){
            vector<int> row2;
            row2.push_back(1);
            ans.push_back(row2);
            row2.push_back(1);
            ans.push_back(row2);
        }
        else{
            vector<int> row2;
            row2.push_back(1);
            ans.push_back(row2);
            row2.push_back(1);
            ans.push_back(row2);
            for(int i=1;i<numRows-1;i++){
                vector<int> row;
                row.push_back(1);
                for(int j=0;j<=i-1;j++){
                    int temp;
                    temp = ans[i][j] + ans[i][j+1];
                    row.push_back(temp);
                }
                row.push_back(1);
                ans.push_back(row);
            }
        }
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

int main(){
    int n;
    cin>>n;
    generate(n);
    return 0;
}