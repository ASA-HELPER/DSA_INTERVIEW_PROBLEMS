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

// Problem : Excel Sheet Column Title LeetCode
class Solution
{
public:
    // TC => O(logN)  SC => O(logN) hogi
    // Sabse pehle ek observation zaroori hai ki jab sirf single hai toh A to Z hi print hoga lekin jab multiple characters honge toh kya karenge?

    // Multiple characters ko observe karte hai like : AA , AB , AC . In teeno cases ko observe karte hai :

    // Sample-Case-1 : 'AA' iska columnNumber 27 hoga lekin kese : toh hume pata hai ki english mein total 26 characters hai jinhe counting ke base
    // par 1 to 26 numbers dete hai but coding mein agar dhyaan ho toh hum jab bhi koyi character ko represent karte hai toh wahan par 'a' or 'A' ko
    // 0 se represent karte hai and 'z' or 'Z' ko 25 par end karte hai. Bas issi cheez ka fayda uthana hai. Hum (27-1)%26 karenge toh hume jo remainder
    // milega usse hum 'A' mein add kardenge taaki hum woh number mile jo ki rightmost character hoga toh 26%26 = 0 hoga toh rightmost character hoga
    // 'A'+ 0  = A. Ab hum columnNumber=27 ko 26 se divide kardenge taaki previous character find kar paayen. columnNumber = (27-1)/26 = 1 hoga.
    // Ab ColumnNumber=1 hai toh remainder = (1-1)%26 = 0 hoga and yahan se hume next character 'A'+0 = 'A' miljaayega. Toh final answer hoga : 'AA'

    // Sample-Case-1 : 'AA'
    // ColumnNumber | Remainder      | Character    | Title
    //     27       | (27-1)%26 = 0  | ('A'+0) = A  |  A
    //(27-1)/26 = 1 | (1-1)%26 = 0   | ('A'+0) = A  |  AA

    // Sample-Case-2 : 'AB'
    // ColumnNumber | Remainder      | Character    | Title
    //     28       | (28-1)%26 = 1  | ('A'+1) = B  |  B
    //(28-1)/26 = 1 | (1-1)%26 = 0   | ('A'+0) = A  |  AB

    // Sample-Case-3 : 'AC'
    // ColumnNumber | Remainder      | Character    | Title
    //     29       | (29-1)%26 = 2  | ('A'+2) = C  |  C
    //(29-1)/26 = 1 | (1-1)%26 = 0   | ('A'+0) = A  |  AC

    // Ek example se dry run karke samjhte hai : columnNumber = 701
    // ColumnNumber   | Remainder      | Character    | Title
    //    701         |(701-1)%26 = 24 | ('A'+24) = Y |  Y
    //(701-1)/26 = 26 | (26-1)%26 = 25 | ('A'+25) = Z |  ZY

    string convertToTitle(int columnNumber)
    {
        int rem = 0;
        string title = "";
        while (columnNumber > 0)
        {
            // 1 ko subtract karne ka reason hi yehi hai ki hum coding scenario mein 'A' to 'Z' ko 0 to 25 represent karte hai
            rem = ((columnNumber - 1) % 26);
            title += ('A' + rem);
            columnNumber = (columnNumber - 1) / 26;
        }
        // reverse isliye karna zaroori hai because hum backward append kar rahe hai loop mein characters ko. Agar reverse nahi karna
        // chahate toh loop mein jo title waali line hai usse remove karke front appending karlo like this : title = ('A'+rem) + title
        reverse(title.begin(), title.end());
        return title;
    }
};

// Problem : Excel Sheet Column Number LeetCode
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int result = 0;
        for (char ch : columnTitle)
        {
            // Simply har baar ek character ko nikalo and uske correspoding number ko nikalo. 1 ko plus is liye kar rahe hai becuase coding
            // scenario mein 'A' to 'Z' ko 0 to 25 se represent kar rahe hai
            int d = ch - 'A' + 1;
            // character ke corresponding jo bhi nuber aayega usse pehle result ko 26 se multiply karna padega phir usme number ko add karenge.
            //  26 se multiply isliye because jesse decimal mein number form karne ke liye 10 se multiply karke phir number ko add karte hai
            // wese hi string of characters to number ke conversion mein 26 se multiply karke add karte hai number ko
            result = result * 26 + d;
        }
        return result;
    }
};