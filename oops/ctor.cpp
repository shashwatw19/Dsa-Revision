#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Box{
    int width ;
    Box(int w) : width(w) {}
    public :
    int getWidth() const {
        return width;
    }
    void setWidth(int w){
        this->width = w;
    }
    friend class BoxFactory;
};
class BoxFactory{
    int count ;
    public : 
    Box getBox(int _w){
        ++count ;
        return Box(_w);
    }
};
int main(){
    BoxFactory bfact;
    Box b = bfact.getBox(6);
    cout<<b.getWidth();

    b.setWidth(4);
    cout<<endl;
    cout<<b.getWidth();
}