#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
    // ans is n'Cr  as ->   m-1 right jana hoga  and  n-1 down jana hoga
    // so n+m-2 total steps chahiye and bs iske combinations
    int N = n+m-2;
    int r = m-1;
    long long res = 1;
    for(int i=1;i<=r;i++){
        res = res*(N-r+i)/i;
    }
    return (int)res;
}

int main(){
    int n,m;
    cout<<"Enter rows and columns: ";
    cin>>n;
    cin>>m;
    int NumberOfPaths = uniquePaths(n,m);
    cout<<"Total no. of unique paths are : "<<NumberOfPaths<<endl;
    return 0;
}