  #include <iostream>
#include <queue>

using namespace std;

void BFS(int G[][7], int startPoint, int dimension)
{
    int i=startPoint;
    queue<int>q;
    //array which contains all the vertices that we have visited
    int visited[7]={0};

    //printing the starting point
    cout<<i<<" ";
    //marking the place as visited
    visited[i]=1;
    //pushing it in the queue
    q.push(i);

    while(!q.empty())
    {
        //taking the first element of the queue
        i=q.front();
        //removing it from the queue
        q.pop();
        
        for(int j=1; j<dimension; j++)
        {
            //if we have a rib between the verteces, and the current vertex is not visited
            if(G[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }

}



void DFS(int matrix[][7], int startingPoint, int dimension)
{
    static int visited[7]={0};
    if(visited[startingPoint]==0)
    {
        cout<<startingPoint<<" ";
        visited[startingPoint]=1;
        for(int j=1; j<dimension; j++)
        {
            if(matrix[startingPoint][j]==1 && visited[j]==0)
            {
                DFS(matrix,j,dimension);
            }
        }
    }
}

int main()
{
    int G[7][7]= {{0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1, 0, 0},
                  {0, 1, 0, 0, 1, 0, 0},
                  {0, 0, 1, 1, 0, 1, 1},
                  {0, 0, 0, 0, 1, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0}};
    BFS(G,1,7);
    DFS(G,1,7); //1,2,4,3,5,6,



     return 0;
}
  
            1
         /      \
        /        \
       2          3
       \         / 
         \      /
             4
            / \
           /   \
          5     6 
    
              
              
              
              
              
 #include <iostream>
#include <queue>

void BFS(int mat[][8], int start, int n)
{
    int visited[8]={0};
    std::cout<<start<<" ";
    std::queue<int> q;
    visited[start]=1;
    q.push(start);

    while (!q.empty())
    {
        int takeVertex=q.front();
        q.pop();
        for(int v=1; v<=n;v++)
        {
            if(mat[takeVertex][v]==1 && visited[v]==0)
            {
                std::cout<<v<<" ";
                visited[v]=1;
                q.push(v);
            }

        }

    }
}
int main() {



    int G[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,1,0,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0}};
    BFS(G,1,8);
    return 0;
}             
    
