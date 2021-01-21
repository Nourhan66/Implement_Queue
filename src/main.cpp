#include<iostream>
using namespace std;

#define ARRAY_BASED_QUEUE
#include"queue.cpp"


int main()
{
    Queue q;
    int elem;
    CreateQueue(&q);
    Append(5,&q);
    Append(9,&q);
    Append(6,&q);
    Append(18,&q);
    Append(1,&q);
    TraverseQueue(&q,&Display);
    serve(&elem,&q);
    serve(&elem,&q);
    TraverseQueue(&q,&Display);
    int size;
    size=QueueSize(&q);
    cout<<"Size of Queue : "<<size<<endl;
    ClearQueue(&q);
    size=QueueSize(&q);
    cout<<"Size of Queue : "<<size<<endl;
}
