#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class A{
    public :
    int x;
    int *y;

    A(int x , int y ) : x(x) , y(new int(y)){}

    //default dumb copy ctor
    // A(const A &a){
    //     cout<<"copy ctor called"<<endl;
    //     this->x = a.x;
    //     this->y = a.y;
    // }
    //smart deep copy
    A(const A &a){
        cout<<"deep copy ctor called"<<endl;
        this->x = x;
        this-> y = new int (*a.y);
    }
    void print(){
        cout<<"value of x "<<x<<" ";
        cout<<"value of y "<<y<<" ";
        cout<<"address of y "<<&y<<" ";
        cout<<"value at y "<<*y<<" ";
        cout<<endl;
    }
    ~A(){
        delete y;
    }
};

int main(){
   A *a = new A(1,6);
   a->print();

   A b = *a;
   delete a;
   b.print();
    
   return 0;
}

// when a is allocated dynamicall in the heap memory . let suppose a's x = 1 and y is somewhere in the heap memory .
//when b = *a
//b->x = 1 , which is a's x's value
//b->y = y , which point to a's y address
//when when we delete a , A's destructor is called and y is deleted from a 
//when we print b.print we got x's value because it was copied , but y was pointing to a's y location which was deleted . so we get garbage value of y 
//*****when using pointers use deep copy to avoid these type of problems 




// *a ->    x =1 , *y = 2 [302] <- address of y
//b = *a   x = 1 , y = 302

//when delete a ; ->   x is delete and y is deleted
// *a -> x is deleted and destructor is so y is also deleted

//when b.print is called x's value was copied but b'y which has pointing to a's y location which has been deleted . there for it prints a garbage value
