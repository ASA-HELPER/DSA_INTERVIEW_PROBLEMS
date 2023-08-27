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

// Problem : Minimum days GFG
class Solution
{
public:
    int getMinimumDays(int N, string S, vector<int> &P)
    {
        int count = 0;
        // Simply hum ye check karenge ki jab tak current character and next character equal
        // hai tab tak and agar current character par ? nahi hai toh permutation se index leke
        // us index par S ke ? laga denge.
        // TC => O(N)    SC => O(1)
        for (int i = 0; i < N - 1; i++)
        {
            while (S[i + 1] == S[i] && S[i] != '?')
            {
                S[P[count++]] = '?';
            }
        }
        return count;
    }
    // Another Approach
    int getMinimumDays(int N, string S, vector<int> &P)
    {
        int count = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (S[P[i]] == S[P[i] + 1] || S[P[i]] == S[P[i] - 1])
            {
                count = i + 1;
            }
            S[P[i]] = '?';
        }
        return count;
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

// Problem : Transform String GFG
class Solution
{
    // TC => O(max(A.size,B.size))    SC => O(1)
public:
    // Hume ye bol rakha hai ki transformation ke liye A se character ko uske index se remove
    // karke starting mein rakhdo. Toh hum isme kya karenge ki pehle toh dono strings ke characters
    // ki frequency same hai ya nahi. Agar frequency same nahi hai toh transform nahi kar
    // sakte toh answer straight forward -1 hojaayega
    int transform(string A, string B)
    {
        if (A.size() != B.size())
        {
            return -1;
        }
        int n = A.size();
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[A[i]]++;
            mp[B[i]]--;
        }
        // agar frequency different hogi toh return -1
        for (auto it : mp)
        {
            if (it.second)
            {
                return -1;
            }
        }
        // Last se traverse karenge and ye dekhenge ki jahan bhi A and B ke characters different
        // huye wahan par ans ko increase karenge jo ki hamare number of transformations ko track
        // kar raha hoga and sirf string A ke hi pointer ko decrease karenge and agar dono
        // strings ke characters same hai toh dono ke pointers ko decrease karenge
        int i = n - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0)
        {
            while (i >= 0 && A[i] != B[j])
            {
                ans++;
                i--;
            }
            i--;
            j--;
        }
        return ans;
    }
};

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

