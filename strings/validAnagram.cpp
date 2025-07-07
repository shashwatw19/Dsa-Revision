//l.c 242
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//time complexity O(2n)
//space complexity O(1)
bool isAnagram(string s, string t) {
    vector<int>hash(26,0);
    for(int i = 0; i < s.size() ; i++){
        hash[s[i] - 'a']++;
    }
    for(int i =0 ; i < t.size() ; i++ ){
        hash[t[i] - 'a']--;
    }
    for(auto it : hash){
        if( it != 0)
            return false;
    } 
    return true;
}