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
//space complexity O(1)
ListNode* method1(ListNode* head, int n){
    ListNode* temp = head;
        int cnt = 0;
        //o(n)
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int nodeToDelete = cnt - n;
        if(nodeToDelete==0)
            return head->next;
        temp = head;
        //O(n)
        while(temp){
            nodeToDelete--;
            if(nodeToDelete==0)
                break;
            temp = temp->next;
        }
        ListNode* NthNode = temp->next;
        temp->next = temp->next->next;
        delete NthNode;
        return head;
}

//time complexity O(N)
//space complexity O(1)
//"If we maintain a gap of exactly n nodes between two pointers, 
//when the fast pointer reaches the end, the slow pointer will be exactly at the node BEFORE the one we want to delete."
ListNode* method2(ListNode* head , int n){
    ListNode* fast = head;
        ListNode* slow = head;
        while(n--){
            fast = fast->next;
        } 
        if(!fast)
            return head->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* nthNode = slow->next;
        slow->next = slow->next->next;
        delete nthNode;
        return head;
}