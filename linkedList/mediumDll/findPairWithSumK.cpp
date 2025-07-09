//given that list is sorted
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val),next(nullptr),prev(nullptr){};
    Node(int val , Node* prev , Node* next) : data(val) , prev(prev) , next(next){};

};
//time complexity O(N*N)
//space complexity O(K) , where K is the number of pairs found
vector<pair<int ,int>>findSum(Node* head , int sum){
        Node* temp1 = head;
        Node* temp2 = temp1->next;
        vector<pair<int ,int>>ans;
        while(temp1){
            temp2 = temp1->next;
            while(temp2 && temp1->data + temp2->data <=sum){
                if(temp1->data + temp2->data == sum){
                    ans.push_back({temp1->data,temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
}
//time complexity O(N)
//space complexity O(K) , where K is the number of pairs found
vector<pair<int, int>> findSumOptimized(Node* head, int sum) {
    vector<pair<int, int>> ans;
    
    if (!head) return ans;
    
    // Get tail pointer
    Node* left = head;
    Node* right = head;
    while (right->next) {
        right = right->next;
    }
    
    // Two pointers approach
    while (left != right && left->data < right->data) {
        int currentSum = left->data + right->data;
        
        if (currentSum == sum) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (currentSum < sum) {
            left = left->next;   // Need larger sum
        }
        else {
            right = right->prev; // Need smaller sum
        }
    }
    
    return ans;
}