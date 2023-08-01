// Problem : Rotate Image LeetCode
class Solution
{
public:
    // Brute Force Approach : Simply ek new matrix le lenge jisme hum and uske last column se usse fil karna start karna start karenge.
    // Original matrix ki first row ko final matrix ki last column mein put kardenge, aese hi second row ke elements ko new matrix ke second
    // last column mein put kardenge.
    // Simply : new_matrix[j][n - i - 1] = Org_matrix[i][j];
    // TC => O(N*N)   SC => O(N*N)

    // Space Optimised Approach :
    // TC => O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
    // SC => O(1)
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        // Sabse pehle hum transpose karenge matrix ka
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // ab hum har row ko reverse karenge taaki hume final matrix mil sake
        for (int i = 0; i < n; i++)
        {
            // Har row reverse karne ke liye manually kar rahe hai reverse using swap function other simply in-built reverse function ko bhi laga
            // sakte hai har row par
            int left = 0;
            int right = n - 1;
            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};

// Problem : Set Matrix Zeroes Leetcode
class Solution
{
public:
    // Approach-1 : Pehli approach toh yehi hai ki mein seedha two for loops lagakar unke andar further loops ko lagaun jinki wajah se
    // TC => O(3*(N*M)) hojayegi  SC => O(1) hogi
    // Approach-2 : Isme hum better kya kar sakte hai ki ek columns and ek rows ke liye ek vector le len aur jis bhi position mein 0 aa raha hoga
    // us position par ke row and column ko un vectors mein mark karlo and phir baad second traversal mein un rows and columns ko 0 kardo.
    // TC => O(2*(N*M))   SC => O(N+M) hojayegi
    // Approach-3 : Hum kya karenge ki separate rows and columns ke vectors lene ki bajaye given matrix ke first column and first row ko hi consider
    // kar lenge jisse space optimize hojayega. Hum jab bhi zero milega toh hum current row and current column ke corresponding first row and first
    //  column ke cells ko mark kardenge. Ab problem yehi hai ki hum jab mark kar rahe honge toh [0,0] par jo value hogi woh column ke liye ho rahi
    // hai ya row ke liye ho rahi hai ye pehchane mein problem hogi toh iske liye hum ek separate variable le lenge column ko mark karne ke liye.
    void setZeroes(vector<vector<int>> &matrix)
    {
        // TC => O(2*(N*M))
        // SC => O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int colzero = 1;
        // sabse pehle hum jis bhi cell par zero mile us cell ke corresponding first row and first column ko mark kardenge and agar j = 0 hai toh uske
        // liye variable ko 0 mark kardenge
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        colzero = 0;
                    }
                }
            }
        }
        // ab hum first row and first column se 0's mark karna start karenge usinng first row and first column
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        // agar 0th cell ko zero mark kar rakha hai toh 0th row ke saare elements ko 0 mark kardenga
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        // agar colzero variable ko zero mark kar rakha hai toh iska matlab hume 0th column ke saare cells ko 0 mark karna hoga.
        if (colzero == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// Problem : Spiral Matrix Leetcode
class Solution
{
    // Time complexity : O(mn) because hum mn cells ko visit kar rahe hai.
    // Space complexity : O(mn) because hum mn cells ko store kar rahe hai apne 1D array mein.
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // ek 1D vector le lenge taake spiral form ko store kar saken
        vector<int> spiral;
        // number of rows
        int rows = matrix.size();
        // number of columnns
        int cols = matrix[0].size();
        // number of cells kitne visit hogaye ye count karne ke liye ek variable le lenge
        int countCells = 0;
        // hamare total cells matrix mein rows*columns ke barabar honge
        int totalCells = rows * cols;
        // 4 variables lenge taaki all four side ko traverse kar saken
        int startRow = 0;
        int startCol = 0;
        int endRow = rows - 1;
        int endCol = cols - 1;
        // jab saare cells visit nahi kar lete tab tak loop chalega
        while (countCells < totalCells)
        {
            // left to right traversal ke liye : Left to right traverse kar rahe hai toh row same rahegi and column ki value change hojayegi
            for (int i = startCol; countCells < totalCells && i <= endCol; i++)
            {
                spiral.push_back(matrix[startRow][i]);
                countCells++;
            }

            // kyunki humne current row ke saare cells ko visit kar liya hai toh hum next row par chale jaayenge and dusra reason isse increment karne ka ye hai ki hum rightmost cell ke element ko store kar chuke hai apne 1D array mein toh usse dubara nahi lena hai
            startRow++;
            // top to bottom traversal ke liye : top to bottom traverse kar rahe hai toh column same rahega and row ki value change hojayegi
            for (int i = startRow; countCells < totalCells && i <= endRow; i++)
            {
                spiral.push_back(matrix[i][endCol]);
                countCells++;
            }

            // kyunki humne current column ke saare cells ko visit kar liya hai toh hum next previous par chale jaayenge and dusra reason isse decrement karne ka ye hai ki hum bottom ke cell ke element ko store kar chuke hai apne 1D array mein toh usse dubara nahi lena hai
            endCol--;
            // right to left traversal ke liye : right to left traverse kar rahe hai toh row same rahegi and column ki value change hojayegi
            for (int i = endCol; countCells < totalCells && i >= startCol; i--)
            {
                spiral.push_back(matrix[endRow][i]);
                countCells++;
            }

            // kyunki humne current row ke saare cells ko visit kar liya hai toh hum next previous row par chale jaayenge and dusra reason isse decrement karne ka ye hai ki hum bottom ke cell ke element ko store kar chuke hai apne 1D array mein toh usse dubara nahi lena hai
            endRow--;
            // down to top traversal ke liye : bottom to top traverse kar rahe hai toh column same rahega and row ki value change hojayegi
            for (int i = endRow; countCells < totalCells && i >= startRow; i--)
            {
                spiral.push_back(matrix[i][startCol]);
                countCells++;
            }
            // kyunki humne current column ke saare cells ko visit kar liya hai toh hum next column par chale jaayenge and dusra reason isse increment karne ka ye hai ki hum leftmpst cell ke element ko store kar chuke hai apne 1D array mein toh usse dubara nahi lena hai
            startCol++;
        }
        return spiral;
    }
};

