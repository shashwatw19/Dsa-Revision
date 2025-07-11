// l.c 1482
// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
// Example 1:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:
// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:
// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int noOfFlowersBloomed(vector<int>&bloomsDay , int day , int m , int k){
    int flowers = 0; int cnt = 0;
    for(int i = 0 ; i < bloomsDay.size() ; i++){
        if(bloomsDay[i] <= day){
            flowers++;
        }else{
            cnt += flowers/k;
            flowers = 0;
        }
    }
    cnt += flowers/k;  // Count the last sequence
    return cnt >= m ? 1 : 0;
}


// Time Complexity: O((max - min) × n)
int brute(vector<int>&bloomsDay , int m , int k){
    // Check if it's impossible to make m bouquets
    if(m * k > bloomsDay.size()) return -1;
    
    int start = *min_element(bloomsDay.begin() , bloomsDay.end());
    int end = *max_element(bloomsDay.begin() , bloomsDay.end());

    for(int i = start ; i <=end ; i++){
        int noOfBouquets = noOfFlowersBloomed(bloomsDay , i ,m , k);
        if(noOfBouquets >= m)
            return i;
    }
    return -1;
}


// Time Complexity: O(log(max - min) × n)
int optimal(vector<int>&bloomsDay , int m , int k){
    // Check if it's impossible to make m bouquets
    if(m * k > bloomsDay.size()) return -1;
    
    int start = *min_element(bloomsDay.begin() , bloomsDay.end());
    int end = *max_element(bloomsDay.begin() , bloomsDay.end());
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(noOfFlowersBloomed(bloomsDay , mid , m , k) == 1){
            ans = mid ;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
         mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    vector<int>nums = {1,10,3,10,2};
    cout<<optimal(nums ,  3 , 1);
}