#include <iostream>

using namespace std;

// Function to check if there is any queen already in the corresponding diagonal
bool checkDiagonal(int **arr, int x, int y, int n)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((((x-y) == (i-j)) || ((x+y) == (i+j))) && arr[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

// Function to check if there is any queen already in the column
bool checkColumn(int **arr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int **arr;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Setting all values in array as 0 initially
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;


    for (int i = 0, j = 0; ((i < n) && (j < n)); i++)
    {
        // Iterating through each element in a row
        for (int j = 0; j < n; j++)
        {
            if (checkDiagonal(arr, i, j, n) && checkColumn(arr, i, j)) // Putting queen if there's no queen already in the corresponding row or coulumn
            {
                arr[i][j] = 1;
                if (i == n-1)
                {
                    // If we are at the last row, then exit the program
                    return 0;
                }
                break; // Break condition to stop iterating through remaining elements in the row, after putting one queen
            }

            // When the iterator reaches end of the row, 
            // Go back to previous row to change the position of queen in that row
            if (j == n-1)
            {
                i -= 1;
                for (j = 0; arr[i][j] != 1; j++); // Iterating through elements in the previous row until we get 1 (queen).
                arr[i][j] = 0; // Removing the queen (Setting the value to be zero)
            }
        }
    }
    
    // Printing the resulting array.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
