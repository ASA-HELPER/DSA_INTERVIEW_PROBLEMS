// Problem: The celebrity problem GFG
class Solution
{
    // Approach-1 : Using graph : Isme hum 2 vectors le lenge ek indegree aur ek outdegree and matrix ke through loop karke sabhi persons ki indegree
    // and outdegree ko calculate karlenge and jis bhi person ki outdegree 0 hogi and indegree n-1 hogi wahi hamara celebrity hoga
    // TC => O(N^2)   SC => O(2N)

    // Approach-2 : Using Stack
    // TC => O(N)    SC => O(N)
public:
    // Hume 2 cases ka dhyaan rakhna hai bas :
    // case-1 : Celebrity kisi ko naa jaanta ho matlab us particular person ki whole row mein bas zeroes hi present ho
    // case-2 : Celebrity ko sab jaante ho matlab us particular person ke number waale column mein (n-1) 1's hone chahiye
    // because usse khud ko chodkar baaki sab person usko jaante honge
    // n = 3   M = {{0,0,0},{0,0,0},{0,0,0}}  is particular case mein koyi celebrity nahi hoga
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        // Simply hum stack mein saare persons ko daal denge
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        // Jab tak stack mein khali celebrity nahi reh jaata tab tak hum har baar 2 persons
        // ko stack se nikal kar puchenge ki dono mein se kon kisko janta hai
        while (st.size() > 1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            // agar first person second person ko jaanta hai toh second ko push kardenge
            // because celebrity toh kisi ko jaanta hi nahi hai toh first person celebrity
            // nahi ho sakta hai
            if (M[first][second])
            {
                st.push(second);
            }
            // agar second person first person ko jaanta hai toh first ko push kardenge
            // because celebrity toh kisi ko jaanta hi nahi hai toh second person celebrity
            // nahi ho sakta hai
            else
            {
                st.push(first);
            }
        }
        // stack mein jo bhi celebrity raha hoga uske index ko rakh lenge apne paas
        int ans = st.top();
        int ZeroCount = 0;
        // ab hum ye check karenge ki hamari algorithm se jo celebrity aaya hai woh kahin
        // kisi ko jaanta toh nahi and agar nahi jaanta hoga toh uske row mein saare zeroes
        // present hone chahiye
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                ZeroCount++;
            }
        }
        // Agar celebrity ki row mein saarer zero nahi hai iska matlab woh kisi ko jaanta
        // hai toh party mein koyi bhi celebrity nahi hoga
        if (ZeroCount != n)
        {
            return -1;
        }
        // ab agar celebrity kisiko nahi jaanta hai toh hume ye check karna hoga ki kya baaki
        // sab persons jo party mein hai woh celebrity ko jaante hai toh iske liye hume celeberity
        // ke column mein check karna hoga ki (n-1) 1's hai ya nahi
        int OneCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
            {
                OneCount++;
            }
        }
        // agar number of ones n-1 ke equal nahi hai toh iska matlab sab log celebrity ko nahi
        // jaante toh iska matlab hamari party mein koyi celebrity hai hi nahi
        if (OneCount != n - 1)
        {
            return -1;
        }
        return ans;
    }
};