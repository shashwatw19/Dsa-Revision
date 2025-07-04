//l.c 1358
// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:
// Input: s = "abc"
// Output: 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//generate all the substrings and count the ones that contains all the three letters
// time complexity O(n*n)
//space complexity O(1)
int brute(string s){
    int count = 0;
    for(int i = 0 ; i < s.size() ; i++){
        int hash[3] = {0};
        for(int j = i ; j < s.size() ; j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                count += s.size() - j;
                break;
            }
        }
    }
    return count;
}
int numberOfSubstrings(string s) {
    int lastSeen[3] = {-1 , -1 , -1};
    int count = 0;
    for(int i = 0; i < s.size() ; i++){
    lastSeen[s[i] - 'a'] = i;
    if((lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1 )){
            count = count + (1 + min(lastSeen[0] , min(lastSeen[1] , lastSeen[2])));
    }
    }
    return count;
}

int main(){

}