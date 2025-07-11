// leetcode -> 875
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.
// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int>&arr){
    int maxi = INT_MIN;
    for(int i = 0 ; i < arr.size() ; i++){
        maxi = max(arr[i] , maxi);
    }
    return maxi;
}

int minEatingSpeed(vector<int>&piles , int h){
    int maxTime = findMax(piles);
    for(int i = 1 ; i <=maxTime ; i++){
        int currTime = 0;
        for(int j = 0 ; j < piles.size() ; j++){
             currTime += ceil((double)piles[j]/(double)i);
        }
        if(currTime <= h)
            return i;
    }
    return -1;
}

// using binarySearch
int helper(vector<int>&piles , int hourly , int h){
    int time = 0;
    for(int i = 0 ; i < piles.size() ; i++ ){
       if(time + ceil(double(piles[i])/double(hourly)) > h){
        return 1;
       }
       time += ceil(double(piles[i])/double(hourly));
    }
    return 0;
}
int optimal(vector<int>piles , int h){
    int start = 1;
    int end = *max_element(piles.begin() , piles.end());
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        int finishTime = helper(piles , mid , h);
        if(finishTime == 0){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    vector<int>nums = {30,11,23,4,20};
    cout<<optimal(nums , 6);
}