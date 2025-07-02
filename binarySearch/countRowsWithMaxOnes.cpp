//given a 2d array return the row with max no of ones
// if we can find the lower bound of the 1 then the count of one in a particular row will be (n - lowerbound) . where n is the size of the row
// find the count of ones in all rows and return the max count
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findRowCount(vector<int>&arr){
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == 0){
            start = mid + 1;  
        } else {
            end = mid - 1;    
        }
    }
    // start now points to the first 1 (or arr.size() if no 1s)
    cout << "onesCount: " << arr.size() - start << endl;
    return arr.size() - start;
}
// time complexity o(N*log(m))
int maxCountRow(vector<vector<int>>&arr){
    int maxCount = INT_MIN;
    for(int i = 0 ; i < arr.size() ; i++){
        maxCount = max(maxCount , findRowCount(arr[i]));
        
    }
    return maxCount;
}
int main(){
    vector<vector<int>>arr = {{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    cout<<maxCountRow(arr);
}