// Problem : Binary Array Sorting GFG
void binSort(int A[], int N)
{
    int i = 0;
    int j = N - 1;
    while (i < j)
    {
        // agar first position par 1 hai and last position par 0 hai toh swap kardo
        if (A[i] == 1 && A[j] == 0)
        {
            A[i] = 0;
            A[j] = 1;
            i++;
            j--;
        }
        // agar starting pointer par pehle se hi 0 hai toh aage badho
        if (A[i] == 0)
        {
            i++;
        }
        // agar ending pointer par pehle se hi 1 hai toh aage badho
        if (A[j] == 1)
        {
            j--;
        }
    }
}

// Problem : Greater on right side GFG
class Solution
{
public:
    void nextGreatest(int arr[], int n)
    {
        int nextGreater = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = nextGreater;
            nextGreater = max(temp, nextGreater);
        }
    }
};

// Problem : Remove duplicate elements from sorted Array in O(1) space GFG
class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (a[j] != a[i])
            {
                i++;
                a[i] = a[j];
            }
        }
        return i + 1;
    }
};

// Problem : Two Repeated Elements GFG
class Solution
{
public:
    // TC => O(N)    SC => O(1)
    // Dry run : arr = [1,2,2,1]
    // arr[abs(arr[0])] = arr[1] = 2 already positive toh negative kardenge => arr[1] = -2
    // arr[abs(arr[1])] = arr[2] = 2 already positive toh negative kardenge => arr[1] = -2
    // arr[abs(arr[2])] = arr[2] = -2 already negative hai toh iska matlab ye duplicate hai
    // arr[abs(arr[3])] = arr[1] = -2 already negative hai toh iska matlab ye duplicate hai
    // ans => {2,1}
    vector<int> twoRepeated(int arr[], int N)
    {
        vector<int> ans;
        for (int i = 0; i < N + 2; i++)
        {
            // Hum yahan kya kar rahe hai ki har number ko negative bana rahe hai and agar
            // same number dubara aayega toh woh already hi negative hoga and isse hume
            // pata chal jaayega ki number repeat hogaya hai
            if (arr[abs(arr[i])] < 0)
            {
                ans.push_back(abs(arr[i]));
            }
            else
            {
                // first time number aaya hai toh usse negative karke array mein rakh denge
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }
        }
        return ans;
    }
};

