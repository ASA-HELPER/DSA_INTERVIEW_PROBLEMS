// Problem : Bulb Switcher Leetcode
class Solution
{
    // TC => O(sqrt(n))    SC => O(1)
public:
    // Dry runn karne par pata chalega ki sirf wahi numbers reh jaayenge jinka square less than equal to n hoga
    int bulbSwitch(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int count = 0;
        for (int i = 1; i * i <= n; i++)
        {
            count++;
        }
        return count;
    }
};