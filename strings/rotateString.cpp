// l.c 796
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:
// Input: s = "abcde"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) {
    if(goal.size() != s.size()){
        return false;
    }
    return (s+s).find(goal) != string::npos;
}
int main(){

}