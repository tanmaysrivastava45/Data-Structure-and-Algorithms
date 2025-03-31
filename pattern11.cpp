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
        while (j <= n)
        {
            char alpha='A'+j-1;
            cout<<alpha;
            j++;
        }
        cout<<endl;
        i++;
    }
}
//output
// ABC
// ABC
// ABC