// Reverse Words in a String 151
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//time complexity O(N)
//space complexity O(1)
class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.size() - 1;
        //remove the leading/trailing white spaces
        while(left <=right && s[left] == ' '){
            left++;
        }
        while(right >=left && s[right] == ' '){
            right--;
        }
        
        //create a clean string with no extra spaces
        string temp = "";
        //ensures that there are no extra spaces . adds the space only if there is not a previous space added
        while(left <= right){
            if(s[left] != ' ' || temp.back() != ' ')
                temp.push_back(s[left]);
            left++;
        }

        //reverse the clean string
        reverse(temp.begin() , temp.end());
        
        //now reverse the each word in the string
        int start = 0;
        for(int end = 0 ; end <= temp.size() ; end++){
            if(temp[end] == ' ' || end == temp.size()){
                reverse(temp.begin() + start , temp.begin() + end);
                start = end+1;
            } 
            
        }
        return temp;
    }
};