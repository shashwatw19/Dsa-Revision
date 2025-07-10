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
ListNode* reverse(ListNode* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
//time complexity O(3n)
ListNode* addOne(ListNode* head){
    ListNode* temp = head;
    // o(n)
    temp = reverse(head);
    int carry = 1;
    //o(n)
    while(temp){
        temp->val+=carry;
        if(temp->val < 10){
           carry = 0;
        }else{
           temp->val = 0;
           carry = 1; 
        }
        temp = temp->next;
    }
    //o(n)
    temp = reverse(head);
    if(carry ==1){
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
int helper(ListNode* head){
    if(!head){
        return 1;
    }
    int carry = helper(head->next);
    head->val+=carry;
    if(head->val < 10){
        return 0;
    }
    head->val = 0;
    return 1;
}
//time complexity O(N)
//space complexity O(N)
ListNode* optimised(ListNode* head){
    int carry = helper(head);
    if(carry){
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
