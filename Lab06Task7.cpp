#include <iostream>
using namespace std;

int arr[] = {2, 3, 5, 6, 8};
int subset[5];
bool found = false;

void findSubset(int i, int sum, int count)
{
    if (sum == 9)
    {
        found = true;

        cout << "Subset: ";
        for (int j = 0; j < count; j++)
            cout << subset[j] << " ";

        cout << endl;
        return;
    }

    if (i == 5 || sum > 9)
        return;

    subset[count] = arr[i];
    findSubset(i + 1, sum + arr[i], count + 1);

    findSubset(i + 1, sum, count);
}

int main()
{
    findSubset(0, 0, 0);

    if (!found)
        cout << "No valid subset exists";

    return 0;
}
