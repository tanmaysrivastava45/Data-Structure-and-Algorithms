#include<iostream>
using namespace std;

// void recursion (int source, int destination)
// {
//     cout<<source<<endl;
//     if(source==destination)
//     {
//         cout<<"aagye"<<endl;
//         return;
//     }
//     source=source +5;
//     recursion(source,destination);
// }

int recursion (int source , int destination)
{
    cout<<source<<endl;

    // base case
    if(source==destination)
    {
        cout<<"Arrived !"<<endl;
        return source;
    }

    // processing 
    source=source+5;

    //recursive relation
    return recursion(source,destination);
}

int main()
{
    int destination=45;
    int source=5;
    recursion(5,45);
}