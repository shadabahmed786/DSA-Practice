#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    for (int i=1; i<n; i++)
    {
        int key = arr[i];
        int j= i-1;

        while(j>=0 && arr[j] >key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

void printArray(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
}

int main()
{
    int arr[]={1,3,76,52,23,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Orignal Array:";
    printArray(arr,n);

    InsertionSort(arr,n);

    cout<<"Sorted Array:";
    printArray(arr,n);
}