//l.c 1903
// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.
// Example 1:
// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:
// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:
// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string nums){
      for(int i = nums.size() - 1 ; i >= 0 ; i--){
        if((nums[i] - '0') % 2 == 1){
            return nums.substr( 0 , i+1);
        }
      }
      return "";
    }
int main(){

}