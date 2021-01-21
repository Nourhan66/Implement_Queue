#ifdef ARRAY_BASED_QUEUE
#include"../include/queue.h"

void CreateQueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void Append(int elem, Queue*pq)
{
    if(!QueueFull(pq))
        cout<<"Queue is full !/n";
    else
    {
        pq->rear=(pq->rear+1)%MaxSize;
        pq->data[pq->rear]=elem;
        pq->size++;
    }
}

void serve(int *pe, Queue *pq)
{
    *pe=pq->data[pq->front];
    pq->front=(pq->front+1)%MaxSize;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    if(!pq->size)
        return 0;
    else
        return 1;
}

int QueueFull(Queue *pq)
{

    if(pq->size==MaxSize)
        return 0;
    else
        return 1;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear  = -1;
    pq->size  = 0;
}

void TraverseQueue(Queue *pq, void(*pf)(int))
{
     int i=1;
    for(int pos=pq->front; i<=pq->size; i++)
    {
        (*pf)(pq->data[pos]);
        pos=(pos+1)% MaxSize;
    }
    cout<<endl;
}

void Display(int elem)
{
    cout<<elem<<" ";
}


#else
#include"../include/queue.h"

void CreateQueue(Queue* pq)
{
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}

void Append(int elem, Queue* pq)
{
    QueueNode* pn=(QueueNode*)malloc(sizeof(QueueNode));
    if(!pn)
        cout<<"There is no enough memory to append more data !"<<endl;
    else
    {
        pn->next=NULL;
        pn->data=elem;
        if(!pq->rear)
            pq->front=pn;
        else
            pq->rear->next=pn;
        pq->rear=pn;
        pq->size++;
    }
}

void Serve(int* pe,Queue* pq)
{
    QueueNode* pn=pq->front;
    *pe=pn->data;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
        pq->rear=NULL;
    pq->size--;

}

int QueueEmpty(Queue* pq)
{
    if(!pq->size)
        return 0;
    else
        return 1;
}

int QueueFull(Queue* pq)
{
    return 0;
}

int QueueSize(Queue* pq)
{
    return pq->size;

}
void  ClearQueue(Queue* pq)
{
    while(pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
        pq->size=0;
    }
}

void TraverseQueue(Queue* pq, void(*pf)(int))
{
    for(QueueNode* pn=pq->front; pn; pn=pn->next)
    {
        (*pf)(pn->data);
    }
    cout<<endl;
}
void Display(int elem)
{
    cout<<elem<<" ";
}


#endif
