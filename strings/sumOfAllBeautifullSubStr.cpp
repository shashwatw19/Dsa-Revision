// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.
// Example 1:
// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:
// Input: s = "aabcb

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        if(s.empty())
            return 0;
        int totalBeauty = 0;
        unordered_map<char , int>mpp;

        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                mpp[s[j]]++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for (auto it : mpp) {
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);
                }

                totalBeauty += (maxFreq - minFreq);

            }
            mpp.clear();
        }

        return totalBeauty;

    }
};
int main(){

}