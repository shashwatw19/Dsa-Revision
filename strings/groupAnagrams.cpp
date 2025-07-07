// leetcode 49
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation:
// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:
// Input: strs = [""]
// Output: [[""]]
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//method -1 
//time complexity O(NKlogK) where N is the number of elements in the array and K is the size of single element
//space complexity O(NK)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mpp;
        for(auto str : strs){
            string temp = str;
            sort(str.begin() , str.end());
            mpp[str].push_back(temp);
        }

        vector<vector<string>>ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;
       
}
//method - 2
vector<int>hashFn(string s){
    vector<int>hash(265 , 0);
    for(char ch : s){
        hash[ch]++;
    }
    return hash;
}
//Total for main loop: O(N × (K + log G))
vector<vector<string>>method2(vector<string>& strs){
    map<vector<int> , vector<string>>mpp;
    for(auto str  : strs){  // O(N) iterations
        mpp[hashFn(str)].push_back(str);  // hashFn: O(K), map insertion: O(log G)
    }

       // Rest is O(N) for building result
    vector<vector<string>>ans;
    for(auto it : mpp){
        ans.push_back(it.second);
    }
}
int main(){

}