/*


* if you want to calculate no.of digits in an number simply write int x=to_string(n).length();
* 
// for removing same element from a vector 
Certainly! The line of code find(ans.begin(), ans.end(), nums[i]) == ans.end() 
is used to check whether a specific element (nums[i] in this case) is already present in the vector ans. Here’s a breakdown:
The syntax is find(start_iterator, end_iterator, value), where:
start_iterator is the beginning of the range to search.
end_iterator is the end of the range to search.
value is the value to find in the range.

////////////////////////////////////////////////
optimised method for finding gcd of 2 numbers
 while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;


//////////////////////////////////////
for deleting duplicate no. or words from a vector
 // Sort the vector to bring duplicates together
    std::sort(words.begin(), words.end());
    
    // Use std::unique to remove consecutive duplicates
    auto last = std::unique(words.begin(), words.end());
    
    // Resize the vector to remove the "extra" elements after unique()
    /words.erase(last, words.end());

//////////////////////////////////////

check out the question 1346[leetcode] 
where when we will try to optimise the code 
we use the built in binary_search function 
[bool binary_search(InputIterator first, InputIterator last, const T& value);]
also we combined it with find function to check whether it exist 
InputIterator find(InputIterator first, InputIterator last, const T& value);

//////////////////////////////////////////
problem-796 in leetcode stl of string where substring of is intended to find in a particular string..

/////////////////////////////////////////////////

problem no.3163 teaches a lot make sure to check out also teaches about string

/////////////////////////////////////////////////

 while declaring an array of variable size make sure to allot it using dynamic memory 
 int *arr=new int[n];
 like this if want to explore more checkout lecture 28;

//////////////////////////////////////////////////

in order to learn about xor questions you should visit q-1829
properties of xor : 

XOR Properties:

1. Self-Inverse Property:
   a ^ a = 0
   - XORing a number with itself results in 0.

2. Identity Property:
   a ^ 0 = a
   - XORing a number with 0 returns the number itself.

3. Commutative Property:
   a ^ b = b ^ a
   - The order of XOR does not matter.

4. Associative Property:
   (a ^ b) ^ c = a ^ (b ^ c)
   - The grouping of XOR operations does not affect the result.

5. Double XOR (Involution Property):
   (a ^ b) ^ b = a
   - XORing a number twice with the same value returns the original number.
   - Useful for encoding and decoding.

6. XOR with All Bits Set:
   a ^ (2^n - 1)
   - XORing with all bits set (e.g., 111...1) inverts all bits in `a`.
   - This is equivalent to getting the bitwise complement of `a` for `n` bits.

7. Finding the Missing Element:
   - Given an array with numbers from 1 to n (or 0 to n), XORing all elements with the expected sequence finds the missing number.
   - Due to the canceling effect of XOR, duplicates are canceled out, leaving the missing number.

8. Toggle Specific Bit:
   - To toggle the k-th bit of a number `n`, use:
     n ^ (1 << k)
   - This flips only the k-th bit, keeping all others unchanged.

Summary of Key Properties:
- Self-Inverse: a ^ a = 0
- Identity: a ^ 0 = a
- Commutative: a ^ b = b ^ a
- Associative: (a ^ b) ^ c = a ^ (b ^ c)
- Double XOR: (a ^ b) ^ b = a

////////////////////////////////////////////////////////

Concepts for "Minimum Array End" Problem (Problem 3133)
--------------------------------------------------------

1. Bitwise AND (&):
   - The AND operation compares two numbers bit by bit.
   - Each bit in the result is set to `1` only if both corresponding bits in the operands are `1`.
   - In this problem, the requirement that the AND of all elements in `nums` equals `x` 
     means each element in the array must contain all the bits set in `x`.

2. Bitwise OR (|):
   - The OR operation compares two numbers bit by bit.
   - Each bit in the result is set to `1` if at least one of the corresponding bits in the operands is `1`.
   - We use `|` with `(num + 1) | x` to ensure that each new number includes the bits of `x`, 
     while also being the smallest number that is greater than the previous number.

3. Efficient Sequence Generation with `(num + 1) | x`:
   - This expression creates the next valid number in the sequence without incrementing one by one.
   - `(num + 1)`: Increments the current number to ensure the next number is greater.
   - `| x`: Forces the new number to contain all bits that are set in `x`.
   - This skips invalid numbers and is more efficient than a simple increment, 
     helping to avoid Time Limit Exceeded (TLE) errors.

4. Constructing Increasing Sequences with Specific Bit Patterns:
   - By using the above bit manipulation techniques, we can construct an increasing sequence 
     where each element respects both the strictly increasing requirement and the bitwise AND condition.
   - This approach minimizes the value of the last element by directly calculating each number, 
     rather than testing each one, which makes it optimal for large `n`.

Summary:
--------
- The solution leverages bitwise operations to construct an efficient sequence that 
  maintains specific bits (those in `x`) while ensuring each number is greater than the last.
- This approach optimally builds the array without checking each possible integer, 
  making it effective even for larger values of `n`.



////////// to convert vector char to string ////////////////////
string str(ans.begin(), ans.end());


/////////////////////////////////////////////////////////////////////////////////////////////////////
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
||||||||||||||||||||||||||||||||||||||CODECHEF STARTERS 165 |||||||||||||||||||||||||||||||||||||||||||||
PROBLELM - 4 --  USUALLY I DON'T KNOW HOW TO SOLVE THIS KIND OF PROBLEM BUT I CAN SOLVE JUST REMEMBER THIS 



#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int z=0;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')z++;
        else{
            o++;
        }
    }
    if(n%2==0)
    {
        if(z!=o)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            int eksathz=0;
            int eksatho=0;
            for(int i=1;i<n;i++)
            {
                if(s[i]==s[i-1] && s[i]=='0')
                {
                    eksathz++;
                }
                else if(s[i]==s[i-1] && s[i]=='1')
                {
                    eksatho++;
                }
            }
            if(max(eksatho,eksathz)>=2 )
            {
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
        
    }
    else if(n%2!=0)
    {
        if(min(o,z)!=max(o,z)-1)
        {
            cout<<"NO"<<endl;
        }
        else {
             int eksathz=0;
            int eksatho=0;
            for(int i=1;i<n;i++)
            {
                if(s[i]==s[i-1] && s[i]=='0')
                {
                    eksathz++;
                }
                else if(s[i]==s[i-1] && s[i]=='1')
                {
                    eksatho++;
                }
            }
            if(max(eksatho,eksathz)>=2 )
            {
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }
}
}

/////////////////////////////////// if unique elements are to be returned /////////////////////////////////////

sort(result.begin(),result.end());
auto last=unique(result.begin(),result.end());
result.erase(last,result.end());

////////////////////////////////// if statement shocking fact //////////////////////////////////////////////
if(i>0 && arr[i]==arr[i-1])
{
}
this is not same as 
if(arr[i]==arr[i-1] && i>0)
{
}



/////////////////////////////// BACK STL IN vector ////////////////////////////////////
q) 56 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>> ans;

        // Step 1: Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end());

        // Step 2: Iterate through the intervals
        for (const auto& interval : intervals) {
            // If ans is empty or the current interval does not overlap with the last interval
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval); // Add the interval as is
            } else {
                // There is overlap, so merge intervals
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};



// gcd function follows euclidean algo 

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


















*/