// Problem : Union of two sorted arrays GFG
class Solution
{
    // Brute Force : map ya set ka use karke kar sakte hai but unordered_map ya unordered_set ka use nahi kar sakte because usme array
    // sorted nahi rahega. TC => O((n+m)log(n+m)) , SC => O(n+m)
    // Timc Complexity : O(n+m)
    // Space Complexity : O(1) agar resultant array ke size ko consider naa karen toh
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> res;
        int i = 0;
        int j = 0;
        // two pointers ka istemal karke dono arrays mein forward move karenge
        while (i < n && j < m)
        {
            // agar first array ka element smaller hai toh usse push karenge resultant array mein tab jab woh resultant array ke last
            // element ke equal na ho and same yehi condition tab bhi dekhenge jab first array ka element second array ke element se
            // greater hoga toh
            if (arr1[i] <= arr2[j])
            {
                if (res.size() == 0 or res.back() != arr1[i])
                {
                    res.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if (res.size() == 0 or res.back() != arr2[j])
                {
                    res.push_back(arr2[j]);
                }
                j++;
            }
        }
        // agar first array mein koyi element reh gaya ho toh usse condition check karke add karlenge
        while (i < n)
        {
            if (res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        // agar first array mein koyi element reh gaya ho toh usse condition check karke add karlenge
        while (j < m)
        {
            if (res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
        return res;
    }
};

// Problem : Check if array is sorted without sorting in O(N) time and O(1) space GFG
class Solution
{
public:
    bool arraySortedOrNot(int arr[], int n)
    {
        if (n == 2 && (arr[0] > arr[1]))
        {
            return false;
        }
        for (int i = 1; i < n - 1; i++)
        {
            if ((arr[i - 1] > arr[i]) or (arr[i] > arr[i + 1]))
            {
                return false;
            }
        }
        return true;
    }
};

// Problem : Quick Left Rotation GFG
class Solution
{
    // Time Complexity : O(N)
    // Space Complexity : O(1)
public:
    void rotate(int arr[], int i, int j)
    {
        while (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    void leftRotate(int arr[], int k, int n)
    {
        // k ko n se mod isliye kiya taaki agar k ki value n se greater hai toh usse within n kar sake
        k = k % n;
        // observation ka khel hai saara
        // case-1 : 0 se (k-1)th tak elements ko reverse kardo
        rotate(arr, 0, k - 1);
        // case-2 : kth se (k-1)th tak elements ko reverse kardo
        rotate(arr, k, n - 1);
        // case-3 : 0 se (n-1)th tak ke elements ko reverse kardo
        rotate(arr, 0, n - 1);
    }
};

// Problem : Smallest positive missing number
class Solution
{
    // TC => O(N)       SC => O(1)
public:
    int missingNumber(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            // Simply hum kya kar rahe hai ki jo bhi positive number greater than 0 hai
            // usse swapping karke uski correct index par rakh rahe hai and jese hi woh
            // correct position par paunch jaaye toh while loop se bahar aajayenge
            // while loop isliye taaki jis number ko current number se swap kara hai woh
            // bhi apni correct position par paunch jaaye
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }
        // second traversal mein bas itna dekh lenge ki konsa number aesa hai jo ki apni correct position par nahi hai
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != (i + 1))
            {
                return i + 1;
            }
        }
        // agar sabhi numbers apni correct position par hai toh iska matlab n+1th number hi missing hai vector mein
        return n + 1;
    }
};

// Problem : Longest Sub-Array with sum K
class Solution
{
public:
    int lenOfLongSubarr(int a[], int n, int k)
    {
        // Complete the function
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i:
            sum += a[i];

            // if the sum = k, update the maxLen:
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e. x-k:
            int rem = sum - k;

            // Calculate the length and update maxLen:
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // Finally, update the map checking the conditions:
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};

// Problem : Find all pairs with a given sum GFG
class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Approach-2 : Using hashmap : Isme simply ek array ke saare numbers ko map mein rakh denge and phir dusre array ke saare elements
        // ko given sum se subtract karke dekhenge one by one ki kya difference jo mil raha hai woh map mein exist karta hai ya nahi.
        // TC => O(N+M)  SC => O(N) because we are unordered_map
        vector<pair<int, int>> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[A[i]]++;
        }
        for (int i = 0; i < M; i++)
        {
            if (mp[X - B[i]])
            {
                res.push_back({X - B[i], B[i]});
            }
        }
        sort(res.begin(), res.end());
        return res;

        // Approach-3 : Using two pointers : Is solution ko hum tab use kar sakte hai jab hume ye check karna ho ki kinhi two elements
        // ka sum X ke equal hai toh return true warna return false ya phir koyi single pair ko find karna ho toh
        // TC => O(NlogN)   SC=>O(1) if we do not consider the array we are making by combining the given two arrays
        // vector<int>arr;
        // for(int i=0;i<max(N,M);i++)
        // {
        //     if(i<N)
        //     {
        //         arr.push_back(A[i]);
        //     }
        //     if(i<M)
        //     {
        //         arr.push_back(B[i]);
        //     }
        // }
        // sort(arr.begin(), arr.end());
        // int left = 0, right = arr.size() - 1;
        // while (left < right)
        // {
        //     int sum = arr[left] + arr[right];
        //     if (sum == X) {
        //         return {arr[left],arr[right]};
        //         // return true;
        //     }
        //     else if (sum < X)
        //         left++;
        //     else
        //         right--;
        // }
        // agar ek bhi pair naa mile toh
        // return false or empty pair;
    }
};

// Problem : Count triplets with sum smaller than X GFG
class Solution
{
public:
    // Approach-1 : 3 for loops ka use karke check karlenge sum ko ki less than
    // given sum hai toh count increment kardenge by 1
    // TC => O(N^3)  SC => O(1)
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Approach-2 : Simply array ko sort kardenge and phir two pointers ka use karenge
        // TC => O(N^2)  SC => O(1)
        sort(arr, arr + n);
        long long count = 0;
        // 0 to n-2 tak jaayenge because hume last mein 2 numbers toh chahiye hi isliye
        // third last element tak hi jaa sakte hai
        for (int k = 0; k < n - 2; k++)
        {
            int i = k + 1;
            int j = n - 1;
            // two pointer approach lagayenge
            while (i < j)
            {
                long long s = (long long)(arr[i] + arr[j] + arr[k]);
                // agar current sum less than hoga given sum se toh hum count karlenge ki
                // kitne numbers aese hai between i and j jo ki triplet bana rahe hai
                if (s < sum)
                {
                    count += (j - i);
                    i++;
                }
                // agar sum greater hoga toh jth pointer ko decrement karenge
                else
                {
                    j--;
                }
            }
        }
        return count;
    }
};

