//no of subarrays with sum k
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//brute force -> generate all the subarrays
//time complexity O(n^3);
int method1(vector<int>&arr , int k){
    int count = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = i ; j < arr.size() ; j++){
            int sum = 0 ;
            for(int k = i ; k <= j ; k++){
                sum+=arr[k];
              
            }
            if(sum==k){
                count++;
            }
        }
    }
    return count;

}
//brute force -> generate all the subarrays
//time complexity O(n^2);
int method2(vector<int>&arr , int k){
    int count = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int sum = 0;
        for(int j = i ; j < arr.size() ; j++){
            sum+=arr[j];
            if(sum==k)
                count++;
        }   
    }
    return count;
}
//optimal approch.

// For each index, you check how many times a prefix sum of presum - k has occurred.
// Each occurrence means a valid subarray ending at the current index.
// This approach efficiently counts all such subarrays in one pass.

// "How many times have I seen a prefix sum equal to presum - k?"
// Each occurrence means there is a subarray ending at i with sum k.


//time complexity 
// O(n*logN)   -> if we take map ..... if we unordered map O(N*1) or in worst case O(N*N) 
// space complexity
// O(N)
int subarraySum(vector<int>& nums, int k) {
    map<int , int>preSumMap;
    preSumMap[0] = 1;
    int count = 0;
    int presum = 0;
    for(int i = 0; i < nums.size() ; i++){
        presum += nums[i];
        int remove = presum - k;
        count += preSumMap[remove];
        preSumMap[presum]++;
    }
    return count;
} 
int main(){
    vector<int>arr = {1,1,1};
    cout<<method2(arr , 2);
}