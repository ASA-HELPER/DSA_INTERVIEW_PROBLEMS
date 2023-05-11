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