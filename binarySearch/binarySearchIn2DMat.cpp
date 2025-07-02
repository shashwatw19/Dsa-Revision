//l.c 74
//you need to search a target value in a matrix which os sorted row wise
// return true if value if found else return false


// method 1 -> you can traver each row and apply binary search on that row . t.c o(n*log(m))
//method 2 -> apply binary search in 2d matrix 
//where row = indx/m && col = indx/m . m is the no. of rows

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>>&arr , int target){
    int n = arr.size();
    int m = arr[0].size();
    int start = 0;
    int end = n*m-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        int row = mid/m;
        int col = mid%m;
        if(arr[row][col] == target){
            return true;
        }
        else if(arr[row][col] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return false;
}
