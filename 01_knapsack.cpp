#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int capacity=10;
    int items=4;
    int price[items+1]={0,2,7,3,9};
    int wt[items+1] ={0,2,2,4,5};
    int dp[items+1][capacity+1];
    for(int i=0;i<=items;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i]<=j){
                dp[i][j]=max( dp[i-1][j] , price[i]+ dp[i-1][j-wt[i]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<"max profit earned  "<<dp[items][capacity];
    return 0;
}