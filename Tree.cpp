// Problem : Construct BST from postorder GFG
// TC => O(N)   SC => O(N)
Node *helper(int post[], int mini, int maxi, int &i)
{
    // agar saare nodes ko create kar chuke hai toh return NULL
    if (i < 0)
    {
        return NULL;
    }
    // agar current node minimum se chota hai ya maximum se bada hai toh return NULL
    if (post[i] <= mini || post[i] >= maxi)
    {
        return NULL;
    }
    // node create karenge
    Node *root = new Node(post[i--]);
    // pehle right mein daalo node ko and yahan minimum ab yehi node ban jaayega
    root->right = helper(post, root->data, maxi, i);
    // phir left mein daalenge and yahan maximum ab yehi node ban jaayega
    root->left = helper(post, mini, root->data, i);
    return root;
}

Node *constructTree(int post[], int size)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = size - 1;
    return helper(post, mini, maxi, i);
}

// Problem : Preorder to Postorder GFG
class Solution
{
public:
    // TC => O(N)       SC => O(N)
    Node *preToPost(int arr[], int start, int end)
    {
        // agar start zyada hojaata hai end se toh hum NULL return kardenge
        if (start > end)
        {
            return NULL;
        }
        // current element ka root bana lenge hum because preorder mein yehi root hoga main tree
        // ka and even subtree ke roots bhi aese hi recursively banege
        Node *root = newNode(arr[start]);
        // ab hum root waale node ke next se start karenge and usse chote elements jab tak milenge
        // tab tak mid ko aage badhate jaayenge
        int mid = start + 1;
        while (mid <= end && arr[mid] < arr[start])
        {
            mid++;
        }
        // jab condition fail huyi hogi toh mid aese element ko point kar raha hoga jo ki usse
        // greater hai toh mid ko decrement karna hoga taaki woh us index par aajaaye jahan usse
        // smaller last element present hai
        mid--;
        // post order traversal technique follow kar rahe hai because yahan hum root se smaller
        // elements yaani left part ko pehle banayenge jo ki index start+1 se mid tak mein hai
        // and phir right part ko banayenge jo ki index mid+1 se end tak hai and phir root ko return
        // karenge
        root->left = preToPost(arr, start + 1, mid);
        root->right = preToPost(arr, mid + 1, end);
        return root;
    }
    Node *post_order(int pre[], int size)
    {
        Node *root = preToPost(pre, 0, size - 1);
        return root;
    }
};

// Problem : Print leaf nodes from preorder traversal of BST GFG
class Solution
{
    // TC => O(N)   SC => O(N)
    // iski explanation bilkul similar hai Preorder to Postorder GFG question ke
public:
    vector<int> ans;
    void preOrder(int arr[], int start, int end)
    {
        if (start > end)
        {
            return;
        }
        if (start == end)
        {
            ans.push_back(arr[start]);
            return;
        }
        int root = arr[start];
        int mid = start + 1;
        while (mid <= end && arr[mid] < arr[start])
        {
            mid++;
        }
        mid--;
        preOrder(arr, start + 1, mid);
        preOrder(arr, mid + 1, end);
    }
    vector<int> leafNodes(int arr[], int N)
    {
        preOrder(arr, 0, N - 1);
        return ans;
    }
};

// Problem : Preorder traversal and BST GFG
class Solution
{
    // TC => O(N)    SC => O(N)
public:
    int canRepresentBST(int arr[], int n)
    {
        // Hum ek stack le lenge and usme store karte rahenge elements ko
        stack<int> st;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            // agar stack khali hai ya phir stack ke top par jo element hai woh bada hai current
            // element se toh hume ye dekhna hoga ki kya K waala element bada toh nahi hai current
            // element se toh isse aese samajh sakte hai ki K parent node hai st stack ke top node
            // ka toh agar parent node greater hoga apne child ke child node se toh preorder nahi
            // banega because preorder mein pehle root ko lete hai phir left node ko and phir right
            // node ko
            if (st.empty() || arr[i] < st.top())
            {
                if (k > arr[i])
                {
                    return 0;
                }
                st.push(arr[i]);
            }
            else
            {
                // agar current element greater hai stack ke element se toh current element ko apne
                // paas rakhlo and stack se remove karte raho
                while (!st.empty() && st.top() < arr[i])
                {
                    k = st.top();
                    st.pop();
                }
                st.push(arr[i]);
            }
        }
        return 1;
    }
};