// Problem : kadane's Algorithm or Maximum subarray Leetcode
class Solution
{
public:
    // Brute Force Approach : Simply two loops ka use karenge and har subarray ke liye uske sum ko maximum sum se compare karte rahenge.
    // TC => O(N^2)  SC=> O(1)
    // Optimal Approach : Using kadane's algorithm : Isme hum sum mein elements ki value ko add karte rahenge and saath hi saath apne maxSum
    // ko update karte rahenge and agar kabhi sum less than 0 hojata hai toh sum ko 0 kardenge taaki hum hamesha maximum sum ko consider kare.
    // TC => O(N)  SC => O(1)
    // Note : if all numbers are negative then it does not mean that maximum sum is 0 but its the smallest element in the array.
    long long maxSubarraySum(int arr[], int n)
    {
        long long sum = 0;
        long long maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};

// Problem : Stock Buy and sell GFG
void stockBuySell(int price[], int n)
{
    // TC => O(N)    SC => O(1)
    // Simply hum increasing subarrays ke starting and ending points ko find kar rahe hai
    int profit = 0;
    int buy = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // agar current position par value less hai next value se and abhi tak buy nahi kiya hai toh buy karlo and profit ko 1 kardo
        if (price[i] < price[i + 1] && buy == 0)
        {
            cout << "(" << i << " ";
            buy = 1;
            profit = 1;
        }
        // agar current position ki value greater hogayi hai next vaale se toh iska matlab increasing subarray khatam hogaya hai toh hum
        // sell price ko print karke buy ko 0 kardenge taaki dubara se buy kar paayen stock ko
        else if (price[i] > price[i + 1] && buy == 1)
        {
            cout << i << ")"
                 << " ";
            buy = 0;
        }
    }
    // agar koyi bhi stock khareed hi nahi paaye toh profit hoga nahi
    if (profit == 0)
    {
        cout << "No Profit"
             << "\n";
    }
    // agar stock khareeda hai and last index par sell kiya hai toh last cell ki value ko print karna padega
    else if (buy == 1)
    {
        cout << n - 1 << ")"
             << "\n";
    }
    // har test case ke baad next line mein jaane ke liye
    else
    {
        cout << "\n";
    }
}

// Problem : Majority element leetcode
class Solution
{
public:
    // Brute force Approach : two loops ka use karlo and outer loop mein se ek element ko lekar usse inner loop ki help se ye count karlo ki
    // ye element kitni baar aa raha hai and uske count ko check karlo ki kya is element ka count > n/2 hai.
    // TC => O(N^2)  SC => O(1)

    // Second Approach : Hum array ko sort kardete hai and phir two pointers ki help se har element ka count karte rahenge and jis element
    // ki frequency greater than n/2 hogi usse return kardenge.
    // TC => O(NlogN)  SC => O(1)

    // Better Approach : hashmap ka use karke store karlo sabhi elements ki frequency ko and and phir ek aur loop lagakar ye check karlo ki
    // konse element ki frequency > n/2 hai.
    // TC => O(N)   SC => O(N)

    // Optimal Approach : Moore's Voting algorithm : Ye algorithm ye kehta hai ki jesse jese hum array mein traverse kar rahe hai toh hum ye
    // dekhte jaayenge ki jo element current humne ek variable mein store kiya hai kya next element bhi wahi hai ya nahi. Agar next element
    // bhi same hai toh count variable ko increase karenge warna count variable ko decrease karenge and agar count zero ho jata hai toh hum
    // new element ko apne paas rakh lenge jiske liye count 1 hoga. And ek baar whole array ko traverse karne ke baad jo element hamare
    // variable mein reh jaayega uski frequency ko array ke through dubara traverse karke nikal lenge and agar iske frequency greater than
    // n/2 huyi toh yehi hamara answer hoga.
    // TC => O(N)  SC => O(1)

    int majorityElement(int a[], int n)
    {
        int count = 0;
        int element = -1;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                element = a[i];
                count = 1;
            }
            else if (element == a[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (element == a[i])
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            return element;
        }
        return -1;
    }
};

