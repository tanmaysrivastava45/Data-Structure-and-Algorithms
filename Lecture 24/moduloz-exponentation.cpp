#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int ans=1;
	while(n>0)
	{
		if(n%2!=0)
		{
			ans=(1ll*ans * (x%m))%m; 
		}
		x=(1ll*(x%m)*(x%m))%m;
		n=n/2;
	}
	return ans;
}

int main()
{
     int a,b,c;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b>>c;

    cout << "Answer is: " << modularExponentiation(a,b,c) << endl;

    return 0;
}