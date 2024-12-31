#include<iostream>
using namespace std;

#define n 20 // It represents the maximum size of the queue.

class queue{
  int* arr; // A pointer to dynamically allocate memory for the queue elements.
  int front; // Points to the index of the first (front) element in the queue.
  int back; // Points to the index of the last (rear) element in the queue.

public:
queue()
{
    arr= new int[n]; //Dynamically allocates memory for the queue using new int[n] to hold up to n elements.
    front=-1; //Initializes front and back to -1, indicating the queue is empty initially.
    back=-1;
}

void push(int x)
{
    if (back == n-1)
    { //Check if the queue is full (back == n-1), and display an overflow message if true.
        cout<<"Queue is overflow:"<<endl;
        return;
    }
    back++; //Increment back to add the new element at the next position.
    arr[back]=x; //Store the new element in arr[back].

    if (front ==-1)
    {
        front++;
    }
}
void pop()
{
    if (front==-1 || front > back)
    { //Check if the queue is empty (front == -1 or front > back). If true, display a message and return.
       cout<<"No Elements to POP:"<<endl;
       return;
    }
    front++; //Increment front to point to the next element in the queue, effectively removing the current front element.
}
int peek()
{
    if (front==-1 || front > back) 
    { //Check if the queue is empty (front == -1 or front > back). If true, display a message and return -1.
    cout<<"No Elements to Peek:"<<endl;
    return -1;
    }
     return arr[front]; //Return the value at arr[front].
}
bool empty()
{
    return (front > back); //Returns true if front > back (no elements in the queue).Otherwise, returns false.
}
};

int main()
{
    queue stc;
    stc.push(1);
    stc.push(2);
    stc.push(3);
    stc.push(4);

    cout<<stc.peek()<<endl;
    stc.pop();

    cout<<stc.peek()<<endl;
    stc.pop();

    cout<<stc.peek()<<endl;
    stc.pop();

    cout<<stc.peek()<<endl;
    stc.pop();

    cout<<"Empty check: YES(1) ... NO(0):"<<stc.empty()<<endl;
}