#include<iostream>
using namespace std;
#define n 5

class Queues
{
    int* arr;
    int front;
    int back;

public:
    Queues()
    {
        arr=new int[n];
        front=-1;
        back=-1;
    }

void push(int x)
{
    if (back ==n-1)
    {
        cout<<"Queue is Overflow:"<<endl;
        return;
    }
    back++;
    arr[back]=x;

    if (front ==-1)
    {
        front++;
    }
}

void pop()
{
    if (front ==-1 || front > back)
    {
        cout<<"No Element to POP!"<<endl;
        return;
    }
    front++;
}

int peek()
{
    if(front==-1 || front>back)
    {
        cout<<"No element to PEEK!"<<endl;
        return -1;
    }
    return arr[front];
}
bool empty()
{
    return(front > back);
}
};

int main()
{
    Queues str;
    str.push(1);
    str.push(2);
    str.push(3);

    cout<<str.peek()<<endl;
    str.pop();
    str.pop();

    str.push(4);
    str.push(5);

    cout<<str.peek()<<endl;
    str.pop();
    str.pop();  
    str.pop();


    str.push(6);
    str.push(7);
    str.push(8);
    str.push(9);
    str.push(10);
    str.push(11);

    str.pop();
    str.pop();  
    str.pop();
    str.pop();  
    str.pop();
    str.pop();
}