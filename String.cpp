// Problem : check if two strings are rotations of each other or not GFG
class Solution
{
public:
    bool areRotations(string s1, string s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        int i = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if ((s1.substr(i) + s1.substr(0, i)) == s2)
            {
                return true;
            }
        }
        return false;
    }
};

// Problem : Binary String GFG
class Solution
{
public:
    // Time Complexity : O(N)
    // Ṣpace Complexity : O(1)
    long binarySubstring(int n, string a)
    {
        // simple observation
        // count karlo number of ones ko and then usse multiply kardo (ones-1) se and divide by 2 kardo
        long long int ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                ones++;
            }
        }
        return (ones * (ones - 1)) / 2;
    }
};

// Problem : Min Number of Flips GFG
int minFlips(string S)
{
    int n = S.size();
    int count = 0;
    for (int i = 0; i < S.size(); i++)
    {
        // even positions par consider kar rahe hai ki zero hoga
        if (i % 2 == 0)
        {
            // agar zero nahi hai toh flip karna padega
            if (S[i] == '1')
                count++;
        }
        else
        {
            // agar odd position par zero hoga toh bhi flip karna hoga because humne consider kiya hai zero even positions par hoga
            if (S[i] == '0')
                count++;
        }
    }

    int counter = 0;

    for (int i = 0; i < S.size(); i++)
    {
        // even positions par consider kar rahe hai ki one hoga
        if (i % 2 == 0)
        {
            if (S[i] == '0')
                counter++;
        }
        else
        {
            // agar odd position par one hoga toh bhi flip karna hoga because humne consider kiya hai ones even positions par honge
            if (S[i] == '1')
                counter++;
        }
    }

    return min(counter, count);
}