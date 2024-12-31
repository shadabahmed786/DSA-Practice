#include<iostream>
#include<string>
using namespace std;

class stringStack{
    private:
    
    struct Node
    {
        string data;
        Node* next;
        Node(string x)
        {
            data= x;
            next =nullptr;
        }
    };
    Node* top;
    public:
    stringStack()
    {
        top=nullptr;
    }

    void push(string x)
    {
        Node* newNode = new Node(x);
        newNode->next =top;
        top=newNode;
        cout<<"Pushed "<< x <<" onto the Stack: "<<endl;
    }

    void pop()
    {
        if(top == nullptr)
        {
            cout<<"No Element in Stack to Pop! "<<endl;
            return;
        }
        Node* temp=top;
        top =top->next;
        cout << "Popped " << temp->data << " from the stack." << endl;
        delete temp;
    }

    string Top()
    {
        if (top == nullptr)
        {
            cout<<"Stack is Empty!"<<endl;
            return " ";
        }
        return top->data;
    }
    bool Empty()
    {
        return top == nullptr;
    }

    ~stringStack()
    {
        while( top != nullptr)
        {
            pop();
        }
    }
};

int main()
{
    stringStack stc;
    stc.push("My ");
    stc.push("name ");
    stc.push("is ");
    stc.push("Qazi Shadab Ahmed!");

    cout<<" "<<stc.Top()<<endl;
    stc.pop();
    stc.pop();
    stc.pop();

    cout<<"Is Stack is Empty? "<<stc.Empty()<<endl;

    cout<<"Remaining Elements: "<<stc.Top()<<endl;
};