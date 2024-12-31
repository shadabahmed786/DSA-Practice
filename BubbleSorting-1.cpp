#include<iostream>
using namespace std;// Time Comp 0(n^2)

// Function to perform Bubble Sort:
void BubbleSort(int arr[],int n)
{
    for (int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            // Swap if elements are out of order:
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
}

// Function to print the array:
void PrintArray(int arr[],int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    cout<<endl;
}
int main()
{
    int arr[]={12,13,43,54,12,87,34};
    int n= sizeof(arr)/sizeof(arr[0]);// Number of elements in the array

    cout<<"Orignal Array:";
    PrintArray(arr,n);

    BubbleSort(arr,n);

    cout<<"Sorted Array:";
    PrintArray(arr,n);

    return 0;

}
