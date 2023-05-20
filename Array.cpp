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

// Problem : Quick Left Rotation GFG
class Solution
{
    // Time Complexity : O(N)
    // Space Complexity : O(1)
public:
    void rotate(int arr[], int i, int j)
    {
        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    void leftRotate(int arr[], int k, int n)
    {
        // k ko n se mod isliye kiya taaki agar k ki value n se greater hai toh usse within n kar sake
        k = k % n;
        // observation ka khel hai saara
        // case-1 : 0 se (k-1)th tak elements ko reverse kardo
        rotate(arr, 0, k - 1);
        // case-2 : kth se (k-1)th tak elements ko reverse kardo
        rotate(arr, k, n - 1);
        // case-3 : 0 se (n-1)th tak ke elements ko reverse kardo
        rotate(arr, 0, n - 1);
    }
};

// Problem : Longest Sub-Array with sum K
class Solution
{
public:
    int lenOfLongSubarr(int a[], int n, int k)
    {
        // Complete the function
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i:
            sum += a[i];

            // if the sum = k, update the maxLen:
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e. x-k:
            int rem = sum - k;

            // Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

// Problem : Find all pairs with a given sum GFG
class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Approach-2 : Using hashmap : Isme simply ek array ke saare numbers ko map mein rakh denge and phir dusre array ke saare elements
        // ko given sum se subtract karke dekhenge one by one ki kya difference jo mil raha hai woh map mein exist karta hai ya nahi.
        // TC => O(N+M)  SC => O(N) because we are unordered_map
        vector<pair<int, int>> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[A[i]]++;
        }
        for (int i = 0; i < M; i++)
        {
            if (mp[X - B[i]])
            {
                res.push_back({X - B[i], B[i]});
            }
        }
        sort(res.begin(), res.end());
        return res;

        // Approach-3 : Using two pointers : Is solution ko hum tab use kar sakte hai jab hume ye check karna ho ki kinhi two elements
        // ka sum X ke equal hai toh return true warna return false ya phir koyi single pair ko find karna ho toh
        // TC => O(NlogN)   SC=>O(1) if we do not consider the array we are making by combining the given two arrays
        // vector<int>arr;
        // for(int i=0;i<max(N,M);i++)
        // {
        //     if(i<N)
        //     {
        //         arr.push_back(A[i]);
        //     }
        //     if(i<M)
        //     {
        //         arr.push_back(B[i]);
        //     }
        // }
        // sort(arr.begin(), arr.end());
        // int left = 0, right = arr.size() - 1;
        // while (left < right)
        // {
        //     int sum = arr[left] + arr[right];
        //     if (sum == X) {
        //         return {arr[left],arr[right]};
        //         // return true;
        //     }
        //     else if (sum < X)
        //         left++;
        //     else
        //         right--;
        // }
        // agar ek bhi pair naa mile toh
        // return false or empty pair;
    }
};