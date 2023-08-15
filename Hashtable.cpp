// Problem : Find minimum number of Laptops required GFG
class Solution
{
public:
    // TC => O(NlogN) because har insertion ke liye ordered map logN time leta hai
    // SC => O(N)
    int minLaptops(int N, int start[], int end[])
    {
        map<int, int> mp;
        int i;
        // Simply starting times ki values ke count ko increment karenge
        // and endding times ki values ke count ko decrement karenge
        for (i = 0; i < N; i++)
        {
            mp[start[i]]++;
            mp[end[i]]--;
        }
        int maxi = 0;
        int count = 0;
        // ab ordered map hai toh saare times order mein hi honge as sorted array
        //  toh jesse hi starting time aayega toh positive number add hoga and jab ending
        // time aayega toh negative number add hoga jiski help se number of laptops ko track
        // kar paayenge
        for (auto x : mp)
        {
            count += x.second;
            maxi = max(count, maxi);
        }
        return maxi;
    }
};

// Problem : Count number of distinct elements in each contiguous subarray in O(N) time
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    map<long long, int> m;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long right = n - i;
        long long left = 1;
        if (m.count(ar[i]) == 1)
        {
            int ind = m[ar[i]];
            ind++;
            left = i - ind + 1;
        }
        else
            left = i + 1;
        ans += left * right;
        m[ar[i]] = i;
    }
    cout << ans << "\n";
    return 0;
}

// Problem : Count number of Subarrays with XOR K
int subarraysWithXorK(vector<int> a, int k)
{
    // TC => O(N) or O(NlogN) jo ki depend karta hai konsa map aap le rahe hai
    // Agar ordered map lenge toh O(NlogN) hogi worst case mein
    // Agar unordered map lenge toh worst case mein O(N^2) hogi warna O(N) hogi
    // SC => O(N)
    int n = a.size(); // size of the given array.
    int xr = 0;
    map<int, int> mp;
    // Ab hum 0 ko map mein put isliye kar rahe hai because agar koyi aesi situation aagayi starting mein hi like [3,3,1,0] jisme 3^3=0 hai lekin
    // hamare paas map mein toh 0 ke liye bydefault value zero hogi jiski wajah se hamara answr update hi nahi hoga isliye 0 ke liye hum 1 set karenge
    mpp[xr]++;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // Simply prefix XOR nikal rahe hai hum
        xr = xr ^ a[i];
        // Hum yahan kya kar rahe hai ki current prefix XOR se k ka XOR kardenge taaki agar utna subarray bach zaaye jiska XOR x hoga taaki hume
        // ye pata chal sake map se ki kitne subarray hai jinka XOR x hai and unhe hum apne result mein store kar saken
        // Basically hum ye check kar rahe hai ki kitne current i ki position tak kitne subarrays aese hai jinme k as XOR aa raha hai
        // Aesa samjho ki current position tak ka subarray hai uska XOR jo hai woh xr hai and usme ek subarray aesa hai jiske XOR k hai toh inki
        // help se hum us subarray ke XOR ko nikal lenge jiska XOR x hoga and phir us XOR ki frequency ko map se apne answer mein put karwa denge
        int x = xr ^ k;
        cnt += mp[x];
        // Current prefix XOR ko map mein put kardenge
        mp[xr]++;
    }
    return cnt;
}