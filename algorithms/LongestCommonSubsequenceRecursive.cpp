#include <iostream>
#include <algorithm>
int max(int a,int b)
{
    return (a>b)?a:b;
}


int longestCommonSubsequenceRecursive(char A[], char B[], int i, int j)
{
    if(A[i]=='\0'|| B[j]=='\0')
    {
        return 0;
    }
    else if(A[i]==B[j])
    {
        return 1+longestCommonSubsequenceRecursive(A,B,i+1,j+1);
    }
    else
    {
        return max(longestCommonSubsequenceRecursive(A,B,i+1,j),longestCommonSubsequenceRecursive(A,B,i,j+1));
    }
}
int main()
{

    char A[]="bd";
    char B[]="abcd";
    std::cout<<longestCommonSubsequenceRecursive(A,B,0,0);

    return 0;
}
