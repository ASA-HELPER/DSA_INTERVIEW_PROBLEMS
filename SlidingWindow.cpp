// Problem : Smallest window containing 0, 1 and 2 GFG
class Solution
{
public:
    // Time Complexity : O(N)
    // Space Complexity : O(1)
    int smallestSubstring(string S)
    {
        int n = S.size();
        int i = 0;
        int j = 0;
        // ek vector le lenge 3 size ka jisme count karlenge 0,1,2 ki values ko
        vector<int> res(3, 0);
        int minWin = INT_MAX;
        while (j < n)
        {
            // extract kar rahe hai number ko string mein se
            int num = int(S[j]) - 48;
            // increment kar rahe hai current ki frequency ko
            res[num]++;
            // agar 0,1,2 ki frequencies greater than 0 hai toh
            // hum second pointer variable ko increment karenge and har baar minimum le lenge
            // second pointer variable par jo number hai uski frequency decrease kardenge
            if (res[0] > 0 && res[1] > 0 && res[2] > 0)
            {
                while (i < j && (res[0] > 0 && res[1] > 0 && res[2] > 0))
                {
                    minWin = min(minWin, j - i + 1);
                    num = int(S[i]) - 48;
                    res[num]--;
                    i++;
                }
            }
            j++;
        }
        // agar kabhi bhi 0,1,2 hai hi nahi aapke kisi ek window mein toh answer -1 hoga
        if (minWin == INT_MAX)
        {
            return -1;
        }
        return minWin;
    }
};

// Problem : Count the subarrays having product less than k GFG
class Solution
{
public:
    // TC => O(N)  SC => O(1) hogi
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        // Agar k hi 1 hai toh koyi product isse less hoga hi nahi toh subarrays zero honge
        if (k == 1)
        {
            return 0;
        }
        // simply sliding window approach lagakar dekhenge
        int i = 0;
        int j = 0;
        long long int product = 1;
        int count = 0;
        while (j < n)
        {
            product *= a[j];
            if (product >= k)
            {
                while (product >= k)
                {
                    product /= a[i];
                    i++;
                }
            }
            // har length ke subarrays ko count karte rahenge
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};

// Problem : Count the number of subarrays having sum between L to R GFG
class Solution
{
    // TC => O(2N)   SC => O(1)
    // Hume woh subarray chahiye jinke elments ka sum between L and R ho toh hum ek kaam kar sakte hai ki un subarrays ko count karle
    // jinka sum L se less ho and un subarrays ko separately count karle jinka sum less than equal to R ho and phir dono ko subtract karle
    // jisse hum woh subarrays mil jaayenge jinka sum between L and R hoga
public:
    // Simply sliding winfow ka concept use kar rahe hai agar sum>target ho jaata hai toh sum ko decrease karne ki try karenge warna har baar
    // current subarray mein kitne subarray ban rahe hai ye count karlenge
    long long helper(vector<int> A, long long k, long long N)
    {
        int i = 0;
        int j = 0;
        long long count = 0;
        long long sum = 0;
        while (j < N)
        {
            sum += (long long)A[j];
            if (sum > k)
            {
                while (sum > k)
                {
                    sum -= (long long)A[i];
                    i++;
                }
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    long long countSubarray(int N, vector<int> A, long long L, long long R)
    {
        // Hum un subarrays ko count kar rahe hai jinka sum less than L ho because isse hum exclude kar paayenge inhe apne final answer mein
        long long maxSumL = helper(A, L - 1, N);
        // Hum un subarrays ko count kar rahe hai jinka sum less than equal to R ho taaki inme mein se un subarrays ko remove kar sake jinka
        // sum less than L hai taaki hume woh subarrays mil jaayen jinka sum L to R mein hai
        long long maxSumR = helper(A, R, N);
        return abs(maxSumR - maxSumL);
    }
};