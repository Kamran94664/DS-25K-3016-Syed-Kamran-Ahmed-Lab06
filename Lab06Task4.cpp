#include <iostream>
using namespace std;

int savings(int n)
{
    if (n == 1){
	
        return 10;
}
    return 2 * savings(n - 1);
}

int main()
{
    int n;
    cout << "Enter the day: ";
    cin >> n;

    if (n < 1)
        cout << "Invalid day";
    else
        cout << "Amount = Rs. " << savings(n);

    return 0;
}
