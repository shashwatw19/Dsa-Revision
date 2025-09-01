// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security 
// systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int rob_util(vector<int>&nums , int index){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    //can rob this house
    int option1 = nums[index] + rob_util(nums , index+2);

    //can leave this house
    int option2 = 0 + rob_util(nums , index+1);

    return max(option1 , option2);
}
int rob(vector<int>& nums){
    return rob_util(nums , 0);
}
int main(){
    vector<int>nums = {1,2,3,1};
    cout<<rob(nums);
}