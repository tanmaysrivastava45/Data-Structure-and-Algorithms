#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="srivastava";
    s[3]='\0';
    cout<<s;
    char arr[10]={'s','r','i','v','a'};
    arr[2]='\0';
    cout<<arr;

}

/*
The key differences between character arrays and strings are rooted in their structure, handling, and usage in programming. Here are some of the main differences:

1. Definition and Structure:
Character Array:
A character array is a sequence of characters stored in contiguous memory locations.
String:
A string is a sequence of characters that is treated as a single data type.
2. Memory Allocation:
Character Array:
The size of a character array is fixed at the time of declaration. If you declare an array of size 10, it will always occupy that amount of memory, even if fewer characters are stored.
Memory allocation is typically static (though dynamic allocation can be used in some cases).
String:
Strings in many modern programming languages are dynamic, meaning their size can change based on the content.
Memory is allocated and managed automatically, often using heap memory for dynamic allocation.
3. Mutability:
Character Array:
Character arrays are mutable; (e.g., arr[0] = 'A';).
String:
Strings can be immutable or mutable, depending on the programming language:
Immutable: In languages like Java and Python, strings are immutable. Once created, they cannot be changed. Any modification results in the creation of a new string.
Mutable: In C++, std::string is mutable, allowing direct modification of characters within the string.
4. Functionality:
Character Array:
Limited functionality; you often need to manually handle operations like concatenation, comparison, and length calculation using functions like strcat, strcmp, and strlen in C.
String:
Strings provide rich functionality out-of-the-box, including methods for concatenation, comparison, substring extraction, search, replace, and more.
5. Ease of Use:
Character Array:
Requires more manual management, such as handling the null terminator, ensuring there is enough memory, and using functions for common operations.
String:
Easier to use due to the abstraction provided by string classes or objects, which manage details like memory allocation and provide a wide range of utility methods.
6. Null Terminator:
Character Array:

Often requires a null terminator ('\0') to indicate the end of the string in languages like C.
String:

Strings do not require a null terminator to manage their length; the length is typically stored and managed internally by the string class or object.
7. Performance:
Character Array:

Can be faster in low-level operations where memory and processing control are critical, but with less safety and convenience.
String:

Often has more overhead due to dynamic memory management, but provides better safety and ease of use in high-level operations.

*/