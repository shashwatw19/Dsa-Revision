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

ListNode* deleteMiddle(ListNode* head){
    if(!head || !head->next)
        return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* middleNode = slow->next;
    slow->next = slow->next->next;
    delete middleNode;
    return head;
}