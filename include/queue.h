#ifdef ARRAY_BASED_QUEUE

const int MaxSize = 1000;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int data[MaxSize];
} Queue;

void CreateQueue(Queue*);

void Append(int,Queue*);

void serve(int*,Queue*);

int QueueEmpty(Queue*);

int QueueFull(Queue*);

int QueueSize(Queue*);

void ClearQueue(Queue*);

void TraverseQueue(Queue*,void(*pf)(int));

void Display(int);


#else

typedef struct queueNode
{
    int data;
    struct queueNode *next;
} QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void CreateQueue(Queue*);

void Append(int,Queue*);

void Serve(int*,Queue*);

int QueueEmpty(Queue*);

int QueueFull(Queue*);

int QueueSize(Queue*);

void ClearQueue(Queue*);

void TraverseQueue(Queue*,void(*)(int));

void Display(int);


#endif
