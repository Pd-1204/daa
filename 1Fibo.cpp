#include<iostream>
#include<vector>

using namespace std;

int fibo(int n){
    
    if(n==1 || n==0){
        return 1;
    }
    
     return fibo(n-1)+ fibo(n-2);
    
}
void iter(int n){
    
    int t1=0,t2=1;
    cout<<t2<<" ";
    for(int i=2;i<=n;i++){
        int next=t1+t2;
        t1=t2;
        t2=next;
        cout<<next<<" ";
    }
   
}

int main(){
    int n, i=0;
    cout<<"enter n";
    cin>>n;
    cout<<"Recursion : "<<endl;
    while(i<n){
        cout<<fibo(i)<<" ";
        i++;
    }
    cout<<endl;
    cout<<"iteration : "<<endl;
    iter(n);
    return 0;
}