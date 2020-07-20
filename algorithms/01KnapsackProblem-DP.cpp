#include <iostream>

int max(int a, int b)
{
    return (a > b) ? a:b;
}
int main()
{
    int p[5]={0,1,2,5,6}; // profit
    int wt[5]={0,2,3,4,5}; //weight
    int m=8;//capacity
    int n=4; //number of objects;
    int k[5][9];
    int w=0;

    for(int i=0; i<=n;i++)
    {
        for( w=0;w<=m;w++)
        {
            if(i==0 || w==0)
            {
                k[i][w]=0; // fill first row and first column with 0
            }
            else if(wt[i]<=w)
            {
                k[i][w]=max(k[i-1][w], k[i-1][w-wt[i]]+p[i]);
            }
            else
            {
                k[i][w]=k[i-1][w]; //value of previous row
            }
        }
    }
    std::cout<<k[n][m];


    return 0;
}
