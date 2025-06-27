//given an array of integers of size n . answer q queries where
//you need to print the sum of values in a given range of indices
//from l to r (both included)
//example -1 [a1 , a2 ,a3 , a4 , a5, a5,a7]
// l = 2 , r = 6 -> need to return the  sum from a2 to a6 inclusive
// l and r are 1 based indexing

#include<iostream>
using namespace std;
int findPrefixSum (int start , int end , vectot<int>&nums){
    int sum = 0;
    for(int i = start ; i < end ; i++){
        sum+=nums[i];
    }
    return sum;
}
int sum(vector<int>&nums , int l , int r){
    int prefixSumR = findPrefixSum(0 , r , nums)
    int prefixSumL = findPrefixSum(0 , l - 1  , nums)

    return prefixSumR - prefixSumL;
}
int main(){
    vector<int>nums = {5,1,2,3,4};
    cout<<sum(nums , 2 , 4);
}