// Problem : Largest rectangle of 1s with swapping of columns allowed GFG
class Solution
{
public:
    // TC => O(R*(R+C))     SC => O(R*C)
    // Original   prefix matrix  sorted rows   Area
    // 0 1 0 1 0    0 1 0 1 0     0 0 0 1 1     2
    // 0 1 0 1 1    0 2 0 2 0     0 0 0 2 2     4
    // 1 1 0 1 0    1 3 0 3 1     0 1 1 3 3     6
    int maxArea(vector<bool> mat[], int r, int c)
    {
        // Sabse pehle hum simply prefix sum le lenge pure matrix ka top to bottom
        vector<vector<int>> cnt(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // agar first row hai toh usme toh usme hamesha matrix ki current value hi aayegi
                if (i == 0)
                {
                    cnt[i][j] = mat[i][j];
                }
                else
                {
                    if (mat[i][j] == 0)
                    {
                        cnt[i][j] = 0;
                    }
                    // count matrix ke previous row ke current index ki value ko add karna hoga har baar
                    else
                    {
                        cnt[i][j] = mat[i][j] + cnt[i - 1][j];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            // har baar ek row ko lekar usse sort karenge and uski minimum height nikal te rahenge jo ki matrix ki values hi honge
            // and is minimum height ko width se multiply karke area nikalte rahenge and width ko bhi 1 se increase karte rahenge
            // jesse jesse columns mein aage traverse karte rahenge
            sort(cnt[i].begin(), cnt[i].end());
            int minHeight = INT_MAX;
            for (int j = c - 1, width = 1; j >= 0; j--, width++)
            {
                minHeight = min(minHeight, cnt[i][j]);
                // kyunki row sorted hai toh ek baar agar 0 miljaaye toh break kardo pura row check karne ki zaroorat nahi hai because zeroes hi milenge
                if (minHeight == 0)
                {
                    break;
                }
                else
                {
                    int area = width * minHeight;
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};

// Problem : Row with max 1s
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> Arr, int n, int m)
    {
        // TC => O(N+M)
        // SC => O(1)
        // Simply yahan two pointers ka concept use kiya hai
        int row = 0;
        // first row ke last column se traverse karna start kaernge
        int col = m - 1;
        int maxRowIndex = -1;
        // agar current cell ki value 1 hai toh previous column par aayenge warna next row
        // par jaayenge.
        while (row < n && col >= 0)
        {
            if (Arr[row][col] == 1)
            {
                maxRowIndex = row;
                col--;
            }
            else
            {
                row++;
            }
        }

        return maxRowIndex;
    }
};