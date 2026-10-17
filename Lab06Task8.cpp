#include <iostream>
using namespace std;

void permute(string s, int start)
{
    if (start == s.length())
    {
        cout << s << endl;
        return;
    }

    for (int i = start; i < s.length(); i++)
    {
        swap(s[start], s[i]);

        permute(s, start + 1);

        swap(s[start], s[i]);
    }
}

int main()
{
    string s = "ABCD";

    permute(s, 0);

    return 0;
}
