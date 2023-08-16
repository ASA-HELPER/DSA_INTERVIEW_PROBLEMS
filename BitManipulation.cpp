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