// Problem : Square root of a number GFG
class Solution
{
public:
    // TC => O(logN)    SC => O(1)
    long long int Sqrt(long long int x)
    {
        // agar x=1 hai toh uska sqrt bhi 1 hi hoga
        if (x == 1)
        {
            return 1;
        }
        // kisi bhi number x ka sqrt 0 to x ki range mein hi aayega
        long long low = 0;
        long long high = x;
        // answer ko double lene ka reason yehi hai ki ho agar kahin par ceil value kahi ho
        // toh answer ko ceil mein convert karsake according to first decimal value after point
        double ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if ((mid * mid) == x)
            {
                return mid;
            }
            else if ((mid * mid) < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // factor ko 1 isliye liye taaki decimal points ko increase kar sake like 0.1,0.01,...
        double factor = 1;
        // precision ka matlab yehi hai ki kitne decimal points tak aap answer chahte hai
        // hum yahan 2 decimal places tak hi consider kar rahe hai
        int precision = 2;
        for (int i = 0; i < precision; i++)
        {
            // har baar next decimal place ki value nikalne ke liye hume factor ko 10 se divide
            // karna padega
            factor = factor / 10;
            // simply ye sqrt check karne ke liye call kar rahe hai ki j ki kya value hogi
            // jiske liye j ka square less hoga x se
            for (double j = ans; j * j < x; j += factor)
            {
                ans = j;
            }
        }
        // answer ko long long mein typecast kar rahe hai as per the question
        return (long long)ans;
    }
};

// Problem : Nth root of a number GFG
class Solution
{
public:
    // 	Approach-1 : Brute force
    // TC => O(m*n)     SC => O(1)
    int NthRoot(int n, int m)
    {
        // agar 1 ka Nth root nikalna hai toh woh hamesha 1 hi rahega
        if (m == 1)
        {
            return 1;
        }
        // agar kisi number ka 1st rool nikalna hai toh woh wahi number rahega
        if (n == 1)
        {
            return m;
        }
        for (int i = 1; i < m; i++)
        {
            int prod = 1;
            for (int j = 0; j < n; j++)
            {
                prod *= i;
            }
            if (prod == m)
            {
                return i;
            }
            if (prod > m)
            {
                break;
            }
        }
        return -1;
    }

