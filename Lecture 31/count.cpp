#include<iostream>
using namespace std;

// this is tail recursion
int print(int n)
{
    // base case
    if(n==0)
    {
        return 0;
    }

    // processing
    cout<<n<<endl;

    // recursive relation
    return print(n-1);
}


// this is head recursion
// void print(int n)
// {
//     // base case
//     if(n==0)
//     {
//         return;
//     }

//     // recursive relation
//     print(n-1);

    
//     // processing
//     cout<<n<<endl;

// }
int main()
{
    int n;
    cin>>n;
    print(n);
}
// this is how head recursion functions 
/*
// Recursion Flow for n = 3

n = 3
  -> Call print(2)
    n = 2
      -> Call print(1)
        n = 1
          -> Call print(0)
            n = 0
            -> Base case reached, return
          print(1)
        Return to n = 2
      print(2)
    Return to n = 3
  print(3)

// Function Call Stack
main() {
  print(3);
}

print(3) {
  print(2) {
    print(1) {
      print(0) {
        // Base case (n = 0)
        return;
      }
      print(1);
    }
    print(2);
  }
  print(3);
}

// Output:
3
2
1
*/