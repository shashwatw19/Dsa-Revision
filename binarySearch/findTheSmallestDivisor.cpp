// lc 1283
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
// The test cases are generated so that there will be an answer.
// Example 1:
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
// Example 2:
// Input: nums = [44,22,33

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute force
int brute(vector<int>&nums , int threshold){
    int maxElement = *max_element(nums.begin() , nums.end());
    for(int i = 1 ; i <= maxElement ; i++){
        int result = 0;
        for(int j = 0 ; j < nums.size() ; j++){
            result+= ceil(double(nums[j])/double(i));
        }
        if(result <= threshold)
            return i;
    }
    return -1;
}



//time complexity log(max)*n
bool helper(vector<int>& nums, int mid , int threshold){
        int result = 0;
        for(int i = 0 ; i < nums.size() ; i++){
           result += ceil(double(nums[i])/double(mid));
        }
        return result <= threshold ? true : false;
}
int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin() , nums.end());
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            if(helper(nums , mid , threshold)){
                ans = mid ;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
}   
