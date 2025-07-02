//dynamic binding
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Animal{
    public :
    virtual void sound(){
        cout<<"Animal Making sound"<<endl;
    }
};
class Dog : public Animal{
    public :
    void sound() override{
        cout<<"Dog making sound.."<<endl;
    }
};
class Cat : public Animal{
    public :
    void sound() override{
        cout<<"cat making sound"<<endl;
    }
};

void sound (Animal* obj){
    obj->sound();
}
int main(){
    Animal *a = new Dog(); //upcasting..
    a->sound();


// without virtual -> left side function will be called
    // Parent *p = new Child();
    // Parent *p = new Parent();
    // Child *c = new Child();
    // Child * c = new Parent(); bad practise downcasting....
// with virtual -> ride side function will be called
    // Parent *p = new Child();
    // Parent *p = new Parent();
    // Child *c = new Child();
    // Child * c = new Parent();
} 