#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coins=0;
    int stand[9]={1,2,5,10,20,50,100,500,1000};
    
    int i=8;
    while(i>=0){
        while(amount>=stand[i]){
            coins++;
            amount-=stand[i];
        }
        i--;
    }
    return coins;
}
