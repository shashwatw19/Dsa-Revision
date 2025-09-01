//generate all the permutation for a give number
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void permutation(vector<int>num , int start , vector<vector<int>>&ans){
    if(start >= num.size()){
        ans.push_back(num);
        return;
    }
    for(int i = start ; i < num.size() ; i++){
        swap(num[i] , num[start]);
        permutation(num , start + 1 , ans);
        swap(num[i] , num[start]);
    }
}
int main(){
    vector<int>num = {1,2,3};
    vector<vector<int>>ans;
    permutation(num , 0 , ans);
    for(auto num : ans){
        for(auto it : num){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}