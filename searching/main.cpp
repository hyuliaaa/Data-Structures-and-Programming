#include <iostream>

int secondMax(int arr[], int n)
{
    int max=arr[0];
    int ind=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            ind=i;
        }
    }
    int secMax=0;
    for(int i=0; i<n;i++)
    {
        if(arr[i]>secMax && i!=ind)
        {
            secMax=arr[i];
        }
    }
    return  secMax;
}
int main()
{
    int arr[5]={2,5,63,8,9};
    int max;
    max=secondMax(arr,5);
    std::cout<<max;
    return 0;
}
