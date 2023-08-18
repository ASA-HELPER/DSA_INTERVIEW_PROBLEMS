// Problem : Generate Grey Code Sequences
class Solution
{
    // Sabse pehle ye pata hona zaroori hai ki given N ke liye kitne grey code generate honge.
    // Toh N ke liye 2^N grey code generate hote hai
    // Yahan base case ka role sabse zyada hai. Hum given N se 1 ki taraf jaayenge because N hamara base case hai jiske liye grey code fix
    // hi rahega yaani "0" "1" . Toh issi ka fayda uthayenge hum.
    // Hum har baar previous N ke grey code sequences ko start se traverse karke unke front mein "0" append karenge phir last se traverse
    // karke "1" ko front mein append karenge and har baar apne answer vector mein push karte rahenge
    // For example : N = 2 toh pehle N = 1 ka nikalenge jo ki "0" and "1"
    // Ab inme pehle "0" ko front mein add karenge "00" and "01" hojayega and phir unme reverse mein "1" ko front mein add karenge "11" and
    // "10" hojayega. Toh N=2 ke liye grey code sequence hojayega : {"00","01","11","10"}
    // TC => O(N*2^N) because given N ke liye 2^N grey code sequences generate honge and kyunki har N ke liye nikal rahe hai from N to 1 toh
    // N se multiply hojayega.    SC => O(1) hoga agar recursive stack space ko consider nahi karenge toh
public:
    vector<string> generateCode(int N)
    {
        vector<string> v;
        if (N == 1)
        {
            v.push_back("0");
            v.push_back("1");
            return v;
        }
        vector<string> res = generateCode(N - 1);
        for (int i = 0; i < res.size(); i++)
        {
            v.push_back("0" + res[i]);
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            v.push_back("1" + res[i]);
        }
        return v;
    }
};

// Problem : Maximum Subset XOR GFG or Maximum XOR Subset GFG
class Solution
{
    // Brute-Force Approach yehi hogi ki hum recursion ka use karen using pick and non-pick ka use karen taaki har index ke paas choice hogi
    // ki usse maximum subset XOR mein include kiya jaayega ya nahi. TC => O(2^N) hogi and SC => O(2^N) hogi because of recursive stack
public:
    // TC => O(32*N) hogi and SC => O(1) hogi
    // Isme hum Gaussian elimination technique ko use karenge MSB ko uthayenge and agar woh 1 hai toh baaki sabhi numbers mein uss bit ko
    // 0 kardenge taaki ye MSB XOR lete waqt 0 naa hojaye. Hum har bit ke liye ye try karenge. Basically hum current MSB ko lekar ye dekhenge
    // ki array mein konsa aesa number hai jo ki maximum hai and jiski current MSB set hai. Taaki us max number ko current ith waale number se
    // swap kar saken. Swapping karne ke baad current number ko baaki sabhi numbers se XOR karna hoga jinki ith bit set hai except khud se.

    // Ek example se dry run dekhte hai : arr={1,4,5,12}  currIndex = 0,  bit = 4
    // currentIndex = 0, bit = 4 | currentIndex = 1, bit = 3 | currentIndex = 2, bit = 2 | currentIndex = 1, bit = 1 | currentIndex = 0,bit = 0
    // 1 = 0001                  |12 = 1100                  | 9 = 1001                  | 9 = 1001                  | 8 = 1000
    // 4 = 0100                  | 4 = 0100                  | 5 = 0101                  | 5 = 0101                  | 4 = 0100
    // 5 = 0101                  | 5 = 0101                  | 1 = 0001                  | 1 = 0001                  | 1 = 0001
    // 12 = 1100                 | 1 = 0001                  | 1 = 0001                  | 1 = 0001                  | 0 = 0000
    // Finally last mein saare elements ka XOR kardo taaki maximum XOR of a subset mil sake : 8^4^1^0 = 13 hi answer hai
    int maxSubsetXOR(int arr[], int n)
    {
        // Ye current index ko track karne ke liye jiske saath max element ko swap karna hoga
        int index = 0;
        // 32 bits hoti hai toh har bit ko check karna hoga
        for (int i = 31; i >= 0; i--)
        {
            int maxEle = INT_MIN;
            int maxIndex = index;
            // jis bhi element ki current ith bit set hai and woh maximum hoga current index se last tak usse apne paas rakh lenge
            for (int j = index; j < n; j++)
            {
                if ((arr[j] & (1 << i)) != 0 && arr[i] > maxEle)
                {
                    maxEle = arr[j];
                    maxIndex = j;
                }
            }
            // agar current index se last tak koyi aesa element nahi mila jiski current ith bit set hai toh next bit par chalejaayenge
            if (maxEle == INT_MIN)
            {
                continue;
            }
            // swapping kar rahe hai current index and current maximum elment ki
            swap(arr[index], arr[maxIndex]);
            // kyunki maximum element index par chala gaya hai toh maxIndex bhi index hi hojaayega
            maxIndex = index;
            // ab un sabhi elements ko maximum element ke saath XOR karenge jinki current bit set hai except maximum element ko khud se
            for (int j = 0; j < n; j++)
            {
                if (j != maxIndex && (arr[j] & (1 << i)) != 0)
                {
                    arr[j] = arr[j] ^ arr[maxIndex];
                }
            }
            index++;
        }
        // finally jo bhi modified array hume milega uska XOR lenge toh maximum subset XOR miljaayega
        int XOR = 0;
        for (int i = 0; i < n; i++)
        {
            XOR = XOR ^ arr[i];
        }
        return XOR;
    }
};