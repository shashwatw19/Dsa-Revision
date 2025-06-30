#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//peak index property -> arri[i-1] < arr[i] > arr[i+1]
int bruteFore(vector<int>&arr){
    int n = arr.size();
    if(n==1)
        return arr[0];
    for(int i = 0 ; i < arr.size() ; i++){
        if((i==0 || arr[i-1] < arr[i]) && (i==n-1 || arr[i] > arr[i+1])){
            return i;
        }
    }
}
int findPeakIndex(vector<int>&nums){
    int n = nums.size();
    if(n == 1)
        return 0;
    else if(nums[0] > nums[1]){
        return 0;
    }
    else if(nums[n-1] > nums[n-2]){
        return n-1;
    }

    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        // increasing curve
        else if(nums[mid] < nums[mid-1] ){
            start = mid + 1;
        }
        // decreasing curve as well as for the reverse peak * . *  when mid is .    
        else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    
}
