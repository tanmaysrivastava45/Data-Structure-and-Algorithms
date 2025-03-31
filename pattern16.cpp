#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    
    while (i <= n)
    {
        int j = 1;
        char ch = 'A' + i+j-2;
        while (j <= i)
        {
            
            cout << ch;
            ch++;
            j++;
        }
        cout << endl;
        i++;
    }
}
//output
// A
// BC
// CDE
// DEFG