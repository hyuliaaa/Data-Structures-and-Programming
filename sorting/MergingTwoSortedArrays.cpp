#include <iostream>
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void printArray(int arr[], int n)
{
    for(int i=0; i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

int *merge(int A[],int n, int B[],int m)
{
    int *C=new int[n+m];
    int i=0;
    int j=0;
    int k=0;

    while(i<n && j<m)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            k++;
            i++;
        }
        else
        {
            C[k]=B[j];
            k++;
            j++;
        }
    }
    for(;i<n;i++)
    {
        C[k]=A[i];
        k++;
    }

    for(;j<n;j++)
    {
        C[k]=B[j];
        k++;
    }
    return C;
}
int main()
{

    int arr1[5]={2,10,18,20,23};
    int arr2[4]={4,9,19,25};
    int *newArr=merge(arr1,5,arr2,4);
    printArray(newArr,9);


    return 0;
}
