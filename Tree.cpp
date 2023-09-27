// Problem : Print Nodes having K leaves GFG
class Solution
{
    // TC => O(N)    SC => O(H)
public:
    // Ek helper function bana lenge jo ki har node ke liye number of leaf nodes ko calculate
    // karega postorder traversal ka use karke and jis bhi node par number of nodes equal to
    // k hojaayenge us node ko apne answer vector mein store karlo
    int helper(Node *root, int k, vector<int> &res)
    {
        if (root == NULL)
        {
            return 0;
        }
        // Jese hi leaf node mile toh 1 return kardo
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int Left = helper(root->left, k, res);
        int Right = helper(root->right, k, res);
        // left and right se jitne bhi leaf nodes milenge agar unka total k ke equal hai toh
        // current node ko apne answer vector mein store karlo
        if ((Left + Right) == k)
        {
            res.push_back(root->data);
        }
        return Left + Right;
    }
    vector<int> btWithKleaves(Node *ptr, int k)
    {
        vector<int> res;
        helper(ptr, k, res);
        // agar ek bhi node aesa nahi hai jiske paas k leaf nodes hai toh return -1
        if (res.size() == 0)
        {
            return {-1};
        }
        return res;
    }
};

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

// Problem : Check if all levels of two trees are anagrams or not GFG
class Solution
{
public:
    // TC => O(N)    SC => O(N)
    bool areAnagrams(Node *root1, Node *root2)
    {
        // agar dono mein se kisi bhi tree ka root null hoga toh anagram nahi ho sakte hai
        if (root1 == NULL or root2 == NULL)
        {
            return false;
        }
        // agar dono trees ke root null hai toh return true
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        // agar dono tree ke root ka data hi same nahi hai toh anagram nahi ho sakta hai
        if (root1->data != root2->data)
        {
            return false;
        }
        // dono trees ke liye queues le lenge
        queue<Node *> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while (!q1.empty() && !q2.empty())
        {
            int n1 = q1.size();
            int n2 = q2.size();
            // agar dono queues ka size same nahi hai toh iska matlab hai ki current level par number of nodes dono trees ke vary kar rahe hai
            if (n1 != n2)
            {
                return false;
            }
            // ek map le lenge jisme har node ki value ka counter rakhenge
            unordered_map<int, int> nodes;
            for (int i = 0; i < n1; i++)
            {
                Node *node1 = q1.front();
                Node *node2 = q2.front();
                q1.pop();
                q2.pop();
                nodes[node1->data]++;
                nodes[node2->data]++;
                if (node1->left)
                {
                    q1.push(node1->left);
                }
                if (node1->right)
                {
                    q1.push(node1->right);
                }
                if (node2->left)
                {
                    q2.push(node2->left);
                }
                if (node2->right)
                {
                    q2.push(node2->right);
                }
            }
            // agar nodes waale map mein kisi bhi node ki value ki frequency even nahi hoti hai toh iska matlab anagram nahi hoga
            for (auto it : nodes)
            {
                if (it.second % 2 != 0)
                {
                    return false;
                }
            }
        }
        if (q1.size() != q2.size())
        {
            return false;
        }
        return true;
    }
};