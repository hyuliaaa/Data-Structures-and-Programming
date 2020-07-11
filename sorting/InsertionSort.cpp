#include <iostream>

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++) //number of passes
    {
        int j=i-1;
        int key=arr[i];
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}
int main()
{


    int arr1[5]={3,1,7,8,9};
    insertionSort(arr1,5);
    printArray(arr1,5);
    return 0;
}
