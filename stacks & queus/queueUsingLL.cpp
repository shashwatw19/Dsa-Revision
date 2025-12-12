struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
}

class Queue{
    private :
    Node* rear;
    Node* front;
    int size;
   
    public :
    Queue(){
        size = 0;
        rear =  new Node();
        front = new Node();
       
    }

    void push(int data){
        
        Node* temp = new Node(data);
        if(front == nullptr && rear == nullptr){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
        size+=1;
    }

    int pop(){
        if(front == nullptr){
            cout<<"empty queue";
            return -1;
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int top(){
        if(front == nullptr){
            cout<<"empty queue"<<endl;
            return;
        }
        int data = front->data;
        return data;
    }
}