// Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of 
//all elements equal to zero.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>&arr){
    map<int , int>mpp;
    int sum = 0;
    int maxLength = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        sum+=arr[i];
        if(sum==0){
            maxLength = i+1;
        }
        else if(mpp.find(sum) != mpp.end()){
            maxLength = max(maxLength , i - mpp[sum]);
        }
        else{
            mpp[sum] = i;
        }
    }
    return maxLength;
}
int main(){
    vector<int>arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<longestSubarray(arr);
}