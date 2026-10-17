#include <iostream>
#include <string>
using namespace std;

void reverseString(string s, int i)
{
    if (i == s.length()){
	
        return;
}
    reverseString(s, i + 1);
    cout << s[i];
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    reverseString(s, 0);

    return 0;
}
