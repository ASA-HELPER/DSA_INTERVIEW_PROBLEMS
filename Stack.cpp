// Problem : Implement Stack using Array GFG
// TC => O(1) for push and pop functions
class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack ::push(int x)
{
    // Simply top ko as an index samjho jisse increment karke us index par hum element ko store kar rahe hai
    top++;
    arr[top] = x;
}

int MyStack ::pop()
{
    if (top != -1)
    {
        // pehle element ko apne pass variable mein store karna hai phir uske baad top ko decrement karna hai
        int ele = arr[top];
        top--;
        return ele;
    }
    // agar array hi empty hoga toh return kardo -1
    return -1;
}

// Problem : Implement Stack using Linked List GFG
struct StackNode
{
    int data;
    StackNode *next;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
}

class MyStack
{
private:
    StackNode *top;

public:
    MyStack()
    {
        top = NULL;
    }
    // TC => O(1) for push and pop
    // SC => O(1) fro push and pop
    void push(int x)
    {
        // ulti linked list bana rahe hai matlab new node ka next hoga previous node
        // simply hum new Node banakar uske next mein top ko daal denge lekin tab jab top NULL naa
        // ho warna top ko ki hi newNode assign kardenge and return kardenge
        StackNode *newNode = new StackNode(x);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        // newNode ke next mein top ko de do and top ko newNode banado
        newNode->next = top;
        top = newNode;
    }

    // Function to remove an item from top of the stack.
    int pop()
    {
        // agar top NULL hai toh -1 return kardo
        if (top == NULL)
        {
            return -1;
        }
        // topmost node ko apne paas rakhlo ek pointer mein
        StackNode *temp = top;
        // top ko uske next par le jaao visualization ke according previous node par
        top = top->next;
        // topmost node ki value nikal lo and temp pointer ko delete kardo
        int topValue = temp->data;
        delete temp;
        return topValue;
    }
}

// Problem : Sort a Stack GFG
// TC => O(N*N) because worst case mein ye ho sakta hai ki array decreasing ho toh insert and sort dono N times chalenge
// SC => O(N)
// insert ka kaam hai sabhi numbers ko unki correct position par rakhna sorted order mein.
void
insert(stack<int> &s, int x)
{
    // agar stack empty hai toh seedha insert kardenge uske top par jis bhi element ko insert karna hai
    if (s.empty())
    {
        s.push(x);
        return;
    }
    else
    {
        // agar stack ke top par jo element hai woh current element se bada hai toh recursively hum stack
        // se pop karte jaayenge elements ko and ek variable mein store kar lenge jab tak ek aisa element
        // nahi miljaata jo current element se chota hai and jese hi chota element mil jaaye toh current
        // element ko stack mein daal ke un elements ko phir recursively waapis jaate waqt push kardenge
        if (s.top() > x)
        {
            int top = s.top();
            s.pop();
            insert(s, x);
            s.push(top);
        }
        // agar stack ke top par jo element hai woh current element jisse insert karna hai usse chota hai
        // toh directly current element ko daaldo stack mein and return kardo
        else
        {
            s.push(x);
            return;
        }
    }
}

// Ye basically sabhi numbers ko recurively ek variable mein store karlega and phir insert ko call karega
void SortedStack ::sort()
{
    // Your code here
    if (s.empty())
    {
        return;
    }
    else
    {
        int top = s.top();
        s.pop();
        sort();
        // isse pehle tak hum bas ek simple sa kaam kar rahe hai ki stack se pop karte jaa rahe hai
        // and ek variable mein store kar rahe hai and jab stack empty hojaayega toh last stored value
        // ko lekar jaayenge aur usse stack mein correct position par rakh denge sorted order mein
        insert(s, top);
    }
}

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

// Problem : Reverse a stack GFG
class Solution
{
    // Is link par jaao dry run dikha rakha hai : https://www.techiedelight.com/reverse-stack-using-recursion/
public:
    // TC => O(N*N)    SC => O(N)
    // For each top element, we will pop it and call recursion to insert a given element at the bottom of the remaining stack. After recursive
    // function does its work and adds the given element to the bottom of stack, then we can simply push the popped element to the top of the stack.
    void insertAtBottom(stack<int> &st, int element)
    {
        if (st.empty())
        {
            st.push(element);
            return;
        }
        int num = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(num);
    }
    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;
        int num = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, num);
    }
};

