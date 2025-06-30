#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(int n ){
    int ans = INT_MIN;
    for(int i = 1 ; i <=n ; i++){
        if(i*i <= n){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}
int optimal(int n){
    int start = 1;
    int end = n;
    int mid = start + (end-start)/2;
    int ans = 1;
    while(start<=end){
        if((mid*mid <= n)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    cout<<optimal(196);
}