// Problem : Diagonal Travesal of Binary Tree
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        while (curr != NULL)
        {
            ans.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            curr = curr->right;
        }
    }

    return ans;
}

// Problem : Boundary Traversal of Binary Tree GFG
// Question easy hai but thoda lengthy hai
// Three parts mein karenge isse hum :
// Part-1 : saare left non-leaf nodes ko lenge hum
// Part-2 : saare leaf nodes ko collect karo
// Part-3 : saare right nodes ko collect karo but in reverse order

class Solution
{
public:
    void traverseLeft(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);

        if (root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    void traverseLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    void traverseRight(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        traverseLeft(root->left, ans);

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        traverseRight(root->right, ans);

        return ans;
    }
};

// Problem : Top View of Binary tree GFG
class Solution
{
public:
    // Yahan par hum horizontal distance ka concept use karenge and level order traversal
    // karenge
    vector<int> topView(Node *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> res;
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        mp[0] = root->data;
        while (!q.empty())
        {
            int qsize = q.size();
            int maxi = INT_MIN;
            for (int i = 0; i < qsize; i++)
            {
                Node *curr = q.front().first;
                int hd = q.front().second;
                q.pop();
                if (!mp[hd])
                {
                    mp[hd] = curr->data;
                }
                if (curr->left)
                {
                    q.push({curr->left, hd - 1});
                }
                if (curr->right)
                {
                    q.push({curr->right, hd + 1});
                }
            }
        }
        for (auto it : mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

// Problem : Bottom View of Binary Tree GFG
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> res;
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        mp[0] = root->data;
        while (!q.empty())
        {
            int qsize = q.size();
            int maxi = INT_MIN;
            for (int i = 0; i < qsize; i++)
            {
                Node *curr = q.front().first;
                int hd = q.front().second;
                q.pop();
                mp[hd] = curr->data;
                if (curr->left)
                {
                    q.push({curr->left, hd - 1});
                }
                if (curr->right)
                {
                    q.push({curr->right, hd + 1});
                }
            }
        }
        for (auto it : mp)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

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

// Problem : Function to return the ceil of given number in BST GFG
int findCeil(Node *root, int input)
{
    // TC => O(Height of the BST)   SC => O(Height of the BST)
    if (root == NULL)
        return -1;
    int ceilVal = -1;
    while (root)
    {
        // agar current node less than hai key se toh right mein jaate jao
        if (root->data < input)
        {
            root = root->right;
        }
        // warna successor ko apne paas rakhlo and left mein move karna start kardo taaki
        // NULL par paunch jaao
        else
        {
            ceilVal = root->data;
            root = root->left;
        }
    }
    return ceilVal;
}

// Problem : Function to return the floor of given number in BST GFG
class Solution
{
public:
    int floor(Node *root, int input)
    {
        // TC => O(Height of the BST)   SC => O(Height of the BST)
        if (root == NULL)
            return -1;
        int floorVal = -1;
        while (root)
        {
            // agar current node greater than hai key se toh left mein jaate jao
            if (root->data > input)
            {
                root = root->left;
            }
            // warna successor ko apne paas rakhlo and right mein move karna start kardo taaki
            // NULL par paunch jaao
            else
            {
                floorVal = root->data;
                root = root->right;
            }
        }
        return floorVal;
    }
};

// Problem : Predecessor and Successor of key in BST GFG
class Solution
{
    // TC => O(Height of the BST)   SC => O(Height of the BST)
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Ceil in a BST find karne ka code hai ye
        Node *temp = root;
        while (temp)
        {
            // agar current node less than equal to hai key se toh right mein jaate jao
            if (temp->key <= key)
            {
                temp = temp->right;
            }
            // warna successor ko apne paas rakhlo and left mein move karna start kardo taaki
            // NULL par paunch jaao
            else
            {
                suc = temp;
                temp = temp->left;
            }
        }
        // floor in a BST find karne ka code hai ye
        temp = root;
        while (temp)
        {
            // agar current node greater than equal to hai key se toh left mein jaate jao
            if (temp->key >= key)
            {
                temp = temp->left;
            }
            // warna predecessor ko apne paas rakhlo and right mein move karna start kardo taaki
            // NULL par paunch jaao because right mein chalejaayenge toh greater nodes hi aayenge
            // key se
            else
            {
                pre = temp;
                temp = temp->right;
            }
        }
    }
};

// Problem : Remove BST keys outside given range GFG
class Solution
{
    // TC => O(N)   SC => O(height of tree)
public:
    Node *removekeys(Node *root, int l, int r)
    {
        if (!root)
            return NULL;
        // range se bahar ke nodes ko recursively eliminate karenge
        // agar root ka data l se less hai toh root ke right mein chalejaayenge
        if (root->data < l)
        {
            return removekeys(root->right, l, r);
        }
        // agar root ka data r se zyada hai toh root ke left mein chalejaayenge
        if (root->data > r)
        {
            return removekeys(root->left, l, r);
        }
        // postorder traversal ka use kar rahe hai
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        return root;
    }
};

// Problem : Delete nodes greater than k GFG
class Solution
{
    // TC => O(N)   SC => O(height of tree)
public:
    // Iski explanation exactly similar hai Remove BST keys outside given range GFG waale question ke
    Node *deleteNode(Node *root, int k)
    {
        if (!root)
            return NULL;
        if (root->data >= k)
        {
            root->right = NULL;
            return deleteNode(root->left, k);
        }
        root->left = deleteNode(root->left, k);
        root->right = deleteNode(root->right, k);
        return root;
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

// Problem : Check Mirror in N-ary tree GFG
class Solution
{
public:
    //   TC => O(e)     SC => O(e)
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        unordered_map<int, vector<int>> mp1, mp2;
        // simply dono vectors ke through traverse karke dono ke liye adjancy list bana lo
        for (int i = 0; i < 2 * e; i += 2)
        {
            mp1[A[i]].push_back(A[i + 1]);
            mp2[B[i]].push_back(B[i + 1]);
        }
        // ab ek map ke through traverse karke current element se jitne connected hai unka reverse
        // karke ye check karlo ki agar woh dusre adjancy list ke vector ke equal nahi hai toh
        // mirror tree nahi hai
        for (auto it : mp1)
        {
            reverse(it.second.begin(), it.second.end());
            if (it.second != mp2[it.first])
            {
                return false;
            }
        }
        return true;
    }
};

// Problem : Construct binary tree from parent array GFG
class Solution
{
public:
    // TC =>O(N)     SC => O(N)
    Node *createTree(int parent[], int N)
    {
        // indexes child ko show kar rahe hai and unki values parent ko
        Node *root = NULL;
        unordered_map<int, Node *> mp;
        // saare indexes ke through jao
        for (int i = 0; i < N; i++)
        {
            // pehle child and parent dono ko null consider kar lenge
            Node *child = NULL, *Parent = NULL;
            int childkivalue = i;
            int parentkivalue = parent[i];
            // agar child exist karta hoga toh child ka parent le aayenge
            if (mp.find(childkivalue) != mp.end())
            {
                child = mp[childkivalue];
            }
            // warna new child banakar usse child ki value de denge
            else
            {
                child = new Node(childkivalue);
                mp[childkivalue] = child;
            }
            // ab parent ko dekhenge agar root node hai toh parent value zero hogi
            if (parentkivalue == -1)
            {
                root = child;
            }
            // warna 2 case hai ya toh parent exist karta hoga ya phir parent bhi new node
            // banega and phir usko map mein daal denge
            else
            {
                if (mp.find(parentkivalue) != mp.end())
                {
                    Parent = mp[parentkivalue];
                }
                else
                {
                    Parent = new Node(parentkivalue);
                    mp[parentkivalue] = Parent;
                }
                // agar parent ka left null hai toh usme left ko daal denge warna right mein daal denge
                if (Parent->left == NULL)
                    Parent->left = child;
                else if (Parent->right == NULL)
                    Parent->right = child;
            }
        }
        return root;
    }
};

// Problem : Make binary tree from linked list GFG
// TC => O(N)   SC => O(N)
void convert(Node *head, TreeNode *&root)
{
    // agar linked list mein koyi node nahi hai toh root ko NULL karke return kardo
    if (!head)
    {
        root = NULL;
        return;
    }
    // queue ki help leni padegi taaki har level ke nodes ko apne paas rakh saken tree banane
    // ke piye
    queue<TreeNode *> q;
    // root ko queue mein push kardiya hai
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;
    // jab tak linked list khatam nahi hogi tab tak traverse karenge
    while (head)
    {
        // queue se nikal kar front node ko apne paas rakhlenge taaki usse tree ka node
        // bana saken and uska left and right node set kar saken
        TreeNode *curr = q.front();
        q.pop();
        TreeNode *leftNode = new TreeNode(head->data);
        curr->left = leftNode;
        q.push(leftNode);
        head = head->next;
        // agar head hai toh right node banayenge current node ke liye
        if (head)
        {
            TreeNode *rightNode = new TreeNode(head->data);
            curr->right = rightNode;
            q.push(rightNode);
            head = head->next;
        }
    }
}

// Problem : Function to convert binary tree to doubly linked list GFG
class Solution
{
    // TC => O(N)     SC => O(H)
public:
    // Hum 2 nodes ki help lenge taaki previous pointer ko track kar saken and hume linked list ka head miljaaye
    Node *prev = NULL;
    Node *head = NULL;
    // Simply hum inorder lagayenge
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        // left mein jaate jaao
        inorder(root->left);
        // inorder work : toh agar previous node NULL hai toh iska matlab head current root banega
        if (prev == NULL)
        {
            head = root;
        }
        // warna current node ke left mein previous node aayega and previous node ke right mein current node aayega
        else
        {
            root->left = prev;
            prev->right = root;
        }
        // ab current root ko previous node bana denge matlab agar visualize karoge toh iska matlab hum
        // linked list ke next node par jaayenge
        prev = root;
        // right mein jaate jaao
        inorder(root->right);
    }
    Node *bToDLL(Node *root)
    {
        inorder(root);
        return head;
    }
};

// Problem : Maximum Path Sum between 2 Special Nodes GFG
// Here special node is a node which is connected to exactly one different node.
class Solution
{
    // TC => O(N)    SC => O(H)
public:
    int helper(Node *root, int &maxSum)
    {
        // agar leaf node hai toh uski value ko return kardo
        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }
        // agar sirf left node hai toh left mein jao and root ke data ko add karte raho
        if (root->right == NULL)
        {
            return (helper(root->left, maxSum)) + (root->data);
        }
        // agar sirf right node hai toh right mein jao and root ke data ko add karte raho
        if (root->left == NULL)
        {
            return (helper(root->right, maxSum)) + (root->data);
        }
        // left mein jaate jao and phir right mein jaate jao
        int l = helper(root->left, maxSum);
        int r = helper(root->right, maxSum);
        // childs ke through root mein add karke maximum sum milega
        maxSum = max(maxSum, l + r + root->data);
        // ya phir left side and right side se maximum answer milega
        return (max(l, r) + (root->data));
    }
    int maxPathSum(Node *root)
    {
        int maxSum = INT_MIN;
        int ans = helper(root, maxSum);
        // agar left and right dono hi NULL hai toh maximum le lo maxSum and ans ka
        if (root->left == NULL || root->right == NULL)
        {
            maxSum = max(maxSum, ans);
        }
        return maxSum;
    }
};

// Problem : Check Tree Traversal GFG
class Solution
{
    // TC => O(N^2)    SC => O(N)
public:
    bool checktree(int preorder[], int inorder[], int postorder[], int n)
    {
        // agar ek bhi node nahi bacha hai toh return true
        if (n == 0)
            return true;
        // agar sirf ek hi node reh gaya hai toh ye dekho ki teeno traversals mein woh node same hai ya nahi
        if (n == 1)
        {
            if (preorder[0] == inorder[0] && inorder[0] == postorder[0])
                return true;
            else
                return false;
        }

        // preorder mein jo pehla element hoga usse inorder mein dhundo because wahi root hoga
        int idx = -1, f = 0;
        for (int i = 0; i < n; ++i)
            if (inorder[i] == preorder[0])
            {
                idx = i;
                break;
            }
        // agar inorder mein element milgaya hai toh preorder ke first element ko dhundo postorder
        // traversal mein konse index par hai
        if (idx != -1)
        {
            for (int i = 0; i < n; i++)
                if (preorder[0] == postorder[i])
                {
                    f = 1;
                    break;
                }
        }
        // agar preorder ka first element inorder ya postorder mien se kisi mein bhi nahi mila hai
        // toh iska matlab hai ki trees same nahi hai traversals mein
        if (idx == -1 || f == 0)
            return false;

        // Ab left subtree mein check karenge and preorder ke index ko badha denge
        bool ret1 = checktree(preorder + 1, inorder, postorder, idx);

        // Ab right subtree mein check karenege jisme preorder ki value ko index + 1 kardenge because idx woh
        // index hai jahan par hume preorder ka first element inorder mein mila tha and inorder ke liye
        // bhi same yehi karenge and postorder mein sirf index ko hi add karenge and n ki value ab hogi
        // n-index-1 jo ki right subtree ko represent kar raha hoga
        int ret2 = checktree(preorder + idx + 1, inorder + idx + 1, postorder + idx, n - idx - 1);

        // return 1 only if both of them are correct else 0
        return (ret1 && ret2);
    }
};

// Problem : Merge two BST's GFG
class Solution
{
    // TC => O(M+N)
    // SC => O(Height of BST1 + Height of BST2 + M + N(for storing the answer))
public:
    // inorder traversal code
    void inorder(Node *root, vector<int> &bst)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, bst);
        bst.push_back(root->data);
        inorder(root->right, bst);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        // inorder traversal ko store kar lenge dono trees ke and phir two pointers ki help
        // se hum ek sorted vector ko create kar lenge
        vector<int> BST1;
        vector<int> BST2;
        vector<int> merged;
        inorder(root1, BST1);
        inorder(root2, BST2);
        int n = BST1.size();
        int m = BST2.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (BST1[i] <= BST2[j])
            {
                merged.push_back(BST1[i]);
                i++;
            }
            else
            {
                merged.push_back(BST2[j]);
                j++;
            }
        }
        while (i < n)
        {
            merged.push_back(BST1[i]);
            i++;
        }
        while (j < m)
        {
            merged.push_back(BST2[j]);
            j++;
        }
        return merged;
    }
};