// Problem : Maximum Absolute Difference GFG
class Solution
{
public:
    // TC => O(N)     SC => O(2N)
    vector<int> leftsmaller(int a[], int n)
    {
        stack<int> st;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            // jab tak stack ke top ki value greater than equal to hogi current element ke
            // tab tak stack se pop karte rahenge
            while (!st.empty() && st.top() >= a[i])
            {
                st.pop();
            }
            // agar stack empty hai toh 0 push kardenge
            if (st.empty())
            {
                v.push_back(0);
            }
            // warna vector mein stack ke top ki value ko append kardenge
            else
            {
                v.push_back(st.top());
            }
            st.push(a[i]);
        }
        return v;
    }
    vector<int> rightsmaller(int a[], int n)
    {
        stack<int> st;
        vector<int> v;
        // jab tak stack ke top ki value greater than equal to hogi current element ke
        // tab tak stack se pop karte rahenge
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= a[i])
            {
                st.pop();
            }
            // agar stack empty hai toh 0 push kardenge
            if (st.empty())
            {
                v.push_back(0);
            }
            // warna vector mein stack ke top ki value ko append kardenge
            else
            {
                v.push_back(st.top());
            }
            st.push(a[i]);
        }
        // kyunki hum last se element se chal kar vector ko prepare kar rahe hai toh
        // reverse karna padega
        reverse(v.begin(), v.end());
        return v;
    }
    int findMaxDiff(int a[], int n)
    {
        // har element ke liye left smaller and right smaller elements ko vectors mein store karwa lenge
        vector<int> ls = leftsmaller(a, n);
        vector<int> rs = rightsmaller(a, n);
        // stored vectors ki values ka difference nikal kar dekh lenge ki konsa maximum hai
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, abs(ls[i] - rs[i]));
        }
        return maxi;
    }
};

// Problem: The celebrity problem GFG
class Solution
{
    // Approach-1 : Using graph : Isme hum 2 vectors le lenge ek indegree aur ek outdegree and matrix ke through loop karke sabhi persons ki indegree
    // and outdegree ko calculate karlenge and jis bhi person ki outdegree 0 hogi and indegree n-1 hogi wahi hamara celebrity hoga
    // TC => O(N^2)   SC => O(2N)

    // Approach-2 : Using Stack
    // TC => O(N)    SC => O(N)
public:
    // Hume 2 cases ka dhyaan rakhna hai bas :
    // case-1 : Celebrity kisi ko naa jaanta ho matlab us particular person ki whole row mein bas zeroes hi present ho
    // case-2 : Celebrity ko sab jaante ho matlab us particular person ke number waale column mein (n-1) 1's hone chahiye
    // because usse khud ko chodkar baaki sab person usko jaante honge
    // n = 3   M = {{0,0,0},{0,0,0},{0,0,0}}  is particular case mein koyi celebrity nahi hoga
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        // Simply hum stack mein saare persons ko daal denge
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        // Jab tak stack mein khali celebrity nahi reh jaata tab tak hum har baar 2 persons
        // ko stack se nikal kar puchenge ki dono mein se kon kisko janta hai
        while (st.size() > 1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            // agar first person second person ko jaanta hai toh second ko push kardenge
            // because celebrity toh kisi ko jaanta hi nahi hai toh first person celebrity
            // nahi ho sakta hai
            if (M[first][second])
            {
                st.push(second);
            }
            // agar second person first person ko jaanta hai toh first ko push kardenge
            // because celebrity toh kisi ko jaanta hi nahi hai toh second person celebrity
            // nahi ho sakta hai
            else
            {
                st.push(first);
            }
        }
        // stack mein jo bhi celebrity raha hoga uske index ko rakh lenge apne paas
        int ans = st.top();
        int ZeroCount = 0;
        // ab hum ye check karenge ki hamari algorithm se jo celebrity aaya hai woh kahin
        // kisi ko jaanta toh nahi and agar nahi jaanta hoga toh uske row mein saare zeroes
        // present hone chahiye
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                ZeroCount++;
            }
        }
        // Agar celebrity ki row mein saarer zero nahi hai iska matlab woh kisi ko jaanta
        // hai toh party mein koyi bhi celebrity nahi hoga
        if (ZeroCount != n)
        {
            return -1;
        }
        // ab agar celebrity kisiko nahi jaanta hai toh hume ye check karna hoga ki kya baaki
        // sab persons jo party mein hai woh celebrity ko jaante hai toh iske liye hume celeberity
        // ke column mein check karna hoga ki (n-1) 1's hai ya nahi
        int OneCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
            {
                OneCount++;
            }
        }
        // agar number of ones n-1 ke equal nahi hai toh iska matlab sab log celebrity ko nahi
        // jaante toh iska matlab hamari party mein koyi celebrity hai hi nahi
        if (OneCount != n - 1)
        {
            return -1;
        }
        return ans;
    }
};

// Problem : Expression contains redundant bracket or not GFG
class Solution
{
public:
    int checkRedundancy(string s)
    {
        // TC => O(N)    SC => O(N)
        int n = s.size();
        stack<char> st;
        // Simply ek stack le lenge character type ka
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            // agar current character opening bracket hai ya phir operator hai toh usse seedha stack mein push kardo
            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            // agar closing bracket hai toh stack se pop karte jao elements jab tak tumhe opening bracket nahi milta
            // agar opening bracket se pehle ek bhi operator miljaata hai stack mein toh redudant bracket nahi hai
            // warna redundant brackets present hai
            else if (ch == ')')
            {
                bool operatorFound = false;
                while (!st.empty() && st.top() != '(')
                {
                    if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                    {
                        operatorFound = true;
                    }
                    st.pop();
                }
                // stack ke top par opening bracket present hai toh usse bhi remove karna padega
                st.pop();
                // agar operator nahi mila toh iska matlab redundant bracket hai
                if (!operatorFound)
                {
                    return true;
                }
            }
        }
        return 0;
    }
};