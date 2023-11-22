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

// Problem : Rows with max 1s GFG
class Solution
{
public:
    // TC => O(N+M) hogi because hum bas two pointers ko hi use karke matrix ko ek baar traverse kar rahe hai
    // SC => O(1) because hum koyi extra space use nahi kar rahe hai
    int rowWithMax1s(vector<vector<int>> Arr, int n, int m)
    {
        // simply hum yahan row number and column number ko as two pointers treat kar rahe hai
        // Hum first row and last column se traverse karna start karenge because har row sorted hai toh 1s rightmost hi honge hamesha
        int row = 0;
        int col = m - 1;
        int maxRowIndex = -1;
        // approach yehi hai ki hum bas ye check karenge ki agar current cell par 1 hai toh previous column par shift karenge
        // warna hum next row mein shift karenge jab tak row < n hai and columns >=0 hai
        while (row < n && col >= 0)
        {
            if (Arr[row][col] == 1)
            {
                maxRowIndex = row;
                col--;
            }
            else
            {
                row++;
            }
        }

        return maxRowIndex;
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
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // TC => O(N^2)  SC => O(1)
        vector<vector<int>> ans;
        // hum sabse pehle sort kardenge taaki duplicates ko avoid kar saken
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            // agar first element nahi hai and previous element current element ke equal hai toh continue taaki duplicates ko avoid kar sake
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // two pointers lenge taaki baaki two numbers ko select kar saken
            int j = i + 1;
            int k = N - 1;
            // jab tak j less than k rahega tabhi tak loop chalega because hum chahte hai ki triplets increasing order mein ho and duplicate na ho
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                // agar sum less than 0 hai toh hume sum ko increase karna hoga toh iske liye hum kya karenge ki j pointer ko increase karenge
                // because k pointer par jo value hai woh toh already greater hogi us value se jo j pointer par hai
                if (sum < 0)
                {
                    j++;
                }
                // agar sum greater than 0 hai toh hume sum ko decrease karna hoga toh iske liye hum kya karenge ki k pointer ko decrease karenge
                // because j pointer par jo value hai woh toh already less hogi us value se jo k pointer par hai
                else if (sum > 0)
                {
                    k--;
                }
                // agar sum equal to 0 hogaya toh
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // ab jab tak current j position par jo value hai woh previous value ke same hai tab tak aage bandhenge array mein taaki
                    // duplicates ko avoid kar saken
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    // ab jab tak current k position par jo value hai woh next value ke same hai tab tak piche jaayenge array mein taaki duplicates
                    // ko avoid kar saken
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};

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

// Problem : Remove and Reverse GFG
class Solution
{
    // Agar aap even number of times reverse karoge toh koyi pharak nahi padega but agar aap
    // odd number of times reverse karoge toh aapko ek hi baar last mein reverse karne par
    // bhi answer miljaayega
    // Baar baar reverse karne se better hai mein ek flag rakh leta hun jo ki mujhe ye batadega
    // ki mujhe kahan se remove karna hai and jab bhi hume repeating character milega toh flag
    // ko change kardenge and iske liye hum two pointers ka use karenge
    // TC => O(N)   SC => O(k) where k<=26 because map mein hamesha 26 hi characters hote hai
public:
    string removeReverse(string S)
    {
        int n = S.size();
        // map mein saar characters ki frequency nikal lenge
        unordered_map<char, int> mp;
        for (int k = 0; k < n; k++)
        {
            mp[S[k]]++;
        }
        // two pointers ka use karlenge ek start par and ek end par
        int start = 0;
        int end = n - 1;
        // initially start se shuru karenge toh direction ko 0 rakhenge
        int dir = 0;
        while (start < end)
        {
            // agar direction 0 hai toh
            if (dir == 0)
            {
                // agar start par jo character hai uski frequency 1 se zyada nahi hai toh
                // simply start ko aage badha do
                if (mp[S[start]] == 1)
                {
                    start++;
                }
                // Warna simply start par jo character hai uski frequency ko decrease karo
                // and us character ko # se replace kardo taaki last mein hum jab final string
                // create karenge jo isse ignore kar saken and start pointer ko aage badha kar
                // direction ko reverse kardo
                else
                {
                    mp[S[start]]--;
                    S[start] = '#';
                    start++;
                    dir = 1;
                }
            }
            else
            {
                // agar end par jo character hai uski frequency 1 se zyada nahi hai toh
                // simply end ko 1 peeche le jaao
                if (mp[S[end]] == 1)
                {
                    end--;
                }
                // Warna simply end par jo character hai uski frequency ko decrease karo
                // and us character ko # se replace kardo taaki last mein hum jab final string
                // create karenge jo isse ignore kar saken and end pointer ko 1 peeche le jao
                // and direction ko reverse kardo
                else
                {
                    mp[S[end]]--;
                    S[end] = '#';
                    end--;
                    dir = 0;
                }
            }
        }
        string ans = "";
        // final string ko create karenge jahan # show kar raha hai ki current character ko
        // remove kardiya gaya hai
        for (int i = 0; i < n; i++)
        {
            if (S[i] != '#')
            {
                ans += S[i];
            }
        }
        // agar dir=1 hai toh iska matlab hai ki aap last se traverse kar rahe the matlab
        // odd number of times reverse kiya string ko toh hume final answer ko bhi reverse
        // karna padega
        if (dir == 1)
        {
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};

// Problem : Conntainer with most water LeetCode
class Solution
{
public:
    // TC => O(N) because two pointers ki help se heights waale vector ko ek hi baar traverse kar rahe hai
    // SC => O(1) because variables ke alawa hum koyi aur extra space use nahi kar rahe hai
    int maxArea(vector<int> &height)
    {
        // Simply hum bas itna sochenge ki mujhe har baar two heights chahiye jinke beech mein water hoga toh koshish yehi rahegi ki
        // two maximum heights miljaayen jin mein se kisi ek ki height tak hi water bharega dono heights ke beech mein
        int n = height.size();
        // initially hum maan rahe hai ki leftHeight and rightHeight -1 hai
        int leftHeight = -1;
        int rightHeight = -1;
        int i = 0;
        int j = n - 1;
        int mostWater = 0;
        // Two pointers ki help lekar mein left and right side se array ke maximum heights ko find karne ki try karunga
        while (i < j)
        {
            // dono taraf se heights ko rakhlo apne paas
            leftHeight = height[i];
            rightHeight = height[j];
            // ab container mein utna hi water hoga jitna container ka area hoga dono ends ki minimum height tak. Toh hum kya karenge ki dono
            // heights mein se minimum ko multiply kardenge un dono heights ke beech ke distance se. Clarity ke liye ye keh sakte hai ki hum
            // rectangle ka area nikal rahe hai jahan par difference between indexes of heights jo hai woh breadth of rectangle ko represent
            // kar raha hai.
            int currentWater = min(leftHeight, rightHeight) * (j - i);
            // ab current container mein jo bhi water hai usse hum most water ke variable ke saath compare karenge taaki jis container mein
            // maximum water hoga uska area apne paas rakh sake har baar compare karne ke liye
            mostWater = max(mostWater, currentWater);
            // ab humne jin 2 heights ko consider kiya tha unme se jo minimum hogi usko find karenge because hum har baar maximum heights chahiye
            // hai toh hum us pointer ko hi shift karenge jo ki 2 heights mein se minimum height ko point kar raha hoga
            int minHeight = min(leftHeight, rightHeight);
            // agar minimum height left waale pointer ki hai toh hum left pointer ko increment karenge
            if (minHeight == leftHeight)
            {
                i++;
            }
            // agar minimum height right waale pointer ki hai toh hum right pointer ko decrement karenge
            else
            {
                j--;
            }
        }
        return mostWater;
    }
};

// Problem : Median of the subarrays GFG
class Solution
{
public:
    //   TC => O(N)     SC => O(N)
    long solve(vector<int> &A, int N, int M)
    {
        // create a map to store the difference between x and y.
        // cur=0(store the current difference)
        // total=0(stores to number of subarrays for the current index)
        // ans=0{sum of "total" for each index}.
        unordered_map<int, int> mp;
        int cur = 0;
        long long int tot = 0, ans = 0;
        mp[cur] = 1;
        for (int i = 0; i < N; i++)
        {
            int x;
            if (A[i] >= M)
            {
                x = 1;
            }
            else
            {
                x = -1;
            }
            if (x == -1)
            {
                tot -= mp[cur - 1];
            }
            else
            {
                tot += mp[cur];
            }
            cur += x;
            ans += tot;
            mp[cur] = mp[cur] + 1;
        }
        return ans;
    }
    long long countSubarray(int N, vector<int> A, int M)
    {
        // Hum kya karenge ki jo bhi median diya hoga usse less waale numbers ko -1 mark kardenge
        // aur jo median se greater hai unhe 1 se mark kardenge and phir un subarrays ko nikal
        // lunga jinka sum greater hai 0 se
        // ans = number of subarrays with median M - number of subarrays having median (M+1)

        long long int lessthanM = solve(A, N, M);
        long long int greaterthanM = solve(A, N, M + 1);
        return (lessthanM - greaterthanM);
    }
};