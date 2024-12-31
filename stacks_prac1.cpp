#include<iostream>
using namespace std;
#define n 100

class stack
{
private:
    int* arr;
    int top;
public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

void push(int x)
    {
        if (top == n-1)
        {
            cout<<"Stack overflow:"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }

void pop()
    { 
        if(top == -1)
        {
            cout<<"No element to Pop:"<<endl;
            return;
        }
        top--;
    }

int Top()
    {
        if(top ==-1)
        {
            cout<<"No element On Top!"<<endl;
            return -1;
        }
        return arr[top];
    }
bool empty()
    {
       return top  ==-1;
    }
};

int main()
{
    stack str;
    str.push(1);
    str.push(2);
    str.push(3);
    cout<<"Element in Stack: "<<str.Top()<<endl;
    str.pop();
    cout<<"Remaining Elements in Stack: "<<str.Top()<<endl;
    str.pop();
    str.pop();
    str.pop();
    cout << "Is Empty? " << str.empty() << endl;
    return 0;
}