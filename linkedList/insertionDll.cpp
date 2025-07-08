#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node* prev; 
    Node(int data , Node* next , Node* prev ){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = prev;
    }
};
Node* insertBeforeHead(Node* head , int val){
    if(head == NULL)
        return new Node(val , nullptr , nullptr);
    Node* newHead = new Node(val , head , nullptr);
    head->prev = newHead;
    return newHead;
}
Node* insertAfterHead(Node* head , int val){
    if(head == NULL)
        return new Node(val , nullptr , nullptr);
    Node* nextNode = head->next;
    Node* newNode = new Node(val , nextNode , head);
    nextNode->prev = newNode;
    head->next = newNode;
    return head;
}
Node* insertBeforeTail(Node* head , int val){
    if(head->next == nullptr){
        return insertBeforeHead(head , val);
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    Node* newNode = new Node(val , temp , prevNode);
    prevNode->next = newNode;
    temp->prev = newNode;
    
    return head;
}
Node* insertAfterTail(Node* head , int val){
    if(head==NULL){
        return new Node(val , nullptr , nullptr);
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node(val , nullptr , temp);
    temp->next = newNode;
    return head;
}
Node* insertBeforeKthPosition(Node* head , int val , int k){
    if(head->next == nullptr){
        if(k == 1){
            return insertBeforeHead(head , val);
        }
    }
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }
    Node* prevNode = temp->prev;
    Node* newNode = new Node(val , temp , prevNode);
    prevNode->next = newNode;
    temp->prev = newNode;

    return head;
}
Node* insertAfterKthPosition(Node* head , int val , int k){
     if(head->next == nullptr){
        if(k == 1){
            return insertAfterHead(head , val);
        }
    }
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k)
            break;
        temp = temp->next;
    }
    Node* nextNode = temp->next;
    Node* newNode = new Node(val , nextNode , temp);
    nextNode->prev = newNode;
    temp->next = newNode;

    return head;
}
void insertBeforeNode(Node* node , int val ){
    Node* prevNode = node->prev;
    Node* newNode = new Node(val ,node ,  prevNode );
    prevNode->next = newNode;
    node->prev = newNode;
}
void insertAfterNode(Node* node , int val){
    Node* nextNode = node->next;
    Node* newNode = new Node(val ,nextNode , node);
    nextNode->prev = newNode;
    node->next = newNode;
}
Node* arrayToDll(vector<int>&arr){
    Node* head = new Node(arr[0] , nullptr , nullptr);
    Node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = prev->next; 
    }
    return head;
}
void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}