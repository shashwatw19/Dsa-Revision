// check if we can partition the array into tow subarrays with equal sum
// more formally , check that the prefix sum of a part of the array is equal to the suffix sum
// of rest of the array
//prefix sum i = sum(a0.....ai)
//suffix sum i+1 = sum(ai+1 , an-1)
//prefixSumI + suffuxI = sum(n)
#include<iostream>
using namespace std;
int findSum(int start , int end , vector<int>&nums){
    if(start >= 0 && end < nums.size()){
        int sum =0;
        for(int i = start ; i <= end ; i++){
            sum+=nums[i];
        }
        return sum;
    }
    return start;
}
bool isValidArray(vector<int>&nums){
    int totalSum = findSum(0 , nums.size()-1 );
    
    int prefixSum = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        int prefixSum+=nums[i];
        int suffixSum = totalSum - prefixSum;
        if(prefixSum == suffixSum)
            return true;
    }
    return false;
}
int main(){
    vector<int>nums = {5,3,3,5};
    return isValidArray(nums)
}