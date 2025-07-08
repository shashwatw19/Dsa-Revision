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
int main(){
    vector<int>arr = {1,2,3,1,2,3,1,3};
    Node* head = arrayToDll(arr);
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}