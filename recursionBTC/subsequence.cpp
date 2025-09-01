//generate all the subsequence of a string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_helper(string&s , string &output , int index){
    if(index >= s.size()){
        for(auto ch : output){
            cout<<ch;
        }
        cout<<endl;
        return;
    }
    cout<<"appending "<<" "<<s[index]<<endl;
    output.push_back(s[index]);
    print_helper(s , output , index+1);

    cout<<"poping"<<" "<<s[index]<<endl;
    output.pop_back();
    print_helper( s , output , index+1);
}
void print(string s){
    string output = "";
    int index = 0;
    print_helper(s , output , index);
}
int main(){
    string s = "ABC";
    print(s);
}