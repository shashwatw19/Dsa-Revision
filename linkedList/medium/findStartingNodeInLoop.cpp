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
//time complexity O(n * 2*logn)
//space complexity O(N)
ListNode* detectCycle(ListNode *head) {
        unordered_map<ListNode* , int>mpp;
        ListNode* temp = head;
        while(temp){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
}
// see explainatio in the copy (pointers)
ListNode *tortoiseHare(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
               slow = head;
               while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
               }
               return slow;
            }
        }
        return nullptr;
}