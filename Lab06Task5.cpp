#include <iostream>
using namespace std;

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

int color[4] = {0};
string colors[] = {"", "Red", "Green", "Blue"};

bool isSafe(int v, int c)
{
    for (int i = 0; i < 4; i++)
    {
        if (graph[v][i] == 1 && color[i] == c){
		
            return false;
    	}
	}

    return true;
}

bool graphColoring(int v)
{
    if (v == 4)
        return true;

    for (int c = 1; c <= 3; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (graphColoring(v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

int main()
{
    if (graphColoring(0))
    {
        for (int i = 0; i < 4; i++)
            cout << char('A' + i) << " = "
                 << colors[color[i]] << endl;
    }
    else
    {
        cout << "No valid coloring exists";
    }

    return 0;
}
