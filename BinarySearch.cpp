// Problem : Missing element of AP (GFG)
class Solution
{
public:
    int findMissing(int arr[], int n)
    {
        // Approach-1 : O(N)
        // Using AP formula : last = first + (n-1)*diff
        int last = arr[n - 1];
        int first = arr[0];
        // formula ki help se hum ye nikal lenge ki har adjacent number ke beech mein kya difference hai
        int diff = (last - first) / n;
        // ek variable le lenge
        int mis = -1;
        for (int i = 1; i < n; i++)
        {
            // agar previous element mein difference ko add karne par current element nahi ban raha hai toh yehi hamara answer hoga
            if ((arr[i - 1] + diff) != arr[i])
            {
                mis = arr[i - 1] + diff;
                break;
            }
        }
        return mis;

        // Approach-2 : O(logN)
        // Using Binary search
        int mis = -1;
        int diff = (arr[n - 1] - arr[0]) / n;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int actualMidVal = arr[0] + mid * diff;
            if (arr[mid] == actualMidVal)
            {
                low = mid + 1;
            }
            else
            {
                mis = actualMidVal;
                high = mid - 1;
            }
        }
        return mis;
    }
};

// Problem : Find the element that appears once GFG
class Solution
{
public:
    // Approach-1 : Simple brute force chala kar dikha do using 2 for loops jisme ye check karlo ki kab ek element kisi bhi next
    // element ke equal nahi hai toh wahi hamara answer hoga. TC => O(N^2) and SC => O(1)

    // Approach-2 : Use unordered_map jiski help se jis bhi element ki frequency 1 hogi wahi hamara answer hoga.
    // TC => O(N) and SC => O(N)

    int search(int A[], int N)
    {
        // Approach-3 : Saare numbers ka XOR kardenge because jab bhi 2 numbers ka XOR karte hai toh value 0 hojati hai and last mein
        // ek hi element bachega jo ki single element hoga. TC => O(N) and SC => O(1)
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans ^= A[i];
        }
        return ans;

        // Approach-4 : using binary search : Iske liye mein code jaldi hi yahan update karunga. TC =. O(logN) and SC => O(1)
    }
};

// Problem : Maximum Sum of rectangle No longer than K
class Solution
{
public:
    // TC => O(cols*cols*rows*log(rows))
    // SC => O(rows)
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int res = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
        // Columns mein traverse karte huye column sum nikalenge
        for (int left = 0; left < cols; left++)
        {
            vector<int> sums(rows, 0);
            for (int right = left; right < cols; right++)
            {
                // Ye basically ek row ka prefix sum nikal rahe hai
                for (int i = 0; i < rows; i++)
                {
                    sums[i] += matrix[i][right];
                }
                set<int> s = {0};
                int run_sum = 0;
                // ab row ke prefix sum waale array mein se sum ko nikal kar add karte jaayenge and usme se k ko minus karke uska lower bound
                // find karenge set mein and agar woh set mein mil jaata hai toh check karlenge ki kya woh maximum hai warna usse set mein daaldenge
                for (int sum : sums)
                {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != s.end())
                    {
                        res = max(res, run_sum - (*it));
                    }
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};