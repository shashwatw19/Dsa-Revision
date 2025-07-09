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
//time complexity O(N)
//space complexity )(N)
ListNode* method1(ListNode* head){
    vector<int>arr;
    ListNode* temp = head;
     if(!head)
            return nullptr;
        if(!head->next)
            return head;
    //O(n/2)
    while(temp && temp->next){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
    if(temp)
        arr.push_back(temp->val);
    temp = head->next;
    //o(n/2)
    while(temp && temp->next){
        arr.push_back(temp->val);
        temp = temp->next->next;
    }
     if(temp)
        arr.push_back(temp->val);
    temp = head;
    for(int i : arr){
        temp->val = i;
        temp = temp->next;
    }
    return head;
}
//inplace chaning of links without extra space
//time complexity = O(n)
//space complexity = O(1)
ListNode* method2(ListNode* head){
    if(!head || !head->next){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        //n/2
        while(even && even->next){
            //these operations will take n/2
            //so over all n/2 * 2 which is O(n)
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
}