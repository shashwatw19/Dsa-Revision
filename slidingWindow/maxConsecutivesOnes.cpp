//l.c 1004
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&nums , int k){
    int maxLength = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        int count = 0;
        for(int j = i ; j < nums.size() ; j++){
            if(nums[j] == 0)
                count++;
            if(count > k)
                break;
         
            maxLength = max(maxLength , j-i+1);
         
        }
    }

    return maxLength;
}
//time complexity O(2N)
//space complexity O(1);
int better(vector<int>&nums , int k){
    int r = 0;
    int l = 0;
    int maxLength = 0;
    int zeroCount = 0;
    //o(N)
    while(r < nums.size()){
        if(nums[r] == 0)
            zeroCount++;
        //O(N)  -> not always n time , n times in part ... example when the while will run n time 1,1,1,1,0,0, where k = 1; 
        while(zeroCount > k){
            if(nums[l] == 0)
                zeroCount--;
            l++;
        }
        if(zeroCount <=k){
            int len = r-l+1;
            maxLength = max(maxLength , len);
            
        }
        r++;
    }
    return maxLength;
}
//time complexity O(N)
//space complexity O(1)
int optimal(vector<int>&nums , int k){
    int r = 0;
    int l = 0;
    int maxLength = 0;
    int zeroCount = 0;
    //o(N)
    while(r < nums.size()){
        if(nums[r] == 0)
            zeroCount++;
       //not allowing the maxLength to increase , mainting constant window size till zeros are greater than k
        if(zeroCount > k){
            if(nums[l] == 0)
                zeroCount--;
            l++;
        }
        if(zeroCount <=k){
            int len = r-l+1;
            maxLength = max(maxLength , len);
            
        }
        r++;
    }
    return maxLength;
}
int main(){
    vector<int>nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout<<brute(nums , 3)<<endl;
    cout<<better(nums , 3)<<endl;
    cout<<optimal(nums , 3)<<endl;

}