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


int main()
{

    int arr1[10]={2,5,8,12,3,6,7,10};

    mergeSingleArray(arr1,0,3,7);
    printArray(arr1,8);

    return 0;
}
