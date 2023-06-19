#include<iostream>
using namespace std;

void solve(int n, int s, int d, int h, int& c){
    c++;
    if(n==1){
        cout<<c<<".  "<<"Moving plate "<< n <<" from "<< s <<" to "<<d<<endl;
        return;
    }
    solve(n-1,s,h,d,c);
    cout<<c<<".  "<<"Moving plate "<< n <<" from "<< s <<" to "<<d<<endl;
    solve(n-1,h,d,s,c);
    
}

int main(){
    int n;
    cout<<"ENTER N: ";
    cin>>n;
    int s=1,h=2,d=3,c=0;
    solve(n,s,d,h,c);
    return 0;
}