// Problem : Implement Queue using array GFG
// TC => O(1)     SC => O(1)
class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int x)
    {
        arr[rear++] = x;
    }
    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front++];
    }
};

// Problem : Implement Queue using Linked List GFG
// TC => O(1)     SC => O(1)
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;
    MyQueue()
    {
        front = rear = NULL;
    }
    void push(int x)
    {
        QueueNode *node = new QueueNode(x);
        if (front == NULL && rear == NULL)
        {
            front = node;
            rear = node;
        }
        rear->next = node;
        rear = rear->next;
    }
    int pop()
    {
        if (front == NULL && rear == NULL)
        {
            front = NULL;
            rear = NULL;
            return -1;
        }
        if (front == rear)
        {
            int popped = front->data;
            front = NULL;
            rear = NULL;
            return popped;
        }
        int popped = front->data;
        front = front->next;
        return popped;
    }
};