// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//time complexity O(n-m*m)
//since nm > m O(nm)
int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    for(int i = 0 ; i < n-m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(haystack[i+j] != needle[j])
                break;
            else if(j == m-1){
                return i;
            }
        }
    }
    return -1;
}   
//using stl   
int strStr2(string haystack , string needle){
    int pos = haystack.find(needle);
    return pos != string::npos ? pos : -1;
}