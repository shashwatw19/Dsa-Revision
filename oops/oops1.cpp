#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Student{
    private :
    string name;
    public : 
    int age , roll ;
    //parameterised constructor
    Student(int age , int roll , string name){
        this->name = name;
        this->roll = roll;
        this->age = age;
    }
    //copy constructor
    Student(const Student&srcObj){
        cout<<"copy constructor called"<<endl;
        this->name = srcObj.name;
        this->age = srcObj.age;
        this->roll = srcObj.roll;
       
    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    string displayName(){
        return this->name;
    }
    ~Student(){ 
        cout<<"Student dTor called for "<<this->name<<endl;
    }
};
int main(){
    Student s0(19 , 119 , "karan");
    // not able to use this pointer because allocated in stack
    cout<<s0.age<<endl;
    // allocation in heap memory
    Student *s1 = new Student(1123 , 119 , "arjun");
    cout<<s1->age<<endl;
    cout<<(*s1).age<<endl;



   Student s3(20 , 2001 , "aenge");
   Student s4 = s3; 



// In this case copy constructor is not being called because it is not creating a new object s5 is pointer to s1 location   
   Student *s5 = s1;
   cout<<s5->getName()<<endl; 
   s5->setName("ishan awasthi");

    // ✅ Clean up heap memory
    delete s1;  // This will call destructor for "arjun"
    s1 = nullptr;
    s5 = nullptr;  // Avoid dangling pointer

}