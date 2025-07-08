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
//brtue force
//time complexity O(2N)
//space complexity O(N)
ListNode* method1(ListNode* head){
    stack<int>st;
    ListNode* temp = head;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(!st.empty() && temp){
        int val = st.top();
        st.pop();
        temp->val = val;
        temp = temp->next;
    }   
    return head;
}
//  |prev|-> |temp| -> |front|
// front = temp->next
// temp->next = prev
// temp = front
// prev = temp
//time complexity O(N)
//space complexity O(1)
ListNode* method2 (ListNode* head){
    ListNode* prev =  nullptr;
    ListNode* temp = head;
 
    while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
//time compleixty O(N)
//space complexity O(N) ->recursive stack space

ListNode* reverse(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}