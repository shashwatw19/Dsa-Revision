// usage of public , private and protected

// protected members are only accessible within class itself and its derived class
//private members are only accessible within class . they are not accessible to their derived class
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Person{
    public : 
    int age , dob;
    string name ;
    Person(){
        cout<<"Default constructor of Person called"<<endl;
    }
    string getName(){
        return this->name;
    }
};
class Doctor : public Person{
    public :
    string profession ;

    Doctor(string name , string profession){
        cout<<"param constructor of Doctor called"<<endl;
        this->name = name;
        this->profession = profession;
    }
    string getProfession(){
        return this->profession;
    }
};
class Mechanic : protected Person{
    public : 
    string profession, name;
    Mechanic(string name , string profession , int age , int dob){
        this->name = name;
        this->profession = profession;
        this->age = age;
        this->dob - dob;
    }
    int getAge(){
        return this->age;
    }

};
//as this class has inherited base class private mode . it's data can't ne inherited
class Shopkeeper : private Person{
    public : 
    string name , proffession;
     Shopkeeper() {
        cout << "Default Shopkeeper constructor called" << endl;
    }
    Shopkeeper(string name , string proffession , int age , int dob){
        this->dob = dob;
        this->proffession = proffession;
        this->age = age;
        this->dob = dob;
    }
    void displayProfession(){
        cout<<this->proffession<<endl;
    }
};
class Tailor : public Shopkeeper{
     Tailor(string name, string profession, int age, int dob){
        this->name = name;
        this->proffession = profession;

        //here age and dob were inherited as private from person into shopkeepr therfore they are not accesible here
        // this->age = age;
        // this->dob = dob;
     }
        

};
int main(){
    // when the base class is public and mode of inheritance is public
    Doctor d1("shashwat" , "surgoen");
    cout<<d1.getProfession()<<endl;
    cout<<d1.getName();

    // when the base class is public and mode of inheritance is protected
    Mechanic m1("mohammad" , "punchure repair" , 15 , 1987);
    
    //age will not be directly accessible bcs it is treated as protected not
    // cout<<m1.age;

    cout<<m1.getAge(); //this will work fine 


    //if the base class has protected access and the mode of inh is public . the data members and function of base will be protected
    //same for if mode of inheritance is protected
    //if the mode of inheritance is private it is treated as private
    
    
}