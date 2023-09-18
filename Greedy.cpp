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