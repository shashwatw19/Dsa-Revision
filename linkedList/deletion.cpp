#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
   
    Node(int data , Node* next ){
        this->data = data;
        this->next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
Node* removeHead(Node* head){
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete(temp);
    return head;
}
Node* removeTail(Node* head){
    if(!head)
        return nullptr;
    if(!head->next)
        return removeHead(head);
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}  
Node* removeKthPosition(Node* head , int k){
    if(head==NULL)
        return head;
    if(k==1){
        return removeHead(head);
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete temp;
            return head;
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
Node* arrtoLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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
    vector<int>arr = {100,2,3,1,4,1,5,1,5};
    Node* head = arrtoLL(arr);
     printList(head);
    Node* temp = removeKthPosition(head , 9);
    printList(temp);
}