// Problem : Count the reversals GFG
int countRev(string s)
{
    // TC => O(N)   SC => O(1)
    // agar string ka size odd hai toh kabhi bhi brackets balanced honge hi nahi toh reversals
    // karne ki zaroorat hi nahi hai seedha -1 return kardo
    if (s.size() % 2 == 1)
    {
        return -1;
    }
    // open brackets and close brackets ka count rakhne ke liye 2 variables le rahe hai
    int openbra = 0;
    int closebra = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        // agar open bracket milega toh increase kardo open bracket ka count
        if (s[i] == '{')
        {
            openbra++;
        }
        else
        {
            // agar abhi tak ek bhi open bracket ka count zero hai toh hi close bracket ko
            // count karenge
            if (openbra == 0)
                closebra++;
            // warna open bracket ke count ko decrease kardenge
            else
                openbra--;
        }
    }
    // observation based hai ye formula
    return ceil(closebra / 2.0) + ceil(openbra / 2.0);
}