//l.c 451
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool myComp(pair<char , int>&a , pair<char , int>&b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        int hash[256] = {0};
        for(char ch : s){
            hash[ch]++;
        }
        vector<pair<char , int>>freqCount;
        for(auto ch : s){
            if(hash[ch] > 0){
                freqCount.push_back({ch , hash[ch]});
                hash[ch] = 0;
            }
        }
        sort(freqCount.begin() , freqCount.end() , myComp);
    
        string result = "";
        for(auto &p : freqCount){
            char ch = p.first;
            int freq = p.second;
            while(freq--){
                result+=ch;
            }
        }
        return result;
    }
};
int main(){

}