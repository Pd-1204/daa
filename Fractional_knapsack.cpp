#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//value/weight

struct item{
    int val,wt;
    item(int val, int wt){
        this->val=val;
        this->wt= wt;
    }
};
bool cmp(struct item a, struct item b){
    double r1= (double)a.val/(double)a.wt;
    double r2= (double)b.val/(double)b.wt;
}
double frac(int W, struct item arr[], int n){
    sort(arr, arr+n, cmp);
    double final=0.0;
    for(int i=0;i<n;i++){
        if(arr[i].wt <=W){
            W-=arr[i].wt;
            final+=arr[i].val;
        }
        else{
            final+=arr[i].val * (double)W/(double)arr[i].wt  ;      }
    }
    return final;
}

int main(){
    int W=50;
    item arr[] ={{60,10}, {100,20}, {120, 30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Ans"<<frac(W,arr,n);
    return 0;
}