// Problem : Majority Element II LeetCode
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // TC => O(N)   SC => O(1)
        // Optimised Approach : Extended Moore's Voting algorithm ka use karenge. Sabse pehle iss question mein ye baat clear honi chahiye ki array
        // mein sirf 2 hi element honge jo ki greater than n/3 times aayenge and isi cheez ka fayda utha kar hum Moore's algorithm ko extend karenge
        int n = nums.size();
        // Hum 4 variables le lenge jinki help se counter and element ko track karenge. 4 variables isiliye taaki dono numbers and unke count ko
        // track kar sake
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;
        // Simply Moore's voting algorithm ka cancellation logic use karenge ki agar count 0 hai toh naya element aajayega and uska count 1 hojayega
        // warna hum ye check karlenge ki current number equal toh nahi hai kahin jin numbers ko hum track kar rahe hai. Agar haan toh us particular
        // tracked number ke counter ko increase kardenge warna agar dono tracked numbers ke equal nahi hai toh simply decrement kardenge counters ko
        for (int i = 0; i < n; i++)
        {
            // Ek slight modification jo ki karni padegi woh ye hai ki agar mera koyi bhi counter 0 hota hai and dusre element ka counter 0 nahi hai
            // lekin woh element jab aa raha hai traverse karte waqt toh first if condition check hogi toh hume yehi check lagana hai ki current
            // element dusre tracked element ke equal naa ho. Is check ko understand karne ke liye is test case par dry run karlo : [1,2,2,3,2,1]
            if (cnt1 == 0 && ele2 != nums[i])
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if (cnt2 == 0 && ele1 != nums[i])
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if (ele1 == nums[i])
            {
                cnt1++;
            }
            else if (ele2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        // ab hum dubara array ko traverse karenge taaki ye confirm kar paayen ki algorithm ki help se jo element's mile hai woh n/3 times se greater
        // hai ya nahi array mein
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
            {
                cnt1++;
            }
            if (nums[i] == ele2)
            {
                cnt2++;
            }
        }
        // edge case : agar saare elements equal honge toh toh dono elements equal hi honge toh us case mein hume return karna hoga single element ko
        if (ele1 == ele2)
        {
            return {ele1};
        }
        int checker = (int)(n / 3) + 1;
        // agar element greater than n/3 times hai toh usse apne array mein rakh lo
        if (cnt1 >= checker)
        {
            res.push_back(ele1);
        }
        if (cnt2 >= checker)
        {
            res.push_back(ele2);
        }
        // sorting karne mein yahan constant time hi lagega because sirf 2 hi elements hai toh N = 2 hoga.
        // TC => O(NlogN) => O(2log2)  => O(2)
        sort(res.begin(), res.end());
        return res;
    }
};

// Problem : Sort an array 0's , 1's and 2's  GFG
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // Dutch national flag algorithm ka use karenge
        // Isme hum three variables lenge jinki help se hum 0's ko left side shift kardenge
        // and 2's ko right ki side shift kardenge
        // 1's middle mein apne aap sort hojayenge
        // TC = > O(N)   SC => O(1)
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low], a[mid]);
                low++;
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};

