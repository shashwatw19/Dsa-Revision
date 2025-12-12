struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        this->next = null;
    }
};

class Stack{
    private : 
    Node* top ;
    int size = 0;

    public :
    Stack(int size){
        this->size = size;
        top = new Node();
    }

    void push(int data){
        Node* temp = new Node(data);
        tmep->next = top;
        top = temp;
        size += 1;
    }

    int pop(){
        Node* temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        size-=1;
        return data;
    }

    int top(){
        return top->data;
    }

    int size(){
        return size;
    }
}
