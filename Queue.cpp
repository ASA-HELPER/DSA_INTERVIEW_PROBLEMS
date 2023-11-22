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

// Problem : Deque Implementations GFG
// TC => O(1) SC => O(1) for all operations
// Function to push element x to the back of the deque.
void push_back_pb(deque<int> &dq, int x)
{
    // Your code here
    dq.push_back(x);
}

// Function to pop element from back of the deque.
void pop_back_ppb(deque<int> &dq)
{
    if (!dq.empty())
    {
        dq.pop_back();
    }
    else
        return;
}

// Function to return element from front of the deque.
int front_dq(deque<int> &dq)
{
    if (!dq.empty())
    {
        return dq.front();
    }
    else
        return -1;
}

// Function to push element x to the front of the deque.
void push_front_pf(deque<int> &dq, int x)
{
    dq.push_front(x);
}

// Problem : Generate Binary Numbers GFG
// TC => O(N)   SC => O(N)
vector<string> generate(int N)
{
    vector<string> ans;
    queue<string> q;
    // simply queue ka istemaal karke hum usme har number ki binary string banakar push karenge
    // uske pehle ke numbers ka use karke. For example, N = 5 ke liye dry run dekho :
    // q = {"1"}                                          ans = {}
    // q = {"10","11"}                                    ans = {"1"}
    // q = {"11","100","101"}                             ans = {"1","10"}
    // q = {"100","101","110","111"}                      ans = {"1","10","11"}
    // q = {"101","110","111","1000","1001"}              ans = {"1","10","11","100"}
    // q = {110","111","1000","1001","1010","1011"}       ans = {"1","10","11","100","101"}
    q.push("1");
    for (int i = 1; i <= N; i++)
    {
        string bin = q.front();
        ans.push_back(bin);
        q.pop();
        q.push(bin + "0");
        q.push(bin + "1");
    }
    return ans;
}

// Problem : First non-repeating character in a stream GFG
class Solution
{
public:
    // 	TC => O(26*N)
    //  SC => O(N)
    string FirstNonRepeating(string A)
    {
        int n = A.size();
        //  ek queue le lenge taaki ye pata kar saken ki konsa character current index tak
        // sirf ek hi baar aaya hai
        queue<char> q;
        //  ek frequency vector rakh lenge jo ki help karega ye pata karne mein ki current
        // character kitni baar aa chuka hai abhi tak
        vector<int> freq(26, 0);
        for (int i = 0; i < A.size(); i++)
        {
            freq[A[i] - 'a']++;
            //  agar character pehli baar aaya hai toh usse queue mein daaldo
            if (freq[A[i] - 'a'] == 1)
            {
                q.push(A[i]);
            }
            //  agar queue empty nahi hai and queue mein jo elements hai unki frequency 1 se
            // zyada hai toh queue se pop karte rahenge
            while (!q.empty() && freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            //  agar queue khali ho jaata hai toh iska matlab hai ki current character ke
            // liye koyi bhi non repeating character nahi hai abhi tak warna queue ka front
            // de denge
            if (q.empty())
            {
                A[i] = '#';
            }
            else
            {
                A[i] = q.front();
            }
        }
        return A;
    }
};