// Problem : Sorting Elements of an Array by Frequency GFG
class Solution
{
    // TC => O(NlogN)      SC => O(N)
public:
    // ek comparator banayenge jo ki sort karega elements ko unke frequency ke according
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    vector<int> sortByFreq(int arr[], int n)
    {
        // sabhi elements ki frequency ko count karenge using map
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        vector<pair<int, int>> vec;
        // map se elements aur unki frequency ko as a pair insert karenge vector mein taaki
        // sorting kar sake using comparator
        for (auto it : mp)
        {
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(), vec.end(), cmp);
        vector<int> ans;
        // sorted vector mein se ek ek karke elements and unki frequency ko nikal kar final answer
        // vector mein push kardenge
        for (auto it : vec)
        {
            int count = it.first;
            int num = it.second;
            while (count--)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

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

// Problem : Number of pairs GFG
class Solution
{
    // TC => O(N*logN+M*logM)    SC => O(1)
public:
    // Question mein bohot saare cases ko handle karna padega
    // Ye getIndex waala function basically binary search ki help se current element se just
    // greater waale element ka index return karega
    int getIndex(int y[], int n, int key)
    {
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (key < y[mid])
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    long long countPairs(int x[], int y[], int m, int n)
    {
        // Dono arrays ko sort karna padega
        sort(x, x + m);
        sort(y, y + n);
        // Hume second waale array mein zeroes, ones, two,three and four ko count karna padega
        int zeroes = 0, ones = 0, two = 0, three = 0, four = 0;
        for (int i = 0; i < n; i++)
        {
            if (y[i] == 0)
            {
                zeroes++;
            }
            else if (y[i] == 1)
            {
                ones++;
            }
            else if (y[i] == 2)
            {
                two++;
            }
            else if (y[i] == 3)
            {
                three++;
            }
            else if (y[i] == 4)
            {
                four++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            // Case-1 : Agar current element 0 hai toh kuch nahi hoga because 0 ki power
            // kuch bhi ho woh hamesha zero hi rahega toh pow(x,y)>pow(y,x) hone ka koyi
            // chance hi nahi hai
            if (x[i] == 0)
            {
                continue;
            }
            // Case-2 : Agar current element 1 hai toh hamare second array mein jitne bhi
            // zeroes honge un sabke saath 1 pair bana paayega
            else if (x[i] == 1)
            {
                ans += zeroes;
            }
            // Case-3 : Agar current element 2 hoga toh hume ye pata karna hoga ki 2 se greater
            // kitne element hai Binary search ki help se just greater waale element ka index
            // find karke number of elements greater than 2 find karlenge
            else if (x[i] == 2)
            {
                int index = getIndex(y, n, x[i]);
                if (index != -1)
                {
                    ans += n - index;
                }
                // 2 ke liye 3 and 4 aese numbers hai jinme ye condition pow(x,y) > pow(y,x)
                // true nahi hogi toh 3 and 4 ke count ko decrease karna hoga and yahan par
                // hume zeroes and ones ke count ko bhi add karna padega because 2 ki power
                // zero hamesha zyada hota hai zero ki power 2 se and same for 1 also.
                ans -= three;
                ans -= four;
                ans += zeroes;
                ans += ones;
            }
            else
            {
                // Case-3 : agar 0,1,2 ke alawa koyi bhi number hai toh just greater greater
                // element ka index find karlo and usse number of elements greater than current
                // element find karlo
                int index = getIndex(y, n, x[i]);
                if (index != -1)
                {
                    ans += n - index;
                }
                // yahan par hume zeroes and ones ke count ko bhi add karna padega because kisi
                // bhi number ki power zero hamesha zyada hota hai zero ki power of that number
                // se and same for 1 also.
                ans += zeroes;
                ans += ones;
                // exception agar current number 3 hai toh phir hume number of twos ko bhi add
                // karna padega because pow(3,2) > pow(2,3) always
                if (x[i] == 3)
                {
                    ans += two;
                }
            }
        }
        return ans;
    }
};