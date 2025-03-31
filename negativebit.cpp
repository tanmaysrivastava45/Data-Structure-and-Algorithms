#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string binary="";
    if ( n==0)
    {
        binary="0";
    }
    else{
        unsigned int num=static_cast<unsigned int>(n);// this line of code assigns or changes the original signed type to unsigned type
        while(num!=0)
        {
            int bit=num&1;
            binary=to_string(bit)+ binary;
            num=num>>1;
        }

    }
    cout<<binary;
}
