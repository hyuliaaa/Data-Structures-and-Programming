#include <iostream>

void bubbleSort(int arr[],int n)
{
    bool isSorted;
    for(int i=0; i<n-1;i++)
    {
        isSorted= false;
        for(int j=0; j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSorted=true;
            }

        }

    }
    if(isSorted== false)
    {
        std::cout<<"The array is already sorted"<<std::endl;
        return;
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
    int arr[5]={2,3,6,8,9};
    bubbleSort(arr,5);

    int arr1[5]={3,1,7,8,9};
    bubbleSort(arr1,5);
    printArray(arr1,5);
    return 0;
}
