// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2



//using hashing
//time complexity O(n log n)
//space complexity O(N)
int majorityElement(vector<int>& nums) {
    map<int,int>mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    for(auto it : nums){
        if(mpp[it] > nums.size()/2)
            return it;
        }
    return -1;
}

// using moores voting algorythm
//optimal approch 
//time complexity O(2N)
//space complexity O(1)
int majorityElement(vector<int>& nums) {
        int count = 0; int ele = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        int countMax = 0;
        for(auto it : nums){
            if(it == ele)
                countMax++;
        }

        if(countMax > nums.size()/2)
            return ele;
        return -1;
    }