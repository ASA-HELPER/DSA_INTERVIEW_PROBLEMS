// Problem : Minimum Absolute Difference in BST or Minimum Distance Between BST Nodes Leetcode
class Solution
{
public:
    // TC => O(N)       SC => O(N)
    // Simply inorder traversal lagaya hai jo ki left and right childs ko compare karta jaayega bas isme hum previous node ka concept use kar rahe hai
    void inorder(TreeNode *curr, TreeNode *&prev, int &ans)
    {
        if (curr == NULL)
            return;
        inorder(curr->left, prev, ans);
        if (prev != NULL)
            ans = min(curr->val - prev->val, ans);
        prev = curr;
        inorder(curr->right, prev, ans);
    }
    int getMinimumDifference(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int min = INT_MAX;
        TreeNode *prev = NULL;
        inorder(root, prev, min);
        return min;
    }
};

// Problem : Binary Search Tree Iterator Leetcode
class BSTIterator
{
    // TC => O(1) for next and hasNext functions
    // SC => O(height of BST)
public:
    // Saare nodes ko store karlenge hum using DFS (inorder traversal)
    int curr = 0, pos = 0, store[10001];
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        store[pos++] = root->val;
        dfs(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        dfs(root);
    }

    // Ye current node ko return karega and next right pointer par jaayenge
    int next()
    {
        return store[curr++];
    }

    // Ye batayega ki current node ke paas next right pointer hai ya nahi
    bool hasNext()
    {
        // Ye pos variable right most node ka index hai BST mein
        return curr < pos;
    }
};