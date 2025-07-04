#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class abc{
    public :
    int x ;
    int *y;

    abc(int x , int y) : x(x) , y(new int(y)) {}

    //default dumb copy constructor : it does shallow copy
    // abc(const abc &a){
    //     cout<<"copy constructor called"<<endl;
    //     this->x = a.x;
    //     this->y = a.y;
    // }

    //smart deep copy
    abc(const abc &a){
        this->x = a.x;
        //this will make a new pointer which has the value of a's y
        this->y = new int(*a.y);
    }

    void print() const {
        cout<<"value of x :"<<x<<" value of y :"<<y<<" value at y :"<<*y<<" address of y :"<<&y<<endl;
    }
};
int main(){
    abc a(3 ,5);
    a.print();
    abc b = a;
    //the pointer variavle y os holding the same address of a's y pointer . which is wrong
    b.print();

    *b.y = 20;
    //a's y and b's y both value will changed  
    cout<<"after changin the value of y "<<endl;
    b.print();
    a.print();

}