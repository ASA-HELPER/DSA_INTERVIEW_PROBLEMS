// Sorting Algorithms :
// Bubble Sort :
class Solution
{
public:
    // Bubble sort algorithm mein hum swapping karte rehte hai jab tak hamara array sort
    // nahi hoga and har baar unsorted array ka size chota hota jaayega
    // TC => O(N^2) because two for loops use ho rahe hai
    // SC => O(1)
    // Bubble sort stable algorithm hota hai.
    void bubbleSort(int arr[], int n)
    {
        // ye outer loop hamare unsorted array ki length bata raha hai
        for (int i = n - 1; i >= 0; i--)
        {
            // Ek boolean flag rakh lenge jo ki ye batayega ki swapping huyi ya nahi
            bool swapped = false;
            // ye current unsorted array mein greatest element ko swap karte karte last
            // position par leke jaayega
            for (int j = 0; j < i; j++)
            {
                // agar next element small hai current element se
                if (arr[j] > arr[j + 1])
                {
                    swapped = true;
                    swap(arr[j], arr[j + 1]);
                }
            }
            // agar ek baar bhi swapping nahi huyi hai toh break kardo array sort hogaya hai
            if (!swapped)
            {
                break;
            }
        }
    }
};

// Insertion Sort :
class Solution
{
public:
    // Insertion simply kehta hai aap ek ek karke har element ko uthao and usse uske saare
    // previous indexes par jo element hai unse compare karo and agar current element se greater
    // hai previous element toh elements ko shift karte raho right mein and jahan condition
    // fail hogayi loop se break kardo
    // TC => O(N^2)    SC => O(1)
    void insert(int nums[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            // current element ko key bana lo
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > key)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            // current element ko uski correct position par place kardo
            nums[j + 1] = key;
        }
    }
};

// Selection Sort :
class Solution
{
public:
    void selectionSort(int arr[], int n)
    {
        // TC => O(N^2)   SC => O(1)
        // Simply ek ek current index ko minimum element manege and phir uske aage ke elements
        // se usse compare karenge and agar koyi smaller element milgaya current minimum element
        // se toh minimum index ko change kardenge and pura array traverse karne ke baad current
        // index waale element ko swap kardo minimum index waale element se
        for (int i = 0; i < n; i++)
        {
            int minidx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minidx])
                {
                    minidx = j;
                }
            }
            swap(arr[minidx], arr[i]);
        }
    }
};

// Problem : Merge Sort
class Solution
{
    // TC => O(NlogN)   SC => O(N)
    // Merge sort stable algorithm hai because ye maintain karti hai relative order ko equal
    // elements ke array mein
public:
    void merge(int arr[], int l, int m, int r)
    {
        // ek temporary vector banayenge accroding to l and r ki kya range hai
        vector<int> temp(r - l + 1, 0);
        // temporary vector ke through traverse karne ke liye ek variable rakh lenge
        int i = 0;
        // dono arrays jinhe sort karke merge karna hai woh alag alag index se start honge
        // ek array l se start ho raha hoga and m tak jaayega and dusra array m+1 se start
        // ho raha hoga and r tak jaa raha hoga
        int n1 = l;
        int n2 = m + 1;
        // dono arrays ke elements ko compare karke temporary array mein sorted form mein
        // daal rahe hain
        while (n1 <= m && n2 <= r)
        {
            if (arr[n1] <= arr[n2])
            {
                temp[i++] = arr[n1];
                n1++;
            }
            else
            {
                temp[i++] = arr[n2];
                n2++;
            }
        }
        // agar first array mein kuch elements reh gaye hai toh unhe temp mein daalenge
        while (n1 <= m)
        {
            temp[i++] = arr[n1];
            n1++;
        }
        // agar second array mein kuch elements reh gaye hai toh unhe temp mein daalenge
        while (n2 <= r)
        {
            temp[i++] = arr[n2];
            n2++;
        }
        // ab original array ki l to r ki range mein jo elements hai unhe sorted temporary
        // array se original array mein daalenge
        for (int j = l; j <= r; j++)
        {
            arr[j] = temp[j - l];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // Simply hum given array ko divide karte rahenge jab tak l and r equal nahi ho jaate hai
        if (l == r)
        {
            return;
        }
        // har baar array ka mid find karo and array ko 2 parts mein divide kardo
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // jab array totally single elements mein divide hogaya hai toh ab unhe merge function
        // ki help se sort karke one by one merge karo
        merge(arr, l, m, r);
    }
};

// Problem : Quick Sort
class Solution
{
public:
    // TC => O(NlogN)    SC => O(logN)
    // QuickSort is an unstable algorithm because we do swapping of elements according to
    // pivot’s position (without considering their original positions).
    void quickSort(int arr[], int low, int high)
    {
        // jab tak low less hai high se tab tak har baar partition function ko call karke
        // pivot element ko find karke usse less elements ko left side and greater element
        // ko right side shift kardo and phir uske left and right side ke sub-arrays par bhi
        // same approach ko lagao
        if (low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        int pivot = low;
        int i = low;
        int j = high;

        while (i < j)
        {
            // jab tak starting elements array ke pivot element se less hai tab tak aage badhte raho
            while (arr[i] <= arr[pivot])
            {
                i++;
            }
            // jab tak endinng elements array ke pivot element se greater hai tab tak peeche jaate raho
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            // ab agar i<j hai toh swap kardo ith and jth element ko
            if (i < j)
            {
                swap(arr[j], arr[i]);
            }
        }
        // last mein swap kardo jth element ko pivot se
        swap(arr[j], arr[pivot]);
        return j;
    }
};

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