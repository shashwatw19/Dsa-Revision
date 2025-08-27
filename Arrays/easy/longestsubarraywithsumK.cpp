//find the length longest subarray with sum k
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&arr , int k){
    int maxlength = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int sum = 0;
        
        for(int j = i ; j < arr.size() ; j++ ){
            sum+=arr[j];
            if(sum==k){
                maxlength = max(maxlength , j-i+1);
            }
        }
    }
    return maxlength;
}
//using hashing ... optimal if the array has +ve and -negatives
//time complexity O(N * logN) if using orderedMap
//time complexiy O(N* 1) but can go upto N*N if using unorderedMap

//space complexity O(N) 
int method2(vector<int>&arr , int k){
    map<int , int>presumMap;
    int maxLen = 0;
    int sum = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        sum+=arr[i];
        if(sum == k){
            maxLen = max(maxLen , i+1);
        }
        int rem = sum - k;
        if(presumMap.find(rem) != presumMap.end()){
            int len = i - presumMap[rem];
            maxLen = max(maxLen , len);
        }
        if(presumMap.find(sum) == presumMap.end())
            presumMap[sum] = i;
    }

    return maxLen;
}    
//using two pointer
//time complexity -> O(2N)
//space complexity -> O(1)
//words only if all the elements are non negatives
int method3(vector<int>&arr , int k){
    int left = 0;
    int right = 0;
    int count = 0;
    int sum = 0;
    while(right < arr.size()){
        sum += arr[right];
        while(sum > k && left <= right){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            count = max(count , right - left + 1);
        }
        right++;
    }
    return count;
}
int main(){
    vector<int>arr = {2, 3, 5, 1, 9};
    cout<<brute(arr , 10);cout<<endl;
    cout<<method2(arr , 10);cout<<endl;
    cout<<method3(arr , 10);
}