#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack{
    private :
        int top;
        int size ;
        int *arr ;
    public :
        Stack(int s){
            size = s;
            arr = new int [size];
            top = -1;
        }
        
        void push(int element){
            if(is_full()){
                cout<<"stack is full cannot push"<<endl;
            }
            arr[++top] = element;
        }
        int pop(){
            if(is_empty()){
                cout<<"stack is empty"<<endl;
            }
            return arr[top--] ;
        }
        int peek(){
            if(is_empty()){
                cout<<"stack is empty"<<endl;
            }
            return arr[top];
        }
        bool is_empty(){
            return top == -1;
        }
        bool is_full(){
            return top == size -1;
        }
        void display(){
            if(is_empty()){
                cout<<"stack is empty";
            }
            for(int i = top ; i >=0 ; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        
};
int main(){
     Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
   
    // st.pop();
    // st.pop();
   
    st.display();

    cout << "Popped: " << st.pop() << endl;
    cout << "Top element: " << st.peek() << endl;

    st.display();
}
