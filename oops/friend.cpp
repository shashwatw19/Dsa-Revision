#include<iostream>
using namespace std;
class A{
    int x;
    int y;
    
    A(int x , int y) : x(x) , y(y){}
    int getX() const {
        return x;
    }
    int setX(int x){
        this->x = x;
    }
    friend class B;
    friend void setNo( A &  , int n);
};
class B {
    public :
    void print(const A &a){
        //if we try to access directly a.getX it will in accessible . so we have to define class B as a friend class of A
        cout<<a.getX()<<endl;
    }
};
//friend function
void setNo( A&a , int n){
    a.setX(n);
}
int main(){

}