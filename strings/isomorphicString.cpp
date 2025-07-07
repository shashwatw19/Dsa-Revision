//205 isomprphic string
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
// Explanation:
// The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
// Example 3:
// Input: s = "p"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
    vector<int>hash(128 , 0);
    vector<int>isCharMapped(128 , 0);
    for(int i = 0 ; i < s.size() ; i++){
        if(hash[s[i]] == 0 && isCharMapped[t[i]] == 0)
            hash[s[i]] = t[i];
            isCharMapped[t[i]] = 1;
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(hash[s[i]] != t[i])
                return false;
        }
    return true;
}
