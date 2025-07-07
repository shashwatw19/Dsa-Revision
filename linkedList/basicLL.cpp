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
int findLength(Node* head){
    if(!head)
        return 0;
    int cnt =0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}
bool checkIfPresent(Node* head , int element){
    if(!head)
        return false;
    while(head){
        if(head->data == element)
            return true;
        head = head->next;
    }
    return false;
}
int main(){
    vector<int>arr = {1,2,31,4,1,51,5};
    Node* temp = arrtoLL(arr);
    
    cout<<findLength(temp);
    cout<<checkIfPresent(temp , 24);
}