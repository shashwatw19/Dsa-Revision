#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>

class MyString{
    private :
    char *data ;
    int length ;

    public :
    //default ctor
    MyString();

    //param ctor
    MyString(const char *str);

    

    //copy ctor
    MyString(const MyString &other);
    
    //dtor
    ~MyString();

    //returns the size of string
    int size() const;

    //return true if the string is empty else returns false
    bool empty() const;

    //displays the string created
    void display(const MyString &obj) ;

    //return the chat at index
    char operator[](int index);

    int find(const MyString &substr) ;
};

#endif // end of header file