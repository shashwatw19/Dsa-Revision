//leetcode 904
// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.
// Example 1:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:
// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:
// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].

//the problem statement can be shrinked to maximum subarray with atmost k elements

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>arr , int k){
    int maxCount = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int count = 1;
        for(int j = i ; i < arr.size() ; j++){
            if(arr[j] != arr[i]){
                count++;
            }
            if(count > k){
                 break;
            }
            maxCount = max(maxCount , j-i + 1);
               
        }
    }
    return maxCount;
}
//time complexity O(2n)
//space complexity O(1)
int better(vector<int>fruits , int k){
    unordered_map<int ,int>mpp;
    int r = 0;
    int l = 0;
    int maxLength = 0;
    while(r < fruits.size()){
        mpp[fruits[r]]++;
        while(mpp.size() > 2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0){
                mpp.erase(fruits[l]);
            }
            l++;
        }
        if(mpp.size() <=2){
            int length = r - l + 1;
            maxLength = max(maxLength ,length);
        }
        r++;
            
    }
        return maxLength;
}
//time complexity O(N)
//space complexity O(1)
int optimal(vector<int>fruits , int k){
    unordered_map<int ,int>mpp;
    int r = 0;
    int l = 0;
    int maxLength = 0;
    while(r < fruits.size()){
        mpp[fruits[r]]++;
        if(mpp.size() > 2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0){
                mpp.erase(fruits[l]);
            }
            l++;
        }
        if(mpp.size() <=2){
            int length = r - l + 1;
            maxLength = max(maxLength ,length);
        }
        r++;
            
    }
        return maxLength;
}
int main(){
    vector<int>arr = {1,2,3,2,2};
    cout<<optimal(arr , 2);
}