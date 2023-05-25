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