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