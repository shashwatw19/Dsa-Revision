//compile time -> fn overloading , operator overloading...
//compile time polymorphism is faster...

// Function overloading is determined by the function signature, which includes:

// Function name
// Number of parameters
// Type of parameters
// Order of parameters
// Return type is NOT part of the function signature.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Number{
    public :
    int a , b , c;
    Number(int a , int b) : a(a),b(b) {}
    Number(int a , int b , int c) : a(a) , b(b) , c(c) {}
    
    int sum() {                           // No parameters
        return a + b;
    }
    
    int sum(int x, int y) {              // Two parameters
        return x + y;
    }
    
    int sum(int x, int y, int z) {       // Three parameters
        return x + y + z;
    }
    
    void display() {
        cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    }

    
};
class Vector {
    public :
    int a , b;
    Vector(int a , int b) : a(a) , b(b) {};

    void operator+(const Vector &srcObj){
        this->a+=srcObj.a;
        this->b += srcObj.b;
    }
    void operator-(const Vector &srcObj){
        this->a -= srcObj.a;
        this->b -= srcObj.b;
    }
    void operator++(){
        this->a++;
        this->b++;
    }
    void display(){
        cout<<this->a<<" "<<this->b<<endl;
    }
};
int main(){
    Number n1(4,5);
    Number n2(3,4,5);
    n1.display();
    n2.display();

    Vector v1(6,5);
    Vector v2(4,4);
    v1 + v2;
    v1.display();
}