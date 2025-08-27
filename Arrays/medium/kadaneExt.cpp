// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23

// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
            
            if(sum > maxi){
                maxi = sum;
            }

            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
}

//printing subarray with max sum
int maxSumSubArray(vector<int>& arr) {
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0, ansStart = 0, ansEnd = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (sum == 0) {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    // Optionally print the subarray:
    // for (int i = ansStart; i <= ansEnd; i++) cout << arr[i] << " ";
    // cout << endl;
    return maxi;
}
