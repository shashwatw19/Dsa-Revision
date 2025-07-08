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
Node* deleteFromHead(Node* head){
    if(head == NULL || head->next == NULL)
        return nullptr;
    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}
Node* deleteFromTail(Node* head){
    if(head==NULL || head->next == NULL)
        return NULL;
    Node* temp = head;
  
    while(temp->next){
       temp =temp->next;
    }
    Node* prev = temp->prev;
    prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}
Node* deleteFromPosition(Node* head , int pos){
     if(!head)
        return NULL;
     int cnt = 0;
     Node* temp = head;
     while(temp){
        cnt++;
        if(cnt==pos)
            break;
        temp = temp->next;
     }
     Node* prevNode = temp->prev;
     Node* nextNode = temp->next;
     //singel element
     if(prevNode==NULL && nextNode == NULL){
        delete temp;
        return NULL;
     }
     //first element
     else if(prevNode == NULL){
        return deleteFromHead(head);
     }
     //last element
     else if(nextNode == NULL){
        return deleteFromTail(head);
     }
    

     //delete from  position
     prevNode->next = nextNode;
     nextNode->prev = prevNode;
     temp->next = nullptr;
     temp->prev = nullptr;
    
     return head;
}
void deleteNode(Node* temp){
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    if(nextNode==NULL){
        prevNode->next = NULL;
        temp->prev = NULL;
        delete temp;
        return ;
    }
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    temp->next = temp->prev = nullptr;
    delete temp;
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
int main(){
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = arrayToDll(arr);

    // Node* temp = deleteFromPosition(head , 1);
    deleteNode(head->next);
    printList(head);
}