// Problem : Arithmetic Subarrays LeetCode
class Solution
{
public:
    // TC => O((N^2)logN)       SC => O(N)
    // Is function ki help se simply ye check kar paayenge ki adjacent elements ke beech ka difference same hai ya nahi
    bool isArithmetic(vector<int> &temp)
    {
        int n = temp.size();
        int diff = temp[1] - temp[0];
        for (int i = 1; i < n - 1; i++)
        {
            if ((temp[i + 1] - temp[i]) != diff)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        // ek vector le lenge final answer ke liye
        vector<bool> res(n);
        // l and r waale vectors mein traverse karenge
        for (int i = 0; i < n; i++)
        {
            int start = l[i];
            int end = r[i];
            // current range mein jo numbers hai unhe ek temporary vector mein store karlenge and phir ussee sort karlenge
            vector<int> temp;
            for (int j = start; j <= end; j++)
            {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            if (isArithmetic(temp))
            {
                res[i] = true;
            }
            else
            {
                res[i] = false;
            }
        }
        return res;
    }
};

// Problem : Minimum swaps to sort GFG
class Solution
{
    // TC => O(NlogN)       SC => O(n)
public:
    int minSwaps(vector<int> &nums)
    {
        // Ek temporary vector le lenge jisme store kardenge apne given vector ko and usse
        // sort kardenge and store vector ke elements ko ek map mein unke index ke saath map
        // kardenge taaki ye pata kar paayen ki sorted array mein har element ki correct position
        // kahan par hai
        vector<int> temp = nums;
        unordered_map<int, int> mp;
        int n = nums.size();
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++)
        {
            mp[temp[i]] = i;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            // agar current index par jo element hai uska correct index current index nahi hai toh
            if (mp[nums[i]] != i)
            {
                count++;

                // swap karke current element ko uske correct position par pauncha denge
                swap(nums[i], nums[mp[nums[i]]]);
                // i ko decrement isliye kiya taaki ye check kar sake ki current element
                // correct position par pauncha ya nahi
                i--;
            }
        }
        return count;
    }
};