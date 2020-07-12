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

void mergeSingleArray(int arr[],int l,int mid, int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int B[h+1];
    while (i<=mid && j<=h)
    {
        if(arr[i]<arr[j])
        {
            B[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            B[k]=arr[j];
            k++;
            j++;
        }
    }

    for(;i<=mid;i++)
    {
        B[k]=arr[i];
        k++;
    }
    for (; j <=h ; ++j) {
        B[k]=arr[j];
        k++;
    }

    for (int m = l; m <=h ; ++m) {
      arr[m]=B[m];
    }


}

void mergeSortRecursive(int arr[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergeSortRecursive(arr,l,mid);
        mergeSortRecursive(arr,mid+1,h);
        mergeSingleArray(arr,l,mid,h);
    }
}


int main()
{

    int arr1[10]={8,2,9,6,5,3,7,4};
    mergeSortRecursive(arr1,0,7);

    printArray(arr1,8);

    return 0;
}
