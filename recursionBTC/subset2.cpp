// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.


class Solution {
public:
    void subsetsWithDup_helper(vector<int>&nums , vector<int>&temp , vector<vector<int>>&ans , int index){
        ans.push_back(temp);
        if(index == nums.size())
            return;

        for(int i = index ; i < nums.size() ; i++){
            if(i > index && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            subsetsWithDup_helper(nums,temp,ans , i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        subsetsWithDup_helper(nums , temp , ans , 0);
        return ans;
    }
};