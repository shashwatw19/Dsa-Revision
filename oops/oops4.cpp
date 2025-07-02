//multiple inheritance
//diamon problem

//Virtual inheritance ensures that only one shared copy of the base class (including all its data members and member functions) 
//exists in the derived object.

//so when virtual is used in the class . the same copy of walk is shared . so no ambiguity problem arises

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Person {
    public : 
    void walk(){
        cout<<"waling....."<<endl;
    }
};
class Teacher : virtual public Person{
    public :
    void teach(){
        cout<<"teaching..."<<endl;
    }
};
class Researcher :virtual public Person{
    public :
    void research(){
        cout<<"researching..."<<endl;
    }
};

class Professor : public Teacher , public Researcher {
    public : 
    void bore(){
        cout<<"boring..."<<endl;
    }
};
int main(){
    Professor p1;

    // "Professor::walk" is ambiguous
    // p1.walk(); 


    //solution 1 -> score resolution
    // p1.Teacher::walk();

    //using virtual 
    p1.walk();
}   