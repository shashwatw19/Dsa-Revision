//given that the list is sorted
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int val;
    Node* next;
    Node* prev;

    Node(int val) : data(val),next(nullptr),prev(nullptr){};
    Node(int val , Node* prev , Node* next) : data(val) , prev(prev) , next(next){};

};
ListNode* removeDuplicates(ListNode* head){
    ListNode* temp = head;
    ListNode* nextNode = temp->next;
    while(temp){
        while(nextNode && nextNode->val == temp->val){
            ListNode* duplicateNode = nextNode;
            nextNode = nextNode->next;
            delete duplicateNode;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;

        temp = temp->nextNode;
    }
    return head;
    
}