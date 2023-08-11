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