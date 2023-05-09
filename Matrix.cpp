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