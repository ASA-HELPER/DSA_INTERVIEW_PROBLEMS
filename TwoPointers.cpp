// Problem : Move all zeroes to end of array GFG
class Solution
{
    // Brute force : Simply zero mile toh usse erase kardo and number of zeroes ko count karke aage baad
    // jao and phir ek loop lagakar utne number of zeroes ko append kardo
public:
    // Time Complexity : O(N) because hum simply array ko hi baar traverse kar rahe hai using two pointers
    // Space Compllexity : O(1)
    void pushZerosToEnd(int arr[], int n)
    {
        int i = 0;
        int j = 1;
        while (j < n)
        {
            // agar zero milega toh hum aesa non-zero number same order mein dhundenge jiske saath hum 0 swap kar saken
            if (arr[i] == 0)
            {
                while (j < n && arr[j] == 0)
                {
                    j++;
                }
                // aesi condition aa sakti hai ki saare zeroes ho toh usme out of loop chala zayega toh swap tabhi karenge jab j<n ho
                if (j < n)
                    swap(arr[j], arr[i]);
                i++;
            }
            // agar ith position ka element zero nahi hai toh aage badho
            else
            {
                i++;
            }
            // j ko hamesha aage move karte rahenge taaki jab par swap karne par zero agaya ho toh aage move karte usse bhi remove kar saken
            j++;
        }
    }
};

// Problem : Maximum number of 1's GFG
class Solution
{
public:
    int findZeroes(int arr[], int n, int m)
    {
        // Two pointers ka problem hai ye
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = -1;
        while (j < n)
        {
            // agar zero aaya toh count bada denge
            if (arr[j] == 0)
            {
                count++;
            }
            // jab bhi zeroes increase ho jayenge toh maximum leke zeroes ko m se less karne ki try karenge
            if (count > m)
            {
                ans = max(ans, j - i);
                while (i < j && count > m)
                {
                    if (arr[i] == 0)
                    {
                        count--;
                    }
                    i++;
                }
            }
            j++;
        }
        // edge case : ho sakta hai ek baar zeroes ko replace karne par saare ones aa rahe ho last index tak
        ans = max(ans, j - i);
        return ans;
    }
};

// Problem : 3Sum Closest LeetCode
class Solution
{
public:
    // TC => O(N^2)+O(NlogN)  SC => O(1)
    // Approach ye hai ki agar mein sort kardeta hun aur phir two pointers leta hun current index ke liye jo ki mujhe help karenge ki un 2 pointers
    // par jo value hai aur jo value current index par hai unka sum agar less hai target se toh left pointer ko aage badhao taaki sum target ke paas
    // paunche and agar sum zyada hai target se toho right pointer ko kum kardo taaki sum target ke pass paunch jaye and agar target aur sum equal
    // hai toh target ko hi return kardo.
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                // Hum ye dekhenge ki kya temporary sum aur target ka difference less hai current sum and target ke difference se agar haan toh hum
                // current sum ko temporary sum assign kardenge taaki hume woh triplet mile jiske sum ki value target ke closest hai
                if (abs(temp - target) < abs(sum - target))
                    sum = temp;
                if (temp < target)
                    left++;
                else if (temp > target)
                    right--;
                else
                    return target;
            }
        }
        return sum;
    }
};

// Problem : 3Sum LeetCode

// Problem : 4Sum Leetcode
class Solution
{
public:
    // TC => O(N^3)   SC => O(1)
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // Two pointers ki approach hi use karenge
        // Two for loops chalayenge and unke andar two pointers ka concept use karenge
        // Outer less than n-3 times isliye chalega because hume 4 elements chahiye hai har baar and is loop ki help se first number ko fix karenge
        for (int i = 0; i < n - 3; i++)
        {
            // Simply duplicates ko avoid karne ke liye
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            // inner loop mein hum second number ko fixed karke two pointer approach ko lagane ki try karenge
            for (int j = i + 1; j < n - 2; j++)
            {
                // duplicates ko avoid karne ke liye
                if (j > i + 1 and nums[j] == nums[j - 1])
                    continue;
                // two pointers ka use karenge
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    // all 4 pointers ki value ko add karke current sum ko nikal lenge
                    long long cursum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    // agar current sum target ke equal hai toh usse apne final answer mein addd karlo
                    if (cursum == target)
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // agar current sum hamare target se less hai toh left pointer ko aage move karo
                    if (cursum < target)
                    {
                        left++;
                        // duplicates ko avoid karne ke liye hum left pointer tab tak increase karenge jab tak uski value and uske previous element
                        // ki value same hogi
                        while (left < right and nums[left] == nums[left - 1])
                            left++;
                    }
                    // agar current sum hamare target se greater hai toh right pointer ko piche move karo
                    else
                    {
                        right--;
                        // duplicates ko avoid karne ke liye hum right pointer tab tak decrease karenge jab uski value and uske next element ki
                        //  value same hogi
                        while (left < right and nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return ans;
    }
};