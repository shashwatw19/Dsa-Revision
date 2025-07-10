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
//time complexity O(n);
//space complexity O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* ans = dummyNode;
    int carry = 0;
    while(temp1 || temp2){
        int sum = carry;
        if(temp1) sum+=temp1->val;
            
        if(temp2) sum+=temp2->val;
            
        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;
        ans->next = newNode;
        ans = ans->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        ListNode* newNode = new ListNode(carry);
        ans->next = newNode;
    }

    return dummyNode->next;
}