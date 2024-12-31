#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n)
{
    for (int i=0; i<n-1; i++)
    {
        // Find the index of the smallest element in the unsorted portion
        int minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if (arr[j]< arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the smallest element with the first element of the unsorted portion
        int temp =arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
}
// Function to print the array
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
    int arr[]={12,54,65,3,43,23,21};
    int n= sizeof(arr)/sizeof(arr[0]);

    cout<<"Orignal Array:"<<endl;
    printArray(arr,n);

    SelectionSort(arr,n);

    cout<<"Sorted Array:"<<endl;
    printArray(arr,n);
}