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

// Problem : Remove duplicate elements from sorted Array in O(1) space GFG
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

// Problem : Union of two sorted arrays GFG
class Solution
{
    // Brute Force : map ya set ka use karke kar sakte hai but unordered_map ya unordered_set ka use nahi kar sakte because usme array
    // sorted nahi rahega. TC => O((n+m)log(n+m)) , SC => O(n+m)
    // Timc Complexity : O(n+m)
    // Space Complexity : O(1) agar resultant array ke size ko consider naa karen toh
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> res;
        int i = 0;
        int j = 0;
        // two pointers ka istemal karke dono arrays mein forward move karenge
        while (i < n && j < m)
        {
            // agar first array ka element smaller hai toh usse push karenge resultant array mein tab jab woh resultant array ke last
            // element ke equal na ho and same yehi condition tab bhi dekhenge jab first array ka element second array ke element se
            // greater hoga toh
            if (arr1[i] <= arr2[j])
            {
                if (res.size() == 0 or res.back() != arr1[i])
                {
                    res.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if (res.size() == 0 or res.back() != arr2[j])
                {
                    res.push_back(arr2[j]);
                }
                j++;
            }
        }
        // agar first array mein koyi element reh gaya ho toh usse condition check karke add karlenge
        while (i < n)
        {
            if (res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        // agar first array mein koyi element reh gaya ho toh usse condition check karke add karlenge
        while (j < m)
        {
            if (res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
        return res;
    }
};

// Problem : Check if array is sorted without sorting in O(N) time and O(1) space GFG
class Solution
{
public:
    bool arraySortedOrNot(int arr[], int n)
    {
        if (n == 2 && (arr[0] > arr[1]))
        {
            return false;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if ((arr[i - 1] > arr[i]) or (arr[i] > arr[i + 1]))
            {
                return false;
            }
        }
        return true;
    }
};