//l.c 15
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> bruteForce(vector<int>& nums) {
    set<vector<int>>st;
    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = i+1 ; j < nums.size() ; j++){
            for(int k = j+1 ; k < nums.size() ; j++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int>temp = {nums[i] , nums[j] , nums[k]};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
        }
    }  
    vector<vector<int>>ans(st.begin() , st.end());
    return ans;      
}


//time complexity O(N^2 * logM)
//space complexity O(N) + O(No of unique triplets)

vector<vector<int>>better(vector<int>&nums){
     set<vector<int>>st;
    for(int i = 0 ; i < nums.size() ; i++){
        set<int>hashset;
        for(int j = i+1 ; j < nums.size() ; j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int>temp = {nums[i] , nums[j] , third};
                sort(temp.begin() , temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>>ans(st.begin() , st.end());
    return ans;    
} 


//intution 
//sort the arr
//i is fixed
//if(sum > 0) k--
//if(sum < 0) j++
//if (sum==0) store the triplets and move the j and k pointers until they are not unique and j < k to maintain the sorted order


//time complexity O(nlogn + n^2)
//space complexity O(no of unique triplets)
 vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin() , nums.end());
    for(int i = 0 ; i < nums.size() ; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = nums.size() - 1;
        while( j < k){
            int sum = nums[j] + nums[k] + nums[i];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int>temp = {nums[i] , nums[j] , nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while( j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}