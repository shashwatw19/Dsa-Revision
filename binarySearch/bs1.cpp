// implement lower bound and upper bound
// lower bound -> the smallest index such that arr[index] >= x . this should be in a sorted array.
// if the index doest occure the lower bound is default last index

// upper bound -> smallest index such that arr[index] > x . even if upper dont exists always have ans = size
#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>arr , int x){
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end ) /2;
    int ans = arr.size();
    while(start<=end){
        if(arr[mid] >= x){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}
int upperBound(vector<int>arr , int x){
    int start = 0;
    int end = arr.size() - 1;
    int ans = arr.size()-1;
    int mid = (start + end) / 2;
    while(start <=end){
        if(arr[mid] > x){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}
// simple binary Search 
int binarySearch(vector<int>arr , int key){
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end)/ 2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else {
             start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
int main(){
    vector<int>arr = {2,3,6,7,8,8,11,11,12};
    int a =  lowerBound(arr, 11);
    int b = upperBound(arr, 11);
    int c = binarySearch(arr, 11);
    cout<<a<<" "<<b<<" "<<c<<" ";
}