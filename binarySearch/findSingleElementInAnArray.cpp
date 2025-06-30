// you have given a sorted array in which all the elements are present in pairs . execpt one you need to return that element
// [1,1,2,2,3,3,4,4,5,6,6,7,7]
//in case of pairs the (ith elemenet == i-1 element || i+1 element)
//only the single element will be i != i-1 && i != i+1

//observation 2 -> if we do indexing of the array . we will get (event , odd) indexes for pairs . and after the single element we will get (add ,even)
// example [1,1,2,2,3,3,4,5,5] -> (1,1) , (2,2) , (3,3) has indexes as odd , even but 5,5 has a index of (odd , even)
// if the element is on right half (even , odd)
// if the element is on left half (odd , even)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>&arr){
    for(int i = 0; i < arr.size() ; i++){
        int n = arr.size();
        if(n==1){
            return arr[0];
        }
        if(i==0 && arr[i+1] != arr[i])
            return arr[0];
        else if(i==n-1 && arr[n-1] != arr[n-2]){
            return arr[n-1];
        }
        else{
            if(arr[i] != arr[i-1] || arr[i] != arr[i+1]){
                return arr[i];
            }
        }
    }
    return -1;
}

int search(vector<int>&arr){
    int n = arr.size();
    if(n==1)
        return arr[0];
    else if(arr[0] != arr[1]){
        return 0;
    }
    else if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }
    int start = 1;
    int end = n-2;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return mid;
        }
        else if(mid%2 == 1 && arr[mid] == arr[mid-1] || mid%2 == 0 && arr[mid] == arr[mid + 1]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){

}