// Problem : Remove consecutive characters Interviewbit
class Solution
{
    // TC => O(N)     SC => O(N)
    string removechars(string A, int B)
    {
        int n = A.size();
        int count = 1;
        // Hum ek vector le lenge taaki ye store kar saken ki ek particular character kitni baar consecutively aa raha hai
        vector<pair<char, int>> v;
        for (int i = 1; i < n; i++)
        {
            // agar character consecutively repeat ho raha hai toh count ko increase karte rahenge
            if (A[i] == A[i - 1])
            {
                count++;
            }
            // warna ye check karenge ki kya ye character B times aaya hai consecutively in string agar haan toh iska length 0 kardenge because hume
            // isse apne final answer mein nahi dena hai warna iski length ko apne paas rakhlenge and isse {character,length} ki form mein vector of
            // pair mein daaldenge and count ko phir se 1 kardenge
            else
            {
                int len;
                if (count == B)
                    len = 0;
                else
                    len = count;
                v.push_back({A[i - 1], len});
                count = 1;
            }
        }
        // Ye last character ke liye hai  ki agar last character ki agar last character taak conseceutively chalta raha loop toh usse out of loop
        // add karna padega vector mein us character ki length ke saath
        v.push_back({A[n - 1], count % B});
        string ans = "";
        // ab vector mein se character ko aur uske length ko lekar har character ko uski length times string mein append karte jaayenge
        for (auto x : v)
        {
            for (int i = 0; i < x.second; i++)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

// Problem : Bulls and Cows LeetCode
class Solution
{
public:
    // TC => O(2N)    SC => O(1)
    // Question mein bulls ka matlab hai woh digits jo ki apni correct position par guess mein according to secret and cows ka matlab woh digits
    // jo ki secret mein hai lekin correct position par nahi hai guess mein
    // Is case par dry run karna : Secret = "1122"  Guess = "1222" iska answer hai : "3A0B"
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        // Hum simply ek vector le lenge 10 size ka because digits 0 to 9 hoti hai
        vector<int> digits(10, 0);
        int bulls = 0;
        int cows = 0;
        // First traversal mein hum number of bulls ko count karlenge agar current position par digit secret mein and guess mein same hai warna
        // digits waale vector mein digit ke count ko increase kardenge because ye woh digit hai jo ki secret mein hai but guess mein correct
        // position par nahi hai
        for (int i = 0; i < n; i++)
        {
            int num = int(secret[i] - 48);
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                digits[num]++;
            }
        }
        // Second traversal mein hum number of cows ko count karlenge agar current position par digit secret mein and guess mein same nahi hai and
        // digits waale vector mein current digit ka count greater hai zero se and saath hi saath hum current digit ke count ko digits waale vector
        // se decrease karte jaayenge
        for (int i = 0; i < n; i++)
        {
            int num = int(guess[i] - 48);
            if (secret[i] != guess[i] && digits[num] > 0)
            {
                cows++;
                digits[num]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

// Problem : Minimum characters to be added at front to make string palindrome in O(N) GFG
class Solution
{
    // Brute Force Approach :
    // Start checking the string each time if it is a palindrome and if not, then delete the last character and check again. When the string gets
    // reduced to either a palindrome or an empty string then the number of characters deleted from the end till now will be the answer as those
    // characters could have been inserted at the beginning of the original string in the order which will make the string a palindrome.
    // TC => O(N*N)     SC => O(1)
public:
    // Test case for dry run : tcitkg       Answer : 5
    // LPS ka concept use karna padega jiski help se hum longest prefix nikalenge reversed string ka jo ki longest suffix hoga given string ka jo ki ye
    // show karega ki itne characters jo hai woh apni correct position par hai. And inhe remove kardenge original string se toh bach jaayenge characters
    // string mein utne hi characters chahiye honge string ko palindrome banane mein
    // Same code hai LPS ka
    // TC => O(N)    SC => O(N)
    // For string = AACECAAAA
    // Concatenated String = AACECAAAA$AAAACECAA
    // LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
    vector<int> lps(int n, string s)
    {
        int i = 1, j = 0;
        vector<int> ans(n, 0);
        while (i < n)
        {
            if (s[i] == s[j])
            {
                ans[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = ans[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
    int minChar(string str)
    {
        // Hum given string ko reverse karke usme '$' ko append karke usme original string ko append kardenge
        // And phir newly created string ke liye Longest prefix suffix nikalenge
        int n = str.length();
        string s = str;
        reverse(str.begin(), str.end());
        string new_s = s + '$' + str;
        vector<int> lps_ans = lps((2 * n + 1), new_s);
        return n - lps_ans[2 * n];
    }
};

// Problem : Longest Prefix Suffix GFG
class Solution
{
    // KMP Algorithm use karna hai isme.
    // TC => O(N)    SC => O(N)
public:
    int lps(string s)
    {
        int n = s.size();
        int i = 1, j = 0;
        // ek lps vector ko create karte hai and iski values ko update karte huye jo final answer aata hai Nth position mein wahi answer hoga
        vector<int> lps(n, 0);
        while (i < n)
        {
            // agar ith and jth position par jo character hai woh same hai toh current ith position par j+1 value put karenge and i and j dono
            // ko increase karenge
            if (s[i] == s[j])
            {
                lps[i] = j + 1;
                i++;
                j++;
            }
            // agar ith and jth position par jo character hai woh same nahi hai toh ye dekhna hoga ki kya j 0 hai agar haan toh ith position
            // par lps ki value 0 hojayegi warna j ki value lps[j-1] hojayegi
            else
            {
                if (j == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return lps[n - 1];
    }
};

// Case Specific Sorting of strings GFG
class Solution
{
    // Question simply yeh keh raha hai ki jahan par bhi lowercase letters hai unhe sort kardo and jahan par bhi upper case characters hai
    // unhe sort kardo but given string mein jo ordeering ko change kiye bina.
    // Hum simply saare lowercase characters ko ek string mein store kar lenge and saare uppercase characters ko ek string mein store karlenge
    // Phir dono strings ko sort kardenge and simply second traversal mein given string ke lowercase letters ki jagah lowercase letters ko
    // sorted form mein put karenge and uppercase letter ki jagah uppercase letters ko put karenge
    // TC => O(2NlogN)   SC => O(N)
public:
    string caseSort(string str, int n)
    {
        string lower = "";
        string upper = "";
        for (int i = 0; i < n; i++)
        {
            if (islower(str[i]))
            {
                lower += str[i];
            }
            else
            {
                upper += str[i];
            }
        }
        // lowercase characters ke string ko sort karlenge
        sort(lower.begin(), lower.end());
        // uppercase characters ke string ko sort karlenge
        sort(upper.begin(), upper.end());
        int l = 0;
        int u = 0;
        // simply given string ko traverse karenge and lowercase character and uppercase character waale string se given string ko update karenge
        for (int i = 0; i < n; i++)
        {
            if (islower(str[i]))
            {
                str[i] = lower[l++];
            }
            else
            {
                str[i] = upper[u++];
            }
        }
        return str;
    }
};

// Problem : Make array elements unique
class Solution
{
public:
    //   TC => O(NlogN)     SC => O(1)
    long long int minIncrements(vector<int> arr, int n)
    {
        // Simply sort kardenge taaki saare elements ko increasing order mein unique kar paayen
        sort(arr.begin(), arr.end());
        long long int count = 0;
        for (int i = 1; i < n; i++)
        {
            // agar previous element greater ho jaata hai current se toh hum
            // number of operations ko count karlenge ki previous se greater banane mein
            // current number ko kitne operation lagenge. For example [4,5,3] hai toh 3 ko
            // 5 se greater banane ke liye (5-3)+1 = 3 operations lagenge tabhi 3 ko 6 banayenge
            if (arr[i - 1] >= arr[i])
            {
                // Number of operations ko count kar rahe hai
                count += arr[i - 1] - arr[i] + 1;
                // bas current number ko previous ka greater bana do
                arr[i] = arr[i - 1] + 1;
            }
        }
        return count;
    }
};