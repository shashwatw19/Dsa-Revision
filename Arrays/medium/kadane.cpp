// Given an integer array arr, find the contiguous subarray (containing at least one number) which
//has the largest sum and returns its sum and prints the subarray.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&nums){
    int maxSym = INT_MIN;
    for(int i = 0 ; i < nums.size() ; i++){
        int sum = 0;
        for(int j = i ; j < nums.size() ; j++){
            for(int k = i ; k <= j ; k++){
                sum+=nums[i];
                if(sum > maxSym){
                    maxSym = sum;
                }
            }
        }
    }
}
int better(vector<int>&nums){
    int maxSum = INT_MIN;
    for(int i = 0 ; i < nums.size() ; i++){
        int sum = 0;
        for(int j = i ; j < nums.size() ; j++){
            sum+=nums[j];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
int optimal(vector<int>&nums){
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0 ; i< nums.size() ; i++){
        sum+=nums[i];

        if(sum > maxSum){
            maxSum = sum;
        }

        if(sum < 0 ){
            sum = 0;
        }
    }
    return maxSum;
}
int main(){

}