    // Approach-2 : Using Binary search
    // TC => O(nlogm)   SC => O(1)
    int helper(int mid, int n, int m)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;
            if (ans > m)
            {
                return 2;
            }
        }
        if (ans == m)
        {
            return 1;
        }
        return 0;
    }
    int NthRoot(int n, int m)
    {
        int low = 1;
        int high = m;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int ans = helper(mid, n, m);
            if (ans == 1)
            {
                return mid;
            }
            else if (ans == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

// Problem : Number and the Digit Sum GFG
class Solution
{
public:
    // TC => O(logN)    SC => O(1)
    long long int numberCount(long long int N, long long int K)
    {
        // Hum ek range bana lenge 1 to N tak ki
        int low = 1;
        int high = N;
        int ans = 0;
        while (low <= high)
        {
            // ek number ko as mid find karenge
            int mid = low + (high - low) / 2;
            int num = mid;
            int sum = 0;
            // number ke digits ka sum nikal lenge
            while (num > 0)
            {
                sum += num % 10;
                num = num / 10;
            }
            // agar sum-number >=k hai toh iska matlab is number se aage ke jitne bhi
            // numbers hai sabke liye ye condition true hogi because har baar 1 se hi
            // number increase hoga and sum bhi 1 se hi increase hoga toh difference
            // constant hojaayega toh hum range mein left ki taraf move karne ki try
            // karenge
            if (abs(sum - mid) >= K)
            {
                // current number se given number tak ke saare numbers hamaare answers
                // honge toh count N-number+1 hojaayega
                ans = N - mid + 1;
                high = mid - 1;
            }
            else
            {
                // agar current number condition ko follow nahi kar raha hai toh range
                // mein right ki taraf move karenge
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Problem : Smallest Factorial Number GFG
class Solution
{
public:
    // TC => (log(base2)N * log(base5)N)     SC => O(1)
    int findNum(int n)
    {
        // range ko sochne ke liye observation zaroori hai agar dhyaan de toh 5 ke har multiple
        // par jaane par ek zero increase ho jaata hai toh aapko jitne trailing zeroes chahiye
        // utna hi multiple hona chahiye 5 ka. For example :
        // 9! tak mein 5 ka sirf ek mutiple hai jo ki 5 khud hi hai
        // 10! par 5 ke 2 multiples (5,10) aagaye toh 2 trailing zeroes hojaayenge
        // 15! par 5 ke 3 multiples (5,10,15) aagaye toh 3 trailing zeroes hojaayenge
        // and issi tarah jese jese 5 ke multiples increase honge wese wese trailing zeroes
        // increase hojaayenge. Toh isliye n ki koyi bhi value di ho uske range hamesha
        // 1 to 5*n tak hi jaayegi
        int low = 1;
        int high = 5 * n;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            int power = 5;
            // simply trailing zeros ko nikalne ki try kar rahe hai by dividing number by 5
            // because isse hume ye pata chal jaayega ki 5 ke kitne multiples present hai
            // number mein
            while ((mid / power) != 0)
            {
                count += mid / power;
                power *= 5;
            }
            // agar number of trailing zeroes zyada hai toh hum apni range ko kum karne ki
            // koshish karenge warna range ko low se increase karenge
            if (count >= n)
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
};

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

// Binary search on matrices
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

// Problem : Median in a row-wise sorted Matrix
class Solution
{
public:
    // Approach-1 : Ek 'ans' vector le lo and usme saare elements ko push kardo and uss vector ko
    // sort karlo and return kardo ans[(R*C)/2] par jo bhi element hai.
    // TC => O(R*C*log(R*C))     SC => O(R*C)

    // Approach-2 : using binary search
    // First column ko traverse karke minimum find karlo and last column ko traverse maximum
    // find karlo, phir mid element ko find karo and coun tkaro kitne elements less than equal
    // to mid hai
    // TC => O(R*logC)     SC => O(1)
    int countSmallerThanMid(vector<int> &row, int mid)
    {
        int low = 0;
        int high = row.size() - 1;
        // current median ke liye find karenge ki kitne number of elements less hai current
        // median se
        while (low <= high)
        {
            int md = low + (high - low) / 2;
            if (row[md] <= mid)
            {
                low = md + 1;
            }
            else
            {
                high = md - 1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = 1;
        int high = 1e9;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;
            // har row ko pick karenge and find karenge ki current se median se kitne elements
            // less hai
            for (int i = 0; i < R; i++)
            {
                count += countSmallerThanMid(matrix[i], mid);
            }
            // agar number of elements less than equal to current median jo hai woh half elements
            // se less hai toh right mein move karenge
            if (count <= (R * C) / 2)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

// Binary Search on answers
// Problem : Allocate minimum number of pages GFG
class Solution
{
    // TC => O(Nlog(sum(A[])-max(A[])))     SC = O(1)
public:
    bool helper(int A[], int N, int M, int mid)
    {
        int count = 0;
        // initially 1 student toh hoga hi
        int persons = 1;
        for (int i = 0; i < N; i++)
        {
            // number of pages ko count karte rahenge jo ki ek student ko allocate kar sakte hai
            count += A[i];
            // agar number of pages maximum number of pages jo ki ek student allocate kar sakte
            // hai use zyada hojata hai toh next student ko allocate karna start karenge
            if (count > mid)
            {
                count = A[i];
                persons++;
            }
        }
        // agar number of students jinhe pages allocate karen hai less ya equal to hai total number
        // of students ke toh return true warna false
        return persons <= M;
    }
    int findPages(int A[], int N, int M)
    {
        // Agar number of books less hongi number of students se toh allocation possible nahi hoga
        if (N < M)
        {
            return -1;
        }
        int low = 0;
        int high = 0;
        // range maximum number of pages se total number of pages tak jaayegi
        for (int i = 0; i < N; i++)
        {
            low = max(low, A[i]);
            high += A[i];
        }
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // agar mid number of pages allocate kar paa rahe hai toh left ki taraf move karenge
            if (helper(A, N, M, mid))
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
};

// Problem : The Painter's Partition Problem-II GFG
class Solution
{
    // TC => O(Nlog(sum(A[])-max(A[])))     SC = O(1)
public:
    bool helper(int A[], int N, int k, long long mid)
    {
        long long count = 0;
        // initially 1 painter toh hoga hi
        int painters = 1;
        for (int i = 0; i < N; i++)
        {
            // time ko count karte rahenge jo ki ek painter ko lagega board ko paint karne mein
            count += A[i];
            // agar calculated time maximum time jo ki ek pianter le sakta hai
            // hai usse zyada hojata hai toh next painter paint karna start karega
            if (count > mid)
            {
                count = A[i];
                painters++;
            }
        }
        // agar number of painters less than equal to honge total number of painters se
        // toh return true warna false
        return painters <= k;
    }
    long long minTime(int A[], int N, int k)
    {
        long long low = 0;
        long long high = 0;
        for (int i = 0; i < N; i++)
        {
            low = max(low, (long long)A[i]);
            high += A[i];
        }
        long long ans = -1;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (helper(A, N, k, mid))
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
};

// Problem : Heaters Leetcode
class Solution
{
    // Time Complexity : O((N+M)log(M+N))
    // Space Complexity : O(1)
public:
    // Simply binary search on answers ka hi concept use hua hai.
    bool blackBox(vector<int> &houses, vector<int> &heaters, int n, int m, int radius)
    {
        // Yahan hum two pointer approach laga rahe hai
        int i = 0, j = 0;
        // hum houses waale vector ke through traverse karenge andye dekhenge ki current heater ki range jo hai usme kahin par current house aa raha hai agar haan toh next house ke liye check karenge warna next heater ko try karenge
        while (i < n)
        {
            // agar hamare paas heaters hi nahi bache toh iska matlab ye radius toh work nahi karega
            if (j == m)
            {
                return false;
            }
            // heater ki range nikal rahe hai
            int l = heaters[j] - radius;
            int r = heaters[j] + radius;
            // agar house current heater ki range mein nahi hai toh next heater par jaayenge
            if (houses[i] < l or houses[i] > r)
            {
                j++;
            }
            // agar current house current heater ki range mein hai toh next heater par jaayenge
            else
            {
                i++;
            }
        }
        return true;
    }

    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int m = heaters.size();
        int low = 0;
        // heaters and houses mein se jo bhi max index par hoga utni hi hamari range hogi
        int high = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // agar current radius saare heaters ko warm kar paa raha hai toh isse hum apna answer maan lenge and isse chota answer find out karne ki try karenge
            if (blackBox(houses, heaters, n, m, mid))
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
};

// Problem : WoodCutting Made Easy interviewbit (Flipkart ka problem hai ye)
class Solution
{
    // TC => O(Nlog(max))       SC => O(1)
    // Simply binary search on answers ka question hai ye
    long long int helper(vector<int> &trees, int wood, int TreeHeight)
    {
        int n = trees.size();
        int woodGot = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i] > TreeHeight)
            {
                woodGot += (trees[i] - Treeheight);
            }
        }
        return woodGot;
    }
    int woodCutter(vector<int> &trees, long long int wood)
    {
        int n = trees.size();
        int low = 0;
        int high = *max_element(trees.begin(), trees.end());
        long long int woodNeeded = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long int woodGot = helper(trees, wood, mid);
            if (woodGot >= wood)
            {
                woodNeeded = max(woodGot, woodNeeded);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return woodNeeded;
    }
};

// Problem : Kth element of two sorted arrays
class Solution
{
public:
    // Approach-1 : Using two pointers
    // TC => O(N+M)   SC => O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int idx = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                // pehle check karenge ki kitne elements track karliiye phir index ko badhayenge
                if (idx == k - 1)
                {
                    return arr1[i];
                }
                i++;
                idx++;
            }
            else
            {
                if (idx == k - 1)
                {
                    return arr2[j];
                }
                j++;
                idx++;
            }
        }
        if (idx < k)
        {
            while (i < n)
            {
                if (idx == k - 1)
                {
                    return arr1[i];
                }
                i++;
                idx++;
            }
            while (j < m)
            {
                if (idx == k - 1)
                {
                    return arr2[j];
                }
                j++;
                idx++;
            }
        }
        // agar dono array ke sizes ka sum less than k hai toh kth element nahi milega
        return -1;
    }

    // Approach-2 : Median of two sorted arrays ka hi concept use kar rahen hai bas hum dono arrays se
    // elements ko lekar uske last elements ka max return kar rahe hai
    // TC => O(log(min(n,m)))    SC => O(1)
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (m > n)
        {
            return kthelement(arr2, arr1, n, m, k);
        }
        // first array se 0 to (k-m)th tak ke elements lenge
        int low = max(0, k - m);
        // second array se total and k mein se jo minimum hoga utne elements hi lenge
        int high = min(k, n);
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }
        return 1;
    }
};