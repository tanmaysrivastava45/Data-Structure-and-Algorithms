#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 0;
        while (j < n)
        {
            char alpha = 'A' + i + j - 1;
            cout << alpha;
            j++;
        }
        cout << endl;
        i++;
    }
}
//output
// ABC
// BCD
// CDE