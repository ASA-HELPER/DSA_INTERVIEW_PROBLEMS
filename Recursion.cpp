// Problem-1 : Sum of First N terms using recursion (GFG)
class Solution
{
public:
    long long helper(long long N)
    {
        // agar N less than 1 hoga toh 0 return kardenge
        if (N < 1)
        {
            return 0;
        }
        // har baar apne answer mein current N ki value ka cube add karke further recursion call se further N ki value ka result maangenge
        return N * N * N + helper(N - 1);
    }
    long long sumOfSeries(long long N)
    {
        // O(N) approach using recursion
        return helper(N);

        // O(1) Approach using mathematical formula
        // return (N*N*(N+1)*(N+1))/4;
    }
};