// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

 

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
 
// just need to add a edge case what if start == mid == end ; then how would we identify the sorted half [3,1,2,3,3,3].  3 == 3 == 3
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
           int start = 0;
           int end = nums.size()-1;
           int mid = start + (end-start)/2;
           while(start<=end){
                if(nums[mid]==target){
                    return true;
                }
                else if(nums[mid] == nums[start]  &&  nums[start] == nums[end] ){
                    start++;
                    end--;
                    continue;
                }
                //left sorted
                else if(nums[start]<=nums[mid]){
                    //if value is present in the interval
                    if(nums[start]<=target && nums[mid]>=target){
                        end = mid -1;
                    }else{
                        start = mid + 1;
                    }
                }
                //right sorted
                else{
                     if(nums[mid]<=target && nums[end]>=target){
                        start = mid +1;
                    }else{
                        end= mid - 1;
                    }
                }
                mid = start + (end-start)/2;
           }
           return false;
    }
