//l.c 5
// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:
// Input: s = "cbbd"
// Output: "bb"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//time complexity O(n*n*n)

bool isPalindrome(string &s , int start , int end){
        while(start<=end){
            if(s[start]!=s[end])
                return false;

            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0 ; i <s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                if(isPalindrome(s , i , j)){
                    string subStr = s.substr(i , j-i+1);
                    if(subStr.size() > ans.size()){
                        ans = subStr;
                    }
                }
            }
        }
        return ans;
    }