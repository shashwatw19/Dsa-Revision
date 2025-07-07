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
Node* insertAtHead(Node* head , int val){
    Node* temp = new Node(val , head);
    return temp;
}
Node* insertAtTail(Node* head , int val){
    if(!head){
        return new Node(val);
    }
    Node* temp = head; 
    while(temp->next){
        temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;

    return head;
}
Node* insertAtPosition(Node* head , int val , int k){
        if(head == nullptr){
             if(k==1)
                return new Node(val);
            else return head;
        }
        if(k==1){
            return insertAtHead(head , val);
        }
        
        Node* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            if(cnt == k - 1){
                Node* newNode = new Node(val , temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
            
        }
        return head;
    
}
Node* insertBeforeElement(Node* head , int element ,int val){
        if(head == nullptr){
            return nullptr;
        }
        if(head->data == val){
            return insertAtHead(head , val);
        }
        
        Node* temp = head;
        int cnt = 0;
        while(temp->next){
            if(temp->next->data == val ){
                Node* newNode = new Node(element , temp->next);
                temp->next = newNode;
                break;
            }
            temp = temp->next;
            
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
    vector<int>arr = {1,2,3,4,5,6,7,8};
    Node* head = arrtoLL(arr);
    printList(head);
    Node* temp  = insertBeforeElement(head , 106 , 4);
    printList(temp);
}