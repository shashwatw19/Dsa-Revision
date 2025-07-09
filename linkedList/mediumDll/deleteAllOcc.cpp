#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val),next(nullptr),prev(nullptr){};
    Node(int val , Node* prev , Node* next) : data(val) , prev(prev) , next(next){};

};
//time complexity O(N)
//space complexity O(1)
Node* deleteAllOcc(Node* head , int key){
    Node* temp = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    while(temp){
        if(temp->data == key){
            if(temp==head){
                head = head->next;
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else{
             temp = temp->next;
        }
    }
}
int main(){

}