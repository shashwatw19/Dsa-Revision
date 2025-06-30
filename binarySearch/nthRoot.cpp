// find the nth root of a no. example 3rd root of 27 is 3
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(int n , int num){
    for(int i = 1 ; i < num ; i++){
        if(pow(i , n) == num)
            return i;
        else if(pow(i , n ) > num)
            break;
    }
    return -1;
}
int helper(int mid , int n , int m){
    long long ans = 1;
    for(int i = 1 ; i<=n ; i++){
        ans = ans*mid;
        if(ans > m)
            return 2;
    }
    if(ans == m)
        return 1;
    return 0;
}
int optimal(int n ,int num){
    int start = 1;
    int end = num;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(helper(mid , n , num) == 1){
            return mid;
        }
        else if(helper(mid , n , num ) == 2){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    
    cout<<optimal(3 , 27);
}