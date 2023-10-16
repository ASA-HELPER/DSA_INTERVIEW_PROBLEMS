// Problem : Bulb Switcher Leetcode
class Solution
{
    // TC => O(sqrt(n))    SC => O(1)
public:
    // Dry runn karne par pata chalega ki sirf wahi numbers reh jaayenge jinka square less than equal to n hoga
    int bulbSwitch(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int count = 0;
        for (int i = 1; i * i <= n; i++)
        {
            count++;
        }
        return count;
    }
};

// Problem : Swap and Maximize GFG
// TC => O(NlogN)
long long int maxSum(int arr[], int n)
{
    // jab array ka size 2 hoga toh first and second element ka difference do baar nikalna
    // hoga because circular array hai ye
    if (n == 2)
    {
        return 2 * abs(arr[0] - arr[1]);
    }
    // simply sort kardenge
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    long long int sum = 0;
    // two pointers ki help lenge
    while (i < j)
    {
        // sabse pehle mein ith and jth pointer ke beech ka difference add karlunga
        sum += abs(arr[i] - arr[j]);
        // ab mein ye dekhunga ki kya i+1<j hai because agar hum first example ko dekhen toh
        // hum observe karenge ki arrangement kuch aesa hai smaller element then greater element
        // then smaller element then greater element. Toh hum yahan visualize kar rahe hai
        // ki greater element 2 smaller elements ke beech mein hi hai toh hum uska difference
        // dono chote elements ke saath ek hi baar mein nikal rahe hai. Matlab ith and (i+1)th
        // element ke beech mein jth element ke baare mein visualize kar rahe hai ki woh wahin
        // par hai.
        // For example : Sort karne ke baad array aesa hoga : [1,2,4,8]
        // toh hum 8 ka difference 1 and 2 dono ke saath nikal rahe hai usse un dono ke beech
        // mein rakha hua soch kar
        if (i + 1 < j)
        {
            sum += abs(arr[i + 1] - arr[j]);
        }
        i++;
        j--;
    }
    // circular array hai toh hamara ith pointer jahan jaake rukega wahi hamara rearrangement
    // ka last element hoga toh uska array ke first element ke saath difference nikal kar
    // add karna jaroori hai because array circular hai as per the question.
    sum += abs(arr[0] - arr[i]);
    return sum;
}

// Problem : N meetings in a room GFG
class Solution
{
public:
    // TC => O(NlogN)     SC => O(N)
    int maxMeetings(int start[], int end[], int n)
    {
        // hum ek pair bana lenge taaki har meeting ke start and end time ko ek dusre se bind kar saken
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++)
        {
            meetings.push_back({end[i], start[i]});
        }
        // end time ke according acsending order mein sort kardenge
        sort(meetings.begin(), meetings.end());
        // first meeting ko le rahe hai toh uska end time apne paas rakh lenge
        int End = meetings[0].first;
        // ek meeting le li hai toh max meetings abhi tak 1 hojaayengi
        int maxMeet = 1;
        for (int i = 1; i < n; i++)
        {
            // agar previous meeting ka end time current meeting ke start time se less hai toh
            // ek aur meeting ko hum room mein karwa sakte hai toh hume simply meetings ke count
            // ko increase karenge and end time ko update kardenge
            if (End < meetings[i].second)
            {
                maxMeet++;
                End = meetings[i].first;
            }
        }
        return maxMeet;
    }
};

// Problem : Maximum Meetings in one room GFG
class Solution
{
public:
    // TC => O(NlogN)    SC => O(N)
    vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end)
    {
        // hum vector of pairs banayenge and usme hum {end time,start time,index+1} store karenge
        vector<pair<int, pair<int, int>>> meetings;
        for (int i = 0; i < n; i++)
        {
            meetings.push_back({end[i], {start[i], i + 1}});
        }
        // sort kardo meetings ko end time ke base par
        sort(meetings.begin(), meetings.end());
        // first meeting ke liye previously end time -1 rahega
        int End = -1;
        // maximum 1 meeting toh hogi hi
        int maxMeet = 1;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            // agar current meeting ka start time current end time se zyada hai toh new meeting banegi
            if (End < meetings[i].second.first)
            {
                res.push_back(meetings[i].second.second);
                maxMeet++;
                End = meetings[i].first;
            }
        }
        // indexes ko sort karke send karna hoga
        sort(res.begin(), res.end());
        return res;
    }
};

// Problem : Non-Overlapping Intervals or Disjoint Intervals GFG
class Solution
{
    // TC => O(NlogN)     SC => O(1)
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
        {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals)
    {
        // end time ke base par sort karlo
        sort(intervals.begin(), intervals.end());
        int count = 0;
        // end time ko track karenge saath ke saath
        int end = intervals[0][1];
        for (int i = 1; i < N; i++)
        {
            // agar current interval ka start time previous waale interval ke end time se
            // zyada hai toh current interval waale ke end time ko new end time bana do
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
            }
            // warna overlapping hogi toh yahan hume end time ko check karna hoga kiska zyada hai
            else
            {
                count++;
                end = min(end, intervals[i][1]);
            }
        }
        return count;
    }
};

