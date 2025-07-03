//lc. 930
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.
// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:
// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&nums , int goal){
    int count = 0;
    for(int i = 0 ; i < nums.size() ; i++){
   
        for(int j = i ; j < nums.size() ; j++){
                 int sum = 0;
            for(int k = i ; k <= j ; k++){
                sum+=nums[k];
            }
            if(sum==goal)
                count++;
        }
    }
    return count;
}
int better(vector<int>&nums , int goal){
    int count = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        int sum = 0;
        for(int j = 0 ; j < nums.size() ; j++){
            sum+=nums[j];
            if(sum == goal)
                count ++;
        }
    }
    return count;
}
int numSubarraysWithSum_helper(vector<int>& nums , int goal){
        if(goal < 0)
            return 0;
        int l = 0 ; 
        int r = 0;
        int subbArrCount = 0;
        int count = 0;
        while(r < nums.size()){
            count+=nums[r];

            while(count > goal){
                count -= nums[l];
                l++;
            }
            subbArrCount += r - l + 1;
            r++;
        }
        return subbArrCount;
}
int numSubarraysWithSum(vector<int>& nums, int goal){
        
        int subArrCountOne = numSubarraysWithSum_helper(nums , goal);
        int subArrCountTwo = numSubarraysWithSum_helper(nums , goal-1);

        return (subArrCountOne - subArrCountTwo);
}
int main(){
    vector<int>nums = {1,0,1,0,1};
    cout<<brute(nums , 2);
}