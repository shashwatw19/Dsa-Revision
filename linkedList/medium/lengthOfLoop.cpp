#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//time complexity O(N * 2*logn)
//space O(N)
int brute(ListNode* head){
    ListNode* temp = head;
    unordered_map<ListNode* , int>mpp;
    int timer = 0;
    while(temp){
        timer++;
        if(mpp.find(temp) != mpp.end()){
            return timer - mpp[temp];
        }
        mpp[temp] = timer;
        temp = temp->next;
    }
    return 0;
}

int findLength(ListNode* &slow , ListNode* &fast){
    int cnt = 1;
    fast = fast->next;
    while(fast != slow){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
//time complexity O(N)
//space complexity O(1)
int tortoiseHare(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return findLength(slow , fast);
        }
    }
    return 0;
}