// Problem : Find Maximum Equal sum of Three Stacks GFG
class Solution
{
public:
    // TC => O(N1+N2+N3)     SC => O(1)
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        // Teeno given arrays ka sum nikal lenge and phir un sums ka minimum apne paas rakhlenge
        for (int i = 0; i < N1; i++)
        {
            sum1 += S1[i];
        }
        for (int i = 0; i < N2; i++)
        {
            sum2 += S2[i];
        }
        for (int i = 0; i < N3; i++)
        {
            sum3 += S3[i];
        }
        int minSum = min({sum1, sum2, sum3});
        int i = 0, j = 0, k = 0;
        // teeno arrays mein traverse karte huye ye dekhenge ki kiska sum greater hai minimum sum se
        // jiska sum greater uske current element ko uske sum se subtract karke aage badhte rahenge
        // aur har baar check karlenge ki kya teeno ka sum equal hogaya hai
        while (i <= N1 && j <= N2 && k <= N3)
        {
            if (sum1 > minSum)
            {
                sum1 -= S1[i++];
            }
            if (sum2 > minSum)
            {
                sum2 -= S2[j++];
            }
            if (sum3 > minSum)
            {
                sum3 -= S3[k++];
            }
            if (sum1 == sum2 && sum2 == sum3)
            {
                return sum1;
            }
            // kyunki sums ki value change huyi hai toh minimum sum ko bhi update karna padega
            minSum = min({minSum, sum1, sum2, sum3});
        }
        // Agar teeno ke sums ki value equal nahi huyi hai toh return 0
        return 0;
    }
};

// Problem : Huffman Decoding GFG
// TC => O(NlogN)   SC => O(1)
string decodeHuffmanData(struct MinHeapNode *root, string binaryString)
{
    string res;
    MinHeapNode *tmp = root;
    // Hume bas itna pata hai ki huffman coding mein first node se leaf node tak hume ek value deta hai
    // toh hum saare root to leaf ke paths ko explore karlenge using giving string
    for (int i = 0; i < binaryString.length(); ++i)
    {
        if (binaryString[i] == '0')
            tmp = tmp->left;
        else
            tmp = tmp->right;
        if (tmp->left == NULL && tmp->right == NULL)
        {
            res += tmp->data;
            tmp = root;
        }
    }
    return res;
}

// Problem : Largest number with given sum GFG
class Solution
{
public:
    // TC => O(N)   SC => O(1)
    string largestNumber(int n, int sum)
    {
        string ans = "";
        // jab tak sum greater hai 9 se tab tak 9 se subtract karte rahenge
        while (sum > 0 && n > 0)
        {
            if (sum >= 9)
                ans += '9';
            else
                ans += to_string(sum);
            sum -= 9;
            n--;
        }
        if (sum > 0)
            return "-1";
        // agar sum khatam hogaya hai and digits baaki hai abhi bhi toh zeroes append kardo
        while (n--)
            ans += '0';
        return ans;
    }
};

// Problem : Water the plants GFG
class Solution
{
    // TC => O(NlogN)   SC => O(N)
public:
    int min_sprinklers(int gallery[], int n)
    {
        int count = 0, target = 0;
        vector<pair<int, int>> span;
        // har index ke liye uske range ko bana kar rakh lenge apne paas ki agar us position par agar sprinkler rakhte hai toh woh
        // kahan tak plants ko water de paayega
        for (int i = 0; i < n; i++)
        {
            if (gallery[i] != -1)
            {
                span.push_back({i - gallery[i], i + gallery[i]});
            }
        }
        // sort kardo ranges ko
        sort(span.begin(), span.end());

        int m = span.size(), idx = 0;
        // traverse karenge range vector ke through and jahan tak ke plants ko water kar paa rahe honge
        // jis bhi index par sprinkler laga rahe hai usse apne count mein rakh lenge
        while (target < n && idx < m)
        {
            int next_target = -1;

            if (span[idx].first > target)
                return -1;

            while (idx < m && span[idx].first <= target)
            {
                next_target = max(next_target, span[idx].second);
                idx += 1;
            }
            target = next_target + 1;
            count += 1;
        }

        return target >= n ? count : -1;
    }
};

// Problem : Police and Thieves GFG
class Solution
{
public:
    // TC => O(N)    SC => O(N)
    int catchThieves(char arr[], int n, int k)
    {
        int i = 0, j = 0, count = 0;
        vector<int> vis(n, 0);
        // two pointers ka use karenge and ith pointer ko first police ke paas lekar jaayenge
        while (i < n && arr[i] != 'P')
            i++;
        // two pointers ka use karenge and jth pointer ko first thief ke paas lekar jaayenge
        while (j < n && arr[j] != 'T')
            j++;

        while (i < n and j < n)
        {
            // agar abhi tak thief visited mark nahi hai and thief and police ke beech ka distance less than k hai toh
            // mark karlo is thief ko and count ko increase kardo
            if (arr[i] == 'P' and arr[j] == 'T' and abs(j - i) <= k and !vis[j])
            {
                count++;
                vis[j] = 1;
                i++;
                j++;
            }
            // agar distance zyada hai toh distance ko kum karna hoga
            else if (abs(j - i) > k)
            {
                if (j > i)
                    i++;
                else
                    j++;
            }
            // agar current position par thief hai jahan hum police ko dhund rahe hai toh ith pointer ko aage badhao
            else if (arr[i] == 'T')
                i++;
            // agar current position par police hai jahan hum theif ko dhund rahe hai toh jth pointer ko aage badhao
            else if (arr[j] == 'P')
                j++;
        }
        return count;
    }
};