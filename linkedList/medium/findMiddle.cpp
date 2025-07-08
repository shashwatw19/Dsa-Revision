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
//time complexity O(N + N/2)
Node* findMiddle(Node* head){
    int cnt = 0;
    Node* temp = head;
    // o(N)
    while(temp){
        cnt++;
        temp = temp->next;
    }
    int middleNode = cnt/2 + 1; 
    temp = head;
    //O(N/2)
    while(temp){
        middleNode--;
        if(middleNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
//when ll lenth us odd fast will be at last node 
//when length is even fast will be at null
//logic -> suppose there are two running at the speed of x and x/2 . when the runner with x speed reaches the destination . the runner with x/2 speed will be surely at the middle of the destination
//time complexity O(n/2)
//space complexity O(1)
Node* tortoiseHare(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){

}