#include <iostream>

int binarySearch(int arr[],int l, int h, int key)
{
    if(h>=l) {
        int medium = (l + h) / 2;
        if (arr[medium] == key) {
            return key;
        } else if (arr[medium] > key) {
            return binarySearch(arr, l, medium - 1, key);
        } else {
            return binarySearch(arr, medium + 1, h, key);
        }
    }
    return -1;
}
int main()
{
    int arr[5]={2,3,6,8,9};
    std::cout<<binarySearch(arr,0,4, 7);
    return 0;
}
