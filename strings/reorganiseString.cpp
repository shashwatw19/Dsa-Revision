//l.c 767
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// Example 1:
// Input: s = "aab"
// Output: "aba"
// Example 2:
// Input: s = "aaab"
// Output: ""
 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//count hash the freq of each chars
//find the max freq character
//place it alternatively . if it is placed correctly , place the other characters
// if the maxf char is not placed correctly return the empty string
string reorganizeString(string s) {
        int hash[26] = {0};
        // find the freq of each character
        for(int i = 0 ; i < s.size() ; i++){
            hash[s[i]  - 'a']++;
        }
     
        //find the most  frequent character
        int maxf = INT_MIN;
        char maxfCh ;
        for(int i = 0 ; i < 26 ; i++){
            if(hash[i] > maxf){
                maxf = hash[i];
                maxfCh = i + 'a';
            }
        }
         
        int index = 0;
        string ans = s;
        while( maxf > 0 && index < s.size()){
            ans[index] = maxfCh;
            index+=2;
            maxf--;
        }
   
        if(maxf != 0)
            return "";

        hash[maxfCh - 'a'] = 0;

        for(int i = 0 ; i < 26 ; i++){
            while(hash[i] > 0){
                if(index >=s.size())
                    index = 1;
                ans[index] = i + 'a';
                hash[i]--;
                index+=2;
            }
        }
        return ans;

    }
int main(){

}