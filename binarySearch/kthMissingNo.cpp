// array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.
// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:
// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.#include<iostream>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&nums , int k){
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] <= k){
            k++;
        }
        else{
            return k;
        }
    }
    return -1;
}
int main(){
    vector<int>nums = {2,3,4,7,11};
    cout<<brute(nums , 5);
}