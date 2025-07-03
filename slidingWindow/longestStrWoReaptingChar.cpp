// l.c 3
// Given a string s, find the length of the longest substring without duplicate characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//time complexity O(n*n)
//space complexity O(256)
int brute(string s){
    int maxLength = 0;
    for(int i = 0 ; i < s.size() ; i++){
        unordered_map<int , int>mpp;
            
        for(int j = i ; j <  s.size() ; j++){
            if(mpp.find(s[j]) != mpp.end()){
                    break;
            }
            maxLength = max(maxLength , j-i+1);
            mpp[s[j]] = j;
        }
    }
    return maxLength;
}
int better(string s){
    unordered_map<int ,int>mpp;
    int l = 0;
    int r = 0;
    int maxLength = 0;
    while(r < s.size()){
        if(mpp.find(s[r]) != mpp.end()){
            //move l only in mpp[s[r]] is in window
            if(mpp[s[r]] >=l){
                l = mpp[s[r]] +1;
            }
        }
        int len = r-l+1;
        maxLength = max(maxLength , len);
        mpp[s[r]] = r;
        r++;
    }
    return maxLength;
}
int main(){
   cout<<brute("abcabcbb");
   cout<<better("abcabcbb");
}