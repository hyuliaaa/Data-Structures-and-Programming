#include <iostream>

struct Queue
{
    int front;
    int rear;
    int *arr;
    int size;
};

void create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->arr=new int [q->size];
}

void enqueue(Queue *q, int x) //add to back
{
    if(q->rear==q->size-1)
    {
        std::cout<<"Queue is full";
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=x;

    }
}

int dequeue(Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        std::cout<<"Queue is empty!";
    }
    else
    {
        q->front++;
        x=q->arr[q->front];
    }
    return x;
}

void print(Queue q)
{   int i;
    for( i=q.front+1; i<=q.rear;i++)
    {
        std::cout<<q.arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main() {
    Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    print(q);
    dequeue(&q);
    print(q);

    return 0;
}
