// l.c 917
// Given a string s, reverse the string according to the following rules:
// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.
// Example 1:
// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:
// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:
// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//or can use built in function isalpha
bool isAlpha(char ch){
    if((ch >= 65 && ch <= 90 )|| (ch >= 97 && ch <= 122) )
        return true;
    return false;
}
string reverseOnlyLetters(string s) {
    int l = 0;
    int h = s.size() - 1;
    while(l <=h){
        if(isalpha(s[l]) && isalpha(s[h])){
            swap(s[l] , s[h]);
            l++;
            h--;
        }else if(!isalpha(s[l])){
                l++;
        }else{
            h--;
        }
    }
    return s;
}
int main(){
    char a = 97;
    char z = 97 + 26 - 1;
    char A = 65;
    char Z = 65 + 26 - 1;
    cout<<a<<" "<<z<<" "<<A<<" "<<Z<<" ";
}