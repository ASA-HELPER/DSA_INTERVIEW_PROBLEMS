// Problem : Binary Array Sorting GFG
void binSort(int A[], int N)
{
    int i = 0;
    int j = N - 1;
    while (i < j)
    {
        // agar first position par 1 hai and last position par 0 hai toh swap kardo
        if (A[i] == 1 && A[j] == 0)
        {
            A[i] = 0;
            A[j] = 1;
            i++;
            j--;
        }
        // agar starting pointer par pehle se hi 0 hai toh aage badho
        if (A[i] == 0)
        {
            i++;
        }
        // agar ending pointer par pehle se hi 1 hai toh aage badho
        if (A[j] == 1)
        {
            j--;
        }
    }
}

// Problem : Greater on right side GFG
class Solution
{
public:
    void nextGreatest(int arr[], int n)
    {
        int nextGreater = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = nextGreater;
            nextGreater = max(temp, nextGreater);
        }
    }
};

// Problem : Remove duplicate elements from sorted Array in O(1) space
class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (a[j] != a[i])
            {
                i++;
                a[i] = a[j];
            }
        }
        return i + 1;
    }
};