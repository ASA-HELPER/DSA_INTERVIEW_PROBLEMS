// Rat in a maze problem I GFG
class Solution
{
    // TC => O(2^(n^2))  SC => O(n^2)
public:
    vector<string> res;
    void helper(vector<vector<int>> &m, int n, int i, int j, string temp, vector<vector<int>> &vis)
    {
        if (i >= n or j >= n or j < 0 or i < 0 or m[i][j] == 0 or vis[i][j] == 1)
        {
            return;
        }
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(temp);
            return;
        }
        vis[i][j] = 1;
        helper(m, n, i + 1, j, temp + 'D', vis);
        helper(m, n, i, j + 1, temp + 'R', vis);
        helper(m, n, i - 1, j, temp + 'U', vis);
        helper(m, n, i, j - 1, temp + 'L', vis);
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<int>> vis(n, vector<int>(n, 0));
        helper(m, n, 0, 0, "", vis);
        return res;
    }
};

// Largest number in K swaps GFG
class Solution
{
public:
    void helper(string s, string &largestNumber, int k, int idx)
    {
        // agar number of swaps khatam hogaye toh return hojao
        if (k == 0)
        {
            return;
        }
        int n = s.size();
        // current string ka first character hum maan rahe hai ki largest character hai string mein
        char maxChar = s[idx];
        // ab string mein aage traverse karke find karne ki koshish karenge ki current max character max hai ya aage koyi aur character hai
        // jo ki maximum character ban sakta hai toh usse appne paas rakhlenge
        for (int i = idx + 1; i < n; i++)
        {
            if (maxChar < s[i])
            {
                maxChar = s[i];
            }
        }
        // agar current character jisse humne max character maana tha intially maximum character nahi hai toh iska matlab swap karna padega
        if (maxChar != s[idx])
        {
            k -= 1;
        }
        for (int i = idx; i < n; i++)
        {
            // ab hum string mein traverse karke maximum character ki position tak jaayenge and phir current character and maximum character
            //  ko swap karke check karenge ki current string maximum hai ya phir largestNumber waala string maximum hai
            if (s[i] == maxChar)
            {
                swap(s[i], s[idx]);
                if (s.compare(largestNumber) > 0)
                {
                    largestNumber = s;
                }
                helper(s, largestNumber, k, idx + 1);
                // backtracking step
                swap(s[i], s[idx]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        //   Hum initially yehi maan kar chal rahe hai ki hamara given string hi maximum string hai
        string largestNumber = str;
        helper(str, largestNumber, k, 0);
        return largestNumber;
    }
};