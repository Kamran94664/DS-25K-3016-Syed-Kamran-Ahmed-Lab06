#include <iostream>
using namespace std;

int grid[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int r, int c, int num)
{
    for (int i = 0; i < 4; i++)
    {
        if (grid[r][i] == num ||
            grid[i][c] == num)
            return false;
    }

    int sr = (r / 2) * 2;
    int sc = (c / 2) * 2;

    for (int i = sr; i < sr + 2; i++)
    {
        for (int j = sc; j < sc + 2; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku()
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (grid[r][c] == 0)
            {
                for (int num = 1; num <= 4; num++)
                {
                    if (isSafe(r, c, num))
                    {
                        grid[r][c] = num;

                        if (solveSudoku())
                            return true;

                        grid[r][c] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main()
{
    if (solveSudoku())
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << grid[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists";
    }

    return 0;
}