// Problem : Largest BST GFG
class Solution
{
    // Brute Force Approach : Har node par jaake puch lo ki valid BST hai ya nahi
    // TC => O(N*N)
public:
    // Approach : Hum simply har node par uske left mein max kya hai and uske right mein minimum
    // kya hai ye track kar rahe hai and saath hi saath size ko bhi calculate karte rahenge
    // TC => O(N)   SC => O(Height of tree)
    vector<int> helper(Node *root)
    {
        // agar root NULL hojaayega toh left max hoga INT_MIN and right min hoga INT_MAX and size 0 hoga
        if (root == NULL)
        {
            return {INT_MIN, INT_MAX, 0};
        }
        // postorder traversal laga rahe hai
        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);
        // returned vectors mein left Max and right Min ko nikal rahe hai
        int leftMax = l[0];
        int rightMin = r[1];
        // agar left subtree ka max value chota hai root se and root chota hai right subtree ke minimum value se
        // toh hum return karenge {max(left,right,root),min(left,right,root),total size}
        if (leftMax < root->data && root->data < rightMin)
        {
            return {max({l[0], r[0], root->data}), min({l[1], r[1], root->data}), l[2] + r[2] + 1};
        }
        // agar BST hi nahi bana toh left se max INT_MAX hoga and right se min INT_MIN hoga and size left and right ka max hoga
        return {INT_MAX, INT_MIN, max(l[2], r[2])};
    }
    int largestBst(Node *root)
    {
        vector<int> ans = helper(root);
        return ans[2];
    }
};

