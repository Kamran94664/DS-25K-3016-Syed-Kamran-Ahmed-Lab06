#include <iostream>
using namespace std;

char grid[3][3] = {
    {'C', 'A', 'T'},
    {'X', 'Y', 'Z'},
    {'P', 'Q', 'R'}
};

bool visited[3][3] = {false};
string word = "CAT";

bool searchWord(int r, int c, int index)
{
    if (index == word.length())
        return true;

    if (r < 0 || r >= 3 ||
        c < 0 || c >= 3)
        return false;

    if (visited[r][c] || grid[r][c] != word[index])
        return false;

    visited[r][c] = true;

    if (searchWord(r, c + 1, index + 1) ||
        searchWord(r, c - 1, index + 1) ||
        searchWord(r + 1, c, index + 1) ||
        searchWord(r - 1, c, index + 1))
        return true;

    visited[r][c] = false;
    return false;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (searchWord(i, j, 0))
            {
                cout << "Word CAT found";
                return 0;
            }
        }
    }

    cout << "Word CAT not found";

    return 0;
}
