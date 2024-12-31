#include<iostream>
using namespace std;

class LinkedListStack{
    private:
    struct Node{
        int data;
        Node* next;
        Node(int x)
        {
            data =x;
            next =nullptr;
        }
    };
    Node* top;
    public:
    LinkedListStack()
    {
        top=nullptr;
    }

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next=top;
        top=newNode;
        cout<<"Pushed "<<x<<" onto the stack."<<endl;
    }

    void pop()
    {
       if(top ==nullptr)
       {
        cout<<"Stack underflow! No Element to Pop."<<endl;
        return;
       } 
      Node* temp = top;
      top =top->next;
      delete temp; 
      cout << "Popped top element from the stack." << endl;
    }
    int Top()
    {
        if(top == nullptr)
        {
            cout<<"Stack is Empty!"<<endl;
        return -1;
        }
        return top->data;
    }
    bool Empty()
    {
        return top == nullptr;
    }
    ~LinkedListStack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
};

int main()
{
    LinkedListStack stc;
    
    stc.push(10);
    stc.push(20);
    stc.push(30);

    cout<<"Top element is "<<stc.Top()<<endl;

    stc.pop();
    cout<<"Top element after pop is: "<< stc.Top()<<endl;

    stc.pop();
    stc.pop();

    cout<<"Is Stack is empty "<<stc.Empty()<<endl;

    return 0;
}