// Problem : Three way partitioning GFG
class Solution
{
public:
    void threeWayPartition(vector<int> &arr, int a, int b)
    {
        // Dutch national flag algorithm ka use karenge
        // Isme hum three variables lenge jinki help se hum 'a' se less waale numbers ko left side shift kardenge
        // and 'b' se greater waale elements ko right ki side shift kardenge
        // Middle waale elements apne aap sort hojayenge
        // TC = > O(N)   SC => O(1)
        int mid = 0;
        int low = 0;
        int high = arr.size() - 1;
        while (mid <= high)
        {
            if (arr[mid] < a)
            {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] > b)
            {
                swap(arr[mid], arr[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};

// Problem : Find missing and repeating numbers GFG
class Solution
{
public:
    // TC => O(N)  SC => O(1)
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // Simply hum given array ka sum and sqaure sum nikalenge
        // Phir iss sum and sqaure sum ko unke 1 to n tak ke sum and square sum se minus kardenge
        // Phir two equations banegi inki help se missing and repeating number ko nikalenge
        // Formula to find sum of numbers from 1 to n
        long long int tSum = n * (n + 1) / 2;
        // Formula to find sum of square of numbers from 1 to n
        long long int tSqaureSum = (n * (n + 1) * (2 * n + 1)) / 6;
        long long int sum = 0;
        long long int sqaureSum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (long long int)arr[i];
            sqaureSum += (long long int)arr[i] * (long long int)arr[i];
        }
        // X-Y = val1
        long long int equation1 = sum - tSum;
        // X^2 - Y^2 = val2
        // X+Y = val2/(X-Y)
        // X+Y = val2/val1
        long long int sqaureEquation = sqaureSum - tSqaureSum;
        // X-Y = val1
        long long int equation2 = sqaureEquation / equation1;
        // repeating number (X) equations ko add karke milega
        long long int repeatingNumber = (equation1 + equation2) / 2;
        // missing number (Y) equations ko subtract karke milega
        long long int missingNumber = repeatingNumber - equation1;
        return {(int)repeatingNumber, (int)missingNumber};
        // X+Y = val2
    }
};

// Problem : Rearrange an array with O(1) extra space GFG
class Solution
{
public:
    // Optimised code using trick : trick yehi hai ki current position par jo number hai usse x maan lenge
    // phir array ki x position par jo element hai usse n se mod karke n se hi multiply kardenge and phir x mein add karke
    // current position par store kardenge array ki.
    // ab is trick se ye hoga ki hum two numbers ko ek hi position par store kar paa rahe hai jiski wajah se dusre traversal mein hume
    // current position par konsa number hoga ye pata chal jaayega just n se divide karke dekhlo.
    // Examples par dry run karlo samajh aajayega.
    // TC => O(N)   SC => O(1)
    void arrange(long long arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            int y = arr[x];
            arr[i] = x + (y % n) * n;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] /= n;
        }
    }
};

// Problem : Rearrange array alternatively GFG
class Solution
{
public:
    // Optimised code : Isme hum ek hi position par two numbers ko rakhne ki koshish karenge
    // Dividened = Quotient*Divisor + Remainder
    // Dividend/Divisor = Quotient
    // Dividend%Divisor = Remainder
    // Yahan remainder old value ko represent karega and Quotient new(final answer at current position) value ko represent karega
    // ek cheez notice karo ki hume hamesha even index par maximum number ko rakhna hai and odd position par minimum value ko
    // TC => O(N)    SC => O(1)
    void rearrange(long long *arr, int n)
    {
        int MAX = arr[n - 1] + 1;
        int min_index = 0;
        int max_index = n - 1;
        for (int i = 0; i < n; i++)
        {
            // even index hai toh current value mein maximum value ko add karna hoga but pehle mod lena hoga MAX se taaki previous value mil
            // sake
            if (i % 2 == 0)
            {
                arr[i] = (arr[max_index] % MAX) * MAX + arr[i];
                max_index--;
            }
            // odd index hai toh current value mein minimum value ko add karna hoga but pehle mod lena hoga MAX se taaki previous value mil
            // sake
            else
            {
                arr[i] = (arr[min_index] % MAX) * MAX + arr[i];
                min_index++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] /= MAX;
        }
    }
};

// Problem : Next Permutation GFG
class Solution
{
public:
    // {1,2,3,6,5,4}
    // 3>6 toh hum first_index mein 2 ko rakhlenge
    // ab last se dubara check karenge ki konsa number greater hai 3 se
    // 4 greater hai 3 se toh 3 and 4 ko swap kardenge
    // {1,2,4,6,5,3} ko ab hum 6 se 3 tak reverse kardenge
    // Final answer array hoga : {1,2,4,3,5,6}
    // TC => O(N)   SC => O(1)
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        // Hum ek variable le lenge jiski help se hum last se us index ko find karne ki koshish karenge jahan par current number next
        // number se less hoga taaki jo bhi small number wala index hai usse last mein shift kar sake
        int first_index = INT_MAX;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                first_index = i;
                break;
            }
        }
        // agar koyi bhi number apne next number se chota nahi hoga toh hume pure vector ko reverse kardenge
        if (first_index == INT_MAX)
        {
            reverse(arr.begin(), arr.end());
        }
        // warna hum last se us index ko find karne ki koshish karenge jo ki hamare first_index waale number par hai usse greater hoga
        // jese hi high_index ka number milega toh hum first_index and last_index waale number ko swap kardenge phir
        // first_index ke next index se last tak ke numbers ko swap kardenge
        else
        {
            int high_index = INT_MAX;
            for (int i = n - 1; i >= 0; i--)
            {
                if (arr[i] > arr[first_index])
                {
                    high_index = i;
                    break;
                }
            }
            swap(arr[first_index], arr[high_index]);
            reverse(arr.begin() + first_index + 1, arr.end());
        }
        return arr;
    }
};

