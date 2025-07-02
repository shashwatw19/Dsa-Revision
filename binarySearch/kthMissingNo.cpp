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
// 1 .the ans will be arr[high] + more
// 2.more = k - missing
// 3. missing = arr[high] - (high + 1) or we can say (high + 1) as index + 1 . but at the end the hight crosses low . therefore we can take high instead of index
// putting value of missing in eq 2 and value of more from eq2 in eq1 we get arr[high] + k - arr[high] + high + 1
// so final answer = k + high + 1 || k + low 
// bsc at the end low crosses

int optimal(vector<int>&nums , int k){
    int start = 0;
    int end = nums.size() - 1;
    int mid = start + (end-start)/2;
    while(start<=end){
        int missing = nums[mid] - (mid + 1);
        if(missing < k){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return k + end + 1;
}
int main(){
    vector<int>nums = {2,3,4,7,11};
    cout<<brute(nums , 5);
}