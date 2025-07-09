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
//time complexity O(2N + NlogN)
//space complexity O(N)
ListNode* sortList(ListNode* head) {
    vector<int>arr;
    ListNode* temp = head;
    while(temp){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    temp = head;
    sort(arr.begin() , arr.end());
    for(auto i : arr){
        temp->val = i;
        temp = temp->next;
    }
    return head;
}
//to eleminate this extra space , we will try to implement merge sort
// time complexity (O(nlog (n + n/2))) 
// n/2 for finding the mid
//space complexity O(1)
ListNode* findMiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow;
}
ListNode* merge(ListNode* left , ListNode* right){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    while(left && right){
        if(left->val < right->val){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    
   if(left){
    temp->next = left;
   }
   else if(right){
    temp->next = right;
   }

    return dummyNode->next;

}
ListNode* sort(ListNode* head){
    if(!head || !head->next)
        return head;
    
    ListNode* middle = findMiddle(head);
    
    ListNode* leftHead = head;
    ListNode* rightHead = middle->next;
    middle->next = nullptr;

    leftHead = sort(head);
    rightHead = sort(rightHead);

    return merge(leftHead , rightHead);
    
}