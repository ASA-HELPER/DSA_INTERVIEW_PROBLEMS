// Problem : Move all zeroes to end of array GFG
class Solution
{
    // Brute force : Simply zero mile toh usse erase kardo and number of zeroes ko count karke aage baad
    // jao and phir ek loop lagakar utne number of zeroes ko append kardo
public:
    // Time Complexity : O(N) because hum simply array ko hi baar traverse kar rahe hai using two pointers
    // Space Compllexity : O(1)
    void pushZerosToEnd(int arr[], int n)
    {
        int i = 0;
        int j = 1;
        while (j < n)
        {
            // agar zero milega toh hum aesa non-zero number same order mein dhundenge jiske saath hum 0 swap kar saken
            if (arr[i] == 0)
            {
                while (j < n && arr[j] == 0)
                {
                    j++;
                }
                // aesi condition aa sakti hai ki saare zeroes ho toh usme out of loop chala zayega toh swap tabhi karenge jab j<n ho
                if (j < n)
                    swap(arr[j], arr[i]);
                i++;
            }
            // agar ith position ka element zero nahi hai toh aage badho
            else
            {
                i++;
            }
            // j ko hamesha aage move karte rahenge taaki jab par swap karne par zero agaya ho toh aage move karte usse bhi remove kar saken
            j++;
        }
    }
};