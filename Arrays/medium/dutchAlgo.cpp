// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

void method1(vector<int>& nums) {
    int zeroCount = 0;
    int onesCount = 0;
    int twoCount = 0;
    for(auto ele : nums){
        if(ele == 1){
            onesCount++;
        }
        else if(ele == 2){
            twoCount++;
        }
        else{
            zeroCount++;
            }
        }

        int index = 0;
        while(zeroCount){
            nums[index++] = 0;
            zeroCount--; 
        }
        while(onesCount){
            nums[index++] = 1;
            onesCount--;
        }
        while(twoCount){
            nums[index++] = 2;
            twoCount--;
        }
        
}

 void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low] , nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid] , nums[high]);
                high--;
            }else{
                mid++;
            }
        }
    }