//l.c 345
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
// Example 2:
// Input: s = "leetcode"
// Output: "leotcede"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isVowel(char ch){
       ch = tolower(ch);

       if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
string reverseVowels(string s) {
    int l = 0;
    int h = s.size() - 1;
    while(l <= h){
        if(isVowel(s[l]) && isVowel(s[h])){
            swap(s[l] , s[h]);
            l++;
            h--;
        }
        else if(!isVowel(s[l])){
            l++;
        }
        else{
            h--;
        }
    }
        return s;
}