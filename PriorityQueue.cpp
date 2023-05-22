// Problem : Top k frequent elements LeetCode
class Solution
{
public:
    // Approach-1 : Simply max heap mein elements ko unki frequency ke saath put kardenge and phir max heap mein se k frequent elements ko final answer vector mein store kar lenge.
    // Time complexity : O(N) [map mein frequences count karne ke liye] + O(NLogN) [map se priority queue mein push karne ke liye] + O(N) [Agar worst case mein k=N hua toh priority queue se N elements pop honge] => O(NlogN) [overall time complexity]
    // Space complexity : O(N) [for map in worst case scenario] + O(N) [for priority queue in worst case] + O(N) [for final answer vector] => O(N) [overall space complexity]

    // Approach-2 : Using bucket sort
    // Hum kya karenge ki sabhi elements ki frequency ko map mein store karlenge and phir uske baad ek bucket lenge jiska har index frequency ko show kar raha hoga and is ke indexes par woh values hongi jinki frequency index ke equal hogi matlab
    // jitne index hoga agar utne hi frequency waala element hai toh usse us index ki values mein put kardo. Phir bucket mein se k elements ko nikal lo.
    // i => elements ki frequency
    // bucket[i] => elements jinki frequency i hai.
    // Time complexity : O(N) [map mein frequences count karne ke liye] + O(N) [bucket mein put karne ke liye elements ko] + O(N) [buckets mein se k elements ko nikal ke liye in worst case] = O(3N) => O(N) [overall time complexity]
    // Space complexity : O(N) [for map in worst case scenario] + O(N) [for bucket] + O(N) [for final answer vector] => O(N) [overall space complexity]
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        // simply unordered map mein elements ki frequency ko store kar rahe hai
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        // worst case mein ek element ki frequency n ho sakti hai toh hume bucket ka size n+1 lena hoga because kisi element ki frequency 0 toh mark karenge nahi and 1 se n tak hi frequency ho sakti hai
        vector<vector<int>> bucket(n + 1);
        for (auto it : mp)
        {
            // it.second ka matlab frequency
            // it.first ka matlab element
            bucket[it.second].push_back(it.first);
        }
        // final result ko send karne ke liye
        vector<int> mtFreq;
        for (int i = n; i >= 0; i--)
        {
            // agar kisi frequency ke liye koyi bhi element nahi hai toh baaki buckets ko dekhenge
            if (bucket[i].size() == 0)
            {
                continue;
            }
            // Agar current bucket mein elements hai toh unhe tab tak lo jab tak k ki value greater than 0 hai ya phir jab tak hamare bucket mein elements hai.
            while (bucket[i].size() > 0 && k > 0)
            {
                mtFreq.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return mtFreq;
    }
};