#include<iostream>
#include<string.h>
using namespace std;

int canClose(string op){
    int o=0,c=0;
    for(int i=0;i<op.size();i++){
        if(op[i]=='('){
            o++;
        }
        if(op[i]==')'){
            c++;
        }
    }
    if(o>c){
        return 1;
    }
    return 0;
}

void solve(int& open,int& close, string op){
    if(close==0 && open==0){
        cout<<op<<endl;
        return;
    }
    string op1=op, op2=op;
    if(canClose(op)){
        op1.push_back(')');
        close--;
        solve(open,close,op1);
    }
    else if(open>0){
        op2.push_back('(');
        open--;
        solve(open,close,op2);
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    string op="";
    int open=n,close=n;
    solve(open,close,op);
    return 0;
}