// Problem : Merge Without Extra Space
class Solution
{
public:
    // Optimised Approach : Two pointers ki help lenge.
    // Agar array1 mein current position par element already less hai than element at current position of array2 then simply array1 mein aage
    // badhenge warna array2 ki current position waale element ko swap kardenge last element se array1 ke.
    // Last mein simply sort kardenge arrays ko.
    // TC => O(2*(NlogN)) hogi
    // SC => O(1) hogi
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int i = 0, j = 0, k = n - 1;
        while (i <= k && j < m)
        {
            if (arr1[i] < arr2[j])
                i++;
            else
            {
                swap(arr2[j++], arr1[k--]);
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

// Problem : Count Inversions GFG
class Solution
{
    // Brute Force : simply 2 for loops lagao and phir check karte jao condition ki a[i]>a[j] hai toh count++
    // TC => O(N^2)   SC => O(1)
public:
    // Optimal Approach : Using merge sort and concept of using sorted arrays. Merge sort mein hi 2-3 lines ka change karna hai. Hum bas ye try
    // kar rahe hai ki har branch mein sort karne ke baad hume two sorted arrays milte hai toh unke beech mein two pointers ka concept laga rahe.
    // Dry run dekho iska youtube par ya kisi website par zyada clear hoga.
    // TC => O(NlogN)     SC =>O(N) because ek temporary array bhi le rahe hai
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
    {
        long long inv_count = 0;
        long long i = left;
        long long j = mid;
        long long k = left;
        while ((i <= mid - 1) && (j <= right))
        {
            if (arr[i] <= arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
                // inversion ka count lenge jo ki hoga inversion count so far + mid-i because agar ith wala element less hai j se toh
                // i se mid tak ke saare element smaller honge mid se iske liye example se dry run karke dekhna padega
                inv_count = inv_count + (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];
        // Simply current array portion se jo bhi count mila hoga inversion ka usse return kardenge
        return inv_count;
    }

    long long merge_Sort(long long arr[], long long temp[], long long left, long long right)
    {
        long long mid;
        long long inv_count = 0;
        if (right > left)
        {
            mid = (left + right) / 2;
            // current portion se array ke jo inversion count milega usse add karo
            inv_count += merge_Sort(arr, temp, left, mid);
            // current portion se array ke jo inversion count milega usse add karo
            inv_count += merge_Sort(arr, temp, mid + 1, right);
            // jab merge hoga toh current portion se array ke jo inversion count milega usse add karo
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return merge_Sort(arr, temp, 0, N - 1);
    }
};

// Problem : Maximum Product Subarray Leetcode
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // TC => O(N)
        // SC => O(1)
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        // Simply prefix and suffix products ka use karenge and agar kahin par bhi 0 aata hai toh iska matlab hai ki wahan se new subarray start ho raha hai
        int prefixProduct = 1, suffixProduct = 1;
        int product = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            prefixProduct *= nums[i];
            suffixProduct *= nums[n - i - 1];
            product = max(product, max(prefixProduct, suffixProduct));
            // agar prefix product 0 hojata hai toh usse 1 kardenge taaki ye show kar saken ki yahan se new subarray start ho raha hai
            if (prefixProduct == 0)
                prefixProduct = 1;
            // agar suffix product 0 hojata hai toh usse 1 kardenge taaki ye show kar saken ki yahan se new subarray start ho raha hai
            if (suffixProduct == 0)
                suffixProduct = 1;
        }
        return product;
    }
};

// Problem : Reverse Pairs LeetCode
class Solution
{
    // Interviewer se hamesha puchna ki kya aap given array ko alter kar sakte hai warna ek temporary vector le lena.
    // O( N log N ) + O (N) + O (N) becausecO(N) Merge operation karne mein lagega, O(N) counting operation mein lagega ( at each iteration of i,
    // j doesn’t start from 0 . Both of them move linearly )
public:
    // Simply merge sort ka hi concept laga hai bas 2-3 lines extra hogayi hai
    // Almost same logic as count inversions question but yahan ye dhyaan rakhna hai ki merge karne se pehle dono sorted array mein agar ek particular
    // left array ka element greater hai kisi particular index se toh uske aage ke index se hi left array ke further elements ko compare karna start
    // karenge. For example :
    // left array = [7,8,9]   right array = [3,4,5]
    // Yahan par 7 jo hai woh 2*3 se bada hai toh count = 1 hoga and right array mein index 1 par hi ruk jaayega for 7.
    // Ab 8 ke liye index 1 se hi start karenge compare karna 2*4 less hai toh count = 1 hi rahega and index bhi 1 hi rahega
    // Ab 9 ke liye dekhenge toh 2*4 se greater hai toh count = 1+2 hojayega. 2 isliye add hoga because 4 tak ke saaare elements ke twice se greater
    // hoga 9.
    int Merge(vector<int> &nums, int low, int mid, int high)
    {
        // Ye ek particular logic hai jo ki hume help karega index ko track karne mein ki kahan tak index pauncha hai and kahan see comparing start
        // karni hai right array mein
        int total = 0;
        int j = mid + 1;
        // outer loop left array ke elements ke liye hai
        for (int i = low; i <= mid; i++)
        {
            // inner loop right array ke elements ke liye hai
            while (j <= high && nums[i] > 2 * (long long)nums[j])
            {
                j++;
            }
            // left array ka ek element mid+1 se jth tak ke saare elements ke twice se greater hai
            total += (j - (mid + 1));
        }

        vector<int> t;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {

            if (nums[left] <= nums[right])
            {
                t.push_back(nums[left++]);
            }
            else
            {
                t.push_back(nums[right++]);
            }
        }

        while (left <= mid)
        {
            t.push_back(nums[left++]);
        }
        while (right <= high)
        {
            t.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = t[i - low];
        }
        return total;
    }

    int MergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        // array ko break karte waqt jo count milega
        int countPairs = MergeSort(nums, low, mid);
        countPairs += MergeSort(nums, mid + 1, high);
        // wapis merge karte waqt jo count milega
        countPairs += Merge(nums, low, mid, high);
        return countPairs;
    }
    int reversePairs(vector<int> &nums)
    {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};

// Problem : Maximum Circular subarray sum
class Solution
{
public:
    // TC => O(N)   SC => O(1)
    // simply kadane's algorithm ka use kar rahe hai
    int kadane(vector<int> &arr)
    {
        int ans = arr[0], sum = 0;
        for (int i : arr)
        {
            sum += i;
            ans = max(ans, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // Sabse pehle hum normal kadane's algorithm ki help se sum le aayenge
        int x = kadane(nums);
        int sum = 0;
        // ab hum har element ko array mein -1 se multiply kardenge and total sum ko bhi saath mein hi calculate karte rahenge
        for (int &i : nums)
        {
            sum += i;
            i = -i;
        }
        // ab hum modified vector par dubara kadane's algorithm lagayenge
        int y = kadane(nums);
        // agar total sum + modified vector se jo kadane's algorithm ne sum diya hai inka sum 0 hoga toh return kadane's algorithm se
        // bina modify kare jo sum mila tha usse hi send kardo
        if (sum + y == 0)
        {
            return x;
        }
        // warna maximum bhejdo normal kadane's algorithm se jo sum mila tha usme and sum of modified vector kadane's algorithm + total sum ka
        return max(x, y + sum);
    }
};

// Problem : Next Smallest Palindrome GFG
class Solution
{
    // Brute force approach : Given number mein hi 1 add karte jao and har baar new number ko check karo ki kya ye palindrome hai
    // TC => O(N*N)   SC => O(1)
public:
    // Optimised Approach : TC => O(N)  SC => O(N) just for result vector
    // Kuch cases ko consider karte hai aproach ko banane ke liye :
    // Case-1 : Jab number of digits given number mein even hongi toh hum simply number ko 2 parts mein divide kardenge ek leftpart and
    // dusra right part. Aur phir left part ko reverse karke right mein part mein daal denge and check kar lenge ki kya ye given number se
    // bada hai palindrome agar haan toh isse hi return kardo warna left part ko 1 se increment karke phir leftpart ko reverse karke daaldo
    // rightpart mein. For example : 123456
    // after reversal 123321 < 123456 toh hume middle element ko increment karna hoga
    // ab 124421 > 123456 se toh 1235321 hi hamara next smallest palindrome hoga
    // Case-2: Jab number of digits given number mein odd hongi toh hum simply number ko 2 parts mein divide kardenge ek leftpart and
    // dusra right part. Aur phir left part ko reverse karke right mein part mein daal denge and check kar lenge ki kya ye given number se
    // bada hai palindrome agar haan toh isse hi return kardo warna left part ko 1 se increment karke phir leftpart ko reverse karke daaldo
    // rightpart mein. Yahan jab hum 1 add karenge toh woh middle element mein add hokar aage left part mein as carry jaa bhi sakta hai aur
    // nahi bhi jaa sakta hai. For example : 1234567
    // after reversal 1234321 < 1234567 toh hume middle element ko increment karna hoga
    // ab 1235321 > 1234567 se toh 1235321 hi hamara next smallest palindrome hoga
    bool compare(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
        }
        return false;
    }
    vector<int> generateNextPalindrome(int num[], int n)
    {
        // Ek vector le lenge jiski help se hum given number ke left and right part ko compare kar paayen
        vector<int> a;
        int cnt = 0;
        // is loop ki help se hum ye check kar rahe hai ki current number ki saari digits 9 toh nahi hai
        for (int i = 0; i < n; i++)
        {
            if (num[i] == 9)
                cnt++;
            a.push_back(num[i]);
        }
        // agar saari digits 9 hai toh hum ek vector n+1 size ka initialize kardenge taaki next smallest palindrome ko return kar saken
        if (cnt == n)
        {
            // by default saari digits is vector mein 0 hongi
            vector<int> temp(n + 1, 0);
            // temp mein sabhi digits zero hongi except first and last. Isse samjhane ke liye ek example lete hai : 9999 toh N = 4
            // next palindrome hoga 10001 toh vector ka size 5 hojayega
            temp[0] = 1;
            temp[n] = 1;
            return temp;
        }
        // agar given number mein odd number of digits hai toh
        if (n % 2 != 0)
        {
            // sabse pehle given number ki ek copy bana lenge
            vector<int> b = a;
            // ab hum given number ke left part ko reverse karke copy vector mein daal rahe hai taaki compare kar sake.For example : a = 12131
            // toh b = 12121 hojayega
            for (int i = (n / 2) + 1, k = (n / 2) - 1; i < n; i++, k--)
            {
                b[i] = a[k];
            }
            // agar 'b' greater hoga 'a' se toh return kardenge 'b' ko hi because yehi next palindrome hai
            if (compare(b, a))
                return b;
            // agar 'b' greater nahi hai 'a' se toh hum kya karenge ki middle element mein 1 add karke left part ko increase karenge
            //  upar waale example ke liye : 12221 hoajega aur yehi hamara palindrome hai
            for (int i = n / 2; i >= 0; i--)
            {
                // agar 9 nahi hai toh middle element mein 1 add karke loop se break kardo because koyi carry toh generate hoga nahi
                if (b[i] != 9)
                {
                    b[i]++;
                    break;
                }
                // agar middle element 9 hai toh usse 0 kardo and further aese hi left part ko update kardo agar unme bhi 9 hai toh
                else
                    b[i] = 0;
            }
            // left part ko right part mein reverse karke put kardenge and 'b' ko return kardenge
            for (int i = (n / 2) + 1, k = (n / 2) - 1; i < n; i++, k--)
            {
                b[i] = b[k];
            }
            return b;
        }
        // agar number mein even number of digits hai toh
        else
        {
            // sabse pehle given number ki ek copy bana lenge
            vector<int> b = a;
            // ab hum given number ke left part ko reverse karke copy vector mein daal rahe hai taaki compare kar sake.For example : a = 1231
            // toh b = 1221 hojayega
            for (int i = (n / 2), k = (n / 2) - 1; i < n; i++, k--)
            {
                b[i] = a[k];
            }
            // agar 'b' greater hoga 'a' se toh return kardenge 'b' ko hi because yehi next palindrome hai
            if (compare(b, a))
                return b;
            // agar 'b' greater nahi hai 'a' se toh hum kya karenge ki left part mein 1 add karke left part ko increase karenge
            //  upar waale example ke liye : 1321 hoajega aur yehi hamara palindrome hai
            for (int i = n / 2 - 1; i >= 0; i--)
            {
                // agar 9 nahi hai toh middle element mein 1 add karke loop se break kardo because koyi carry toh generate hoga nahi
                if (b[i] != 9)
                {
                    b[i]++;
                    break;
                }
                // agar middle element 9 hai toh usse 0 kardo and further aese hi left part ko update kardo agar unme bhi 9 hai toh
                else
                    b[i] = 0;
            }
            // // left part ko right part mein reverse karke put kardenge and b ko return kardenge
            for (int i = (n / 2), k = (n / 2) - 1; i < n; i++, k--)
            {
                b[i] = b[k];
            }
            return b;
        }
    }
};