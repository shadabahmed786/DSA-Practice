#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    for (int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j>=0 && arr[j] >key)
        {
         arr[ j+1 ] = arr[j];
         j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[],int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={12,32,41,23,65,32,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array:";
    printArray(arr,n);

    InsertionSort(arr,n);

    cout<<"Sorted Array:";
    printArray(arr,n);
}