// Problem : Shortest Range In BST GFG
class Solution
{
public:
    // TC => O(N)   SC => O(N)
    // approach bilkul similar hai Merge K sorted arrays/linked lists waale problems ki
    pair<int, int> shortestRange(Node *root)
    {
        // BFS lagakar tree ke saare levels ke nodes ko apne paas store kar lenge jinhe hum
        // arrays ki tarah treat karenge
        vector<vector<int>> v;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> t;
            while (size--)
            {
                root = q.front();
                q.pop();
                t.push_back(root->data);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            v.push_back(t);
        }
        int m = v.size();
        int mx = 0;
        // hume minimum range nikalni hai toh hume difference between start and end ko minimize karna hoga
        int s, e, diff = INT_MAX;
        // minimum priority queue le lenge jisme har level ke first node ko uske index and level number ke saath
        // priority queue mein daaldenge and saath hi saath har level ke initial nodes mein se maximum waale ko
        // apne paas rakh lenge
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < m; i++)
        {
            pq.push({v[i][0], i, 0});
            mx = max(mx, v[i][0]);
        }
        // ab merge sorted lists waala approach use karenge
        while (!pq.empty())
        {
            // {value,level,node index}
            int mn = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            // agar maximum and minimum ke beech ka difference less hai toh update karo difference, start and end ko
            if (mx - mn < diff)
            {
                diff = mx - mn;
                s = mn;
                e = mx;
            }
            // current level ke next node par jao
            j++;
            // agar current level ke nodes hi finish hogaye hai toh break
            if (j == v[i].size())
                break;
            // har baar maximum range ko update karte rahenge
            mx = max(mx, v[i][j]);
            // current node ko uske index and level ke saath priority queue mein push kardo
            pq.push({v[i][j], i, j});
        }
        return {s, e};
    }
};

