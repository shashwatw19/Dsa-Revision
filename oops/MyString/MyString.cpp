#include<cstring>
#include<iostream>
#include "MyString.h"
using namespace std;

MyString::MyString(){
     data = new char[1];
     length = 0;
     data[0] = '\0';
}

MyString::MyString(const char *str){
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data , str); 
}
MyString::MyString(const MyString&other){
    data = new char[strlen(other.data) + 1];
    length = strlen(other.data);
    strcpy(data , other.data);
}
MyString::~MyString(){
    delete[] data;
}
int MyString::size() const{
    return length;
}
bool MyString::empty() const {
    return length == 0 ? true : false;
}
void MyString::display(const MyString &obj) {
    data = new char[strlen(obj.data) + 1];
    length = obj.length;
    for(int i = 0; i < length ; i++){
        cout<<data[i];
    }
}
char MyString::operator[](int index){
    if(index < 0 || index > length){
        return '\0';
    }
    cout<<data[index];
}
int MyString::find(const MyString &str){
    if(str.length > length)
        return -1;
    
    for(int i = 0 ; i <=length - str.length ; i++){
        int j;
        for(j = 0 ; i < str.length ; j++){
            if(data[i+j] != data[j])
                break;
        }
        if(j==str.length)
            return i;
    }
    return -1;
}