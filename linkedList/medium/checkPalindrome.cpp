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
//time complexity O(2N)
//space complexity O(N)
bool method1(ListNode* head){
    stack<int>st;
    ListNode* temp = head;
    while(temp){
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(!st.empty()){
        int val = st.top();
        st.pop();
        if(temp->val != val)
            return false;
        temp = temp->next;
    }
    return true;
}
//
ListNode* reverse(ListNode* head){
    if(!head || !head->next){
        return head;
    }
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}
//time complecity O(2N)
//space complexity O(1)

bool method2(ListNode* head){
    if(head == NULL || head->next == NULL)
        return true;
    ListNode* slow = head;
    ListNode* fast  = head;
    // O(n/2)
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //O(n/2)
    ListNode* newHead = reverse(slow->next);
    
    ListNode* second = newHead;
    ListNode* first = head;

    //O(n/2)
    while(second){
        if(second->val != first->val)
            return false;
        first = first->next;
        second = second->next;
    }
    //O(n/2)
    reverse(newHead);

    return true;
}