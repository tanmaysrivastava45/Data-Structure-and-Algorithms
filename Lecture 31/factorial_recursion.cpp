#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<"factorial of "<<n<<" is : "<<factorial(n);

}
// How It Works Internally (Step-by-Step Execution):

// Example: If the user inputs n = 5

// First Call (n = 5):
// The function factorial(5) is called.
// Since n != 0, the function calls factorial(4).

// Second Call (n = 4):
// The function factorial(4) is called.
// Since n != 0, it calls factorial(3).

// Third Call (n = 3):
// The function factorial(3) is called.
// Since n != 0, it calls factorial(2).

// Fourth Call (n = 2):
// The function factorial(2) is called.
// Since n != 0, it calls factorial(1).

// Fifth Call (n = 1):
// The function factorial(1) is called.
// Since n != 0, it calls factorial(0).

// Base Case (n = 0):
// The function factorial(0) is called.
// Since n == 0, it returns 1.

// Unwinding the Recursion:
// After reaching the base case (factorial(0)), the function calls start returning and the recursion "unwinds":

/* Return from factorial(1):
   factorial(1) returns 1 * 1 = 1 to factorial(2).

   Return from factorial(2):
   factorial(2) returns 2 * 1 = 2 to factorial(3).

   Return from factorial(3):
   factorial(3) returns 3 * 2 = 6 to factorial(4).

   Return from factorial(4):
   factorial(4) returns 4 * 6 = 24 to factorial(5).

   Return from factorial(5):
   factorial(5) returns 5 * 24 = 120.
*/

// Finally, the result 120 is printed as the factorial of 5.

// Execution Flow:
// Input: The user provides a number n (e.g., 5).
// Recursive Calls: The function repeatedly calls itself with decreasing values of n until it reaches 0.
// Base Case: Once n reaches 0, it returns 1, and the recursion starts unwinding, multiplying the values on each step.
// Output: The final result is printed.

// Output for n = 5:
// factorial of 5 is : 120

// Time Complexity:
// The time complexity of this recursive function is O(n) because it makes n recursive calls until it reaches the base case.

// Space Complexity:
// The space complexity is also O(n) due to the space required to store each recursive call in the function call stack.