// Problem : Maximum edge removal interviewbit
// TC => O(N)   SC => O(N)
int dfs(vector<vector<int>> &tree, int node, vector<int> &child, int parent)
{
    for (int i = 0; i < tree[node].size(); i++)
    {
        if (tree[node][i] == parent)
        {
            continue;
        }
        // child ko count karte jaayenge
        child[node] += dfs(tree, tree[node][i], child, node);
    }
    return child[node];
}
int helper(vector<vector<int>> &tree, int node, vector<int> &child, int parent)
{
    int count = 0;
    for (int i = 0; i < tree[node].size(); i++)
    {
        if (tree[node][i] == parent)
        {
            continue;
        }
        // agar child ka count even hai toh cut kar sakte hai
        if (child[tree[node][i]] % 2 == 0)
        {
            count++;
        }
        // subtree se bhi lekar aayenge answer
        count += helper(tree, tree[node][i], child, node);
    }
    return count;
}
int Solution::solve(int A, vector<vector<int>> &B)
{
    // simply hum dfs lagakar saare nodes ke paas unke child ka counts rakh lenge
    // phir hum ek ek node se puchenge ki kya woh cut kar sakte hai
    vector<vector<int>> tree(A + 1);
    for (int i = 0; i < B.size(); i++)
    {
        tree[B[i][0]].push_back(B[i][1]);
        tree[B[i][1]].push_back(B[i][0]);
    }
    // ek child vector le lenge and sabhi nodes ki value 1 kardenge jo ki uss node ko show kar raha hai
    vector<int> child(A + 1, 1);
    dfs(tree, 1, child, -1);
    return helper(tree, 1, child, -1);
}

// Problem : Pairs violating BST property GFG : Question GFG ke count inversions question ke exact same hi hai
// TC => O(NlogN)    SC => O(N)
int countMerge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low, res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];

            res += (n1 - i);
        }
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }

    return res;
}

int countInversion(vector<int> &arr, int low, int high)
{
    int res = 0;

    if (low < high)
    {
        int mid = low + (high - low) / 2;
        res += countInversion(arr, low, mid);
        res += countInversion(arr, mid + 1, high);
        res += countMerge(arr, low, mid, high);
    }

    return res;
}

void createArray(Node *root, vector<int> &arr)
{
    if (root)
    {
        createArray(root->left, arr);
        arr.push_back(root->data);
        createArray(root->right, arr);
    }
}

int pairsViolatingBST(Node *root, int n)
{
    vector<int> arr;
    createArray(root, arr);
    int res = countInversion(arr, 0, arr.size() - 1);
    return res;
}
