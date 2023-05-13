// Problem : Uncrossed lines Leetcode
class Solution
{
public:
    int helper(vector<int> &nums1, vector<int> &nums2, int i, int j, int n, int m, unordered_map<string, int> &mp)
    {
        if (i == n or j == m)
        {
            return 0;
        }
        string key = to_string(i) + "#" + to_string(j);
        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }
        int count = 0;
        // agar dono arrays ke current index par same number hai toh hum line banayenge unke beech mein and count ko increase kardenge by 1
        if (nums1[i] == nums2[j])
        {
            count = 1 + helper(nums1, nums2, i + 1, j + 1, n, m, mp);
        }
        // agar dono arrays ke current index par same number nahi hai toh hum dono arrays ke current index ko ek ek karke chance denge like this;
        // array1 = [1,4,2] and array2 = [1,2,4]
        // upar waale arrays mein jab hum index 1 par honge dono arrays ke toh hum ek baar array1 ke 4 ko chance denge and array2 mein aage chale jayenge and ek baar array2 ke 2 ko choice denge and array1 mein aage chale jaayenge
        // jab waapis aayenge toh ye dekh lenge ki kon zyada maximum number of lines bana raha hai
        else
        {
            count += max(helper(nums1, nums2, i + 1, j, n, m, mp), helper(nums1, nums2, i, j + 1, n, m, mp));
        }
        return mp[key] = count;
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<string, int> mp;
        return helper(nums1, nums2, 0, 0, n, m, mp);
    }
};

// Problem : Count ways to build good strings Leetcode
class Solution
{
public:
    vector<int> dp;
    int mod = 1e9 + 7;
    long ans = 0;
    int helper(vector<int> &dp, int target, int zero, int one)
    {
        // agar length less hogayi zero se toh hum hume ek bhi way nahi mila hai
        if (target < 0)
        {
            return 0;
        }
        // agar length 0 hogi toh matlab hume ek way milgaya hai targeted length banane ke liye
        if (target == 0)
        {
            return 1;
        }
        // agar given length ke liye already check kar chuke hai toh return kardo jitne ways bane the
        if (dp[target] != -1)
        {
            return dp[target];
        }
        // two choices hai ya toh zeroes ko append kar sakte hai ya phir ones ko append kar sakte hai
        int takingones = helper(dp, target - one, zero, one);
        int takingzeroes = helper(dp, target - zero, zero, one);
        // dono choices ko consider karke jitne bhi strings banenge unka sum lenge total number of ways ke liye and usse store kar lenge ki given targeted length ke liye itne total strings ban sakte hai
        return dp[target] = (takingones + takingzeroes) % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        // dp ka size high length ke barabar lenna hoga toh 1 extra le lenge size ko as per coin change problem
        dp.resize(high + 1, -1);
        // yahan har length ke liye dhundenge ki kitne good strings ban sakte hai
        for (int target = low; target <= high; target++)
        {
            ans = ((ans % mod) + helper(dp, target, zero, one)) % mod;
        }
        return ans;
    }
};