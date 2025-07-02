// types of inheritance
// single 
//multilevel
//heirarichle
//***multiple***

//Key Takeaway: Child classes call parent's default constructor by default, 
//but you can override this using member initializer lists to call specific parent constructors!
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Animal {
    public :
    string name ;
    int age ;
    int weight;

    Animal(){
        cout<<"Animal constructor called"<<endl;
    }

    string getAnimalName(){
        return this->name;
    }   
    ~Animal(){
        cout<<"Animal destructor called "<<this->name<<endl;
    }

};
//single inheritance
class Bird : public Animal{
    public :
    Bird(string name , int age , int weight){
        cout<<"Bird param constructor called"<<endl;
        this->name = name;
        this->age = age;
        this->weight = weight;
    }
  
    void fly(){
        cout<<this->name<<" can fly "<<endl;
    }
    ~Bird(){
        cout<<"Bird destructor called "<<this->name<<endl;
    }
};

//multiple inheritance
class Sparrow : public Bird{
    
    public:
    string color;
    Sparrow(string name , string color , int age , int weight):Bird(name , age , weight){
        this->name = name;
        this->color = color;
        this->age = age;
        this->weight = weight;
    }

    ~Sparrow(){
        cout<<"Sparrow destructor called "<<this->name<<endl;
    }
};
//heirarical inheritance
class Eagle : public Bird{
    public : 
    string eyes;
    Eagle(string eyes , string name , int age , int weight)  : Bird(name , age , weight){
        this->name = name;
        this->eyes = eyes;
        this->age = age;
        this->weight = weight;
    }

    ~Eagle(){
        cout<<"Eagle destructor called "<<this->name<<endl;
    }
};
int main(){
    
  
    Bird a = Bird("bird2" , 10 , 20);
   
    a.fly();
    // Line 68:
    // Creates a Bird object dynamically using new.
    // Returns a pointer to the Bird object (Bird*).
    // The object is stored on the heap (dynamic memory).
    // You must manually delete b; later to avoid memory leaks.
    
    // Line 69:
    // Creates a Bird object on the stack (automatic storage).
    // a is a Bird object, not a pointer.
    // The object is destroyed automatically when it goes out of scope (e.g., at the end of the function).

    Sparrow *s1 = new Sparrow("sparrow" , "brown" , 12 , 20);
    cout<<s1->getAnimalName()<<endl;
    cout<<s1->age<<endl ;
    cout<<s1->color<<endl; 
    
    
    Eagle *e1 = new Eagle("black" , "hawk" , 20 , 59 );
    cout<<e1->age<<endl;
    cout<<e1->getAnimalName()<<endl;
    
    delete s1 ;
    delete e1;
    s1 = nullptr;
    e1 = nullptr;
    
} 