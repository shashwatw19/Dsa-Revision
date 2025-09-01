//generate all the subarray from a given array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_helper(vector<int>&nums , vector<int>&output , int index){
    if(index >= nums.size()){
        for(auto it : output){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    output.push_back(nums[index]);
    print_helper(nums , output , index+1);

    output.pop_back();
    print_helper(nums , output , index+1);
}
void print(vector<int>&nums){
    int index = 0 ;
    vector<int>output;
    print_helper(nums , output , index);
}
int main(){
    vector<int>nums = {1,2,3};
    print(nums);
}