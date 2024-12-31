#include<iostream>
using namespace std;
#define n 100

//Reverse Sentence:
class sent
{
private:
    string* arr;
    int top;
public:
    sent()
    {
        arr = new string[n];
        top = -1;
    }
void push(string x)
    {
        if (top == n-1)
        {
            cout<<"Stack Overflow: "<<endl;
        }
        top++;
        arr[top]=x;
    }

string Top()
    {
        if (top == -1)
        {
            cout<<"Stack is Empty: "<<endl;
            return " ";
        }
        return arr[top]; 
    }
};
int main()
{
    sent stc;
    stc.push("Hey, how are you doing?");
    cout<<stc.Top()<<endl;
    return 0;
}