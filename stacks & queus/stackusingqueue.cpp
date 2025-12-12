#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    int currSize;
    int capacity;
    queue<int>q;

public:
    Stack(int size){
        capacity = size;
        currSize = 0;
    }

    void push(int x){
        if(currSize == capacity){
            cout << "Stack Overflow\n";
            return;
        }
        // push new element then rotate the queue so the new element becomes front
        q.push(x);
        int n = q.size();
        for(int i = 0; i < n - 1; ++i){
            q.push(q.front());
            q.pop();
        }
        ++currSize;
    }

    int pop(){
        if(currSize == 0){
            cout << "Stack Underflow\n";
            return INT_MIN; // or throw
        }
        int val = q.front();
        q.pop();
        --currSize;
        return val;
    }

    bool empty() const { return currSize == 0; }
    int size() const { return currSize; }
    int top() const { return currSize ? q.front() : INT_MIN; }
};

int main(){

}