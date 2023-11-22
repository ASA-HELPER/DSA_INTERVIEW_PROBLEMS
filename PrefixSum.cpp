// Problem : Subarray sum equals k LeetCode
class Solution
{
public:
    // Brute Force Approach : Simply two for loops ka use karenge check karlenge ki kitne subarrays ka sum equal to k hai.
    // TC => O(N)   SC => O(2N)
    int subarraySum(vector<int> &nums, int k)
    {
        int n = arr.size();
        int prefix[n];
        prefix[0] = arr[0];
        // Simple prefix sum array banayenge
        for (int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        // ek map le lenge jisme hum prefix sum ko store karenge
        unordered_map<int, int> mp;
        // Ek variable le lenge number of subarrays ko count karne ke liye
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        for (int i = 0; i < n; i++)
        {
            // Agar prefix sum already hi equal to k hai toh hume ek subarray milgaya hai toh answer ko increment kardenge
            if (prefix[i] == k)
                ans++;

            // Ab hum yahan ye check karenge ki agar hamare paas current prefix sum hai toh usme se k ko minus karenge toh kya hume map mein difference milega kya
            // Agar woh difference map mein hoga toh uski frequency ko hum apne answer mein add kardenge
            if (mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k];
            }
            // current prefix sum ko map mein put kardo
            mp[prefix[i]]++;
        }
        return ans;
    }
};