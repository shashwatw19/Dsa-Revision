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
//space complexity O(N)
bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , int>mpp;
        ListNode* temp = head;
        while(temp){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
}
// when there is a cylce in a linked list faster will be closer by one step in each iteration . and there will be a point where the distance between them is 0
bool tortoiseHare(ListNode *head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)
            return true;
    }
    return false;
}