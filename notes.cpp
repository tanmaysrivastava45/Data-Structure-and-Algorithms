// jai shree Ganesh

// Lecture 1

// discussed about flowcharts and pseudocode

//---------------------------------------------------------------------------------------------------------------------------------------

// Lecture2

/*printing first program
datatypes and variables
1 byte=8bit
int-4byte
char-1byte
float-4byte
double-8byte
Q) how -ve no. are stored in computers?
Ans) by the method of 2's compliment
e.g -5=> 0000000000101
      => 1111111111010=>1's compliment
      =>+1
      => 1111111111011=>2's compliment

    the first digit here represents -ve no.

for data types if int/int data type =int
               if float/int data type =float
               if double/int data type =double

types of operators
arithmetic , relational, assignment,logical,bitwise,comparison,etc*/

//------------------------------------------------------------------------------------------------------------------------------------

// Lecture 3

/*
*cin generally ignores spaces , tab and enter
*to not ignore that we use cin.get()
*we can use if-else statement by two methods
*1)if()
   {)
   else
   {if()
   {}
   else{}
   }
*2)if ()
   {}
   else if()
   {}
   else{}

*for fahrenheit to celsius conversion
In the given code, writing 5.0 instead of 5 is important due to the way integer division and floating-point division work in C++
*pattern questions can be done through example.
*/

//-----------------------------------------------------------------------------------------------------------------------------------

// Lecture 4
/* pattern questions which can be seen in practice
there are several patterns we need to understand the basic idea that how pattern is working*/

//-----------------------------------------------------------------------------------------------------------------------------------

// Lecture 5

/*
--Bit wise operators (&,|,~,^)
  And,Or,NOT,XOR
  left shift(<<)
  multiply by 2power
  5<<1=5*2
  5<<2=5*2^2
  right shift(>>)
  divide by 2power
  17>>1=8
  8>>2=2
--inccrement/decrement
 >post incre/decrement
  i++
  i--
 >pre incre/decrement
 ++i
 --i
-->for(int i=0;i<n;i++)//-->initialization-->condition to check-->updation
we can use multiple variables also
{

}
**for loop is iterative while while loop is totally depends on the condition being true
**check prime no. code example to understand this
**variable used in a particular block is only valid for that block
**operator precedence has its particular table of operators but we will use paranthesis.

//-------------------------------------------------------------------------------------------------------------------------------------

/**Lecture 6 **\


--------->this is not working in code every time <--------------
for printing a number we have to use this formula;
--> ans = ( digit + 10^i ) + ans
example let make a from 4,5,6
let take ans =0
now ans = (4*10^0)+0=4
now ans = (5*10^1)+4=54
now ans =(6*10^2)+54=654

for printing reverse number using digits we use the formula;
-->ans=(ans*10)+digit
example let make a reverse no. from 4,5,6
let take ans =0
now ans = (0*10)+4=4
now ans = (4*10)+5=45
now ans =(45*10)+6=456
----------------> <-------------------------------------------
now for that we can check (bit.cpp) code

//-------------------------------------------------------------------------------------------------------------------------------------

/** LECTURE 7**\


solved three problems in leetcode

//-------------------------------------------------------------------------------------------------------------------------------------

/**Lecture 8**\


learned switch case visit switchcase.cpp
learned functions
-solved nCr problem
-prime no. problem
-power(a,b) problem
-even odd function

learned pass by refererce

homework
--APfunction.cpp
--funct_totalbits.cpp
--function_fibonacci.cpp

//-------------------------------------------------------------------------------------------------------------------------------------

/** LECTURE 9**\

If we need to print largest integer among 3 number we will simply make variables and provide certain condition ;
but what if i have 100's of number in that case we will use array

ARRAY
it stores multiple values in a single variable of similar data types
it stores data in a contiguous memory location

An array can be initialize using a particular value check (array_initializeParticularValue.cpp)

*array funtion can be seen in array_function.cpp
* how to get the maximum and minimum value in an array can be seen in array_max_min_element.cpp


----> In case of function when we make function if we declare a variable and make some changes in it ;
 it does not replicate in the main function while in case of array it gets update this is because
 in case of a function the variable box is copied while in case of array the address is shared which means
  that any changes in it will replicate in the main function also.<-------

* Linear Search
  checkout array_linearSearch.cpp

* reversing an array
 check out array_reverse.cpp

//-------------------------------------------------------------------------------------------------------------------------------------

/**Lecture 10**\

problem solving on array
//
swap fuction can be breakdown by using a temporary varaible to store the value
check out == array_swapalternate.cpp

* code ninja - problem to find unique element  in the list of array
-- XOR function a^a=0; a^0=a;

----> solved a lot of problems on array in platforms like leetcode and code ninjas
**these all problems can be viewed in the description of lecture 10**

//-------------------------------------------------------------------------------------------------------------------------------------

/**Lecuture 11**\

**+**Time complexity--it is the amount of time taken by algorithm to run and it is a function of time
constant time ->O(1);
linear time-> O(n);
logarithmetic time ->O(logn)
quadritic time -> O(n^2)
cubic time -> O(n^3)

---->big O notation order <-----
         ^
 O(N!)   |
 O(2^n)  |
 O(n^3)  |
 O(n^2)  |
 O(nlogn)|
 O(n)    |
 O(logn) |
 O(1)    |
------------------------
 for
 {
   for{    ( for this case time complexity = O(n^2))
     }
 }

 for
 {
 }
 for     (for this case time complexity = O(n)+O(n)
 {
 }

 -------------------
 space complexity - it is the space occupied by the memory to run the program
 for constant values it is O(1)
 while for uncertain n it is O(n)


<----------------------------------------------------------------------------------------------------------------------------------->
/** LECTURE 12 **\

Binary search :- we will calculate the mid index and then compare the value of array at mid index with the key that is to be searched
and if it key = arr[mid]
return mid;
if !=
then compare key>arr[mid]
then start=mid+1;
if key<arr[mid]
then end = mid-1;
and then we will update the mid value
as mid= start + (end-start)/2;

***** now remember one thing that mid = start + (end- start)/2
and not start + end/2
because of max limit of int is 2^31-1 to avoid test case failure;

-----> time complexity of binary search

for linear search we saw that it was checking every element so it was taking time complexity as O(N)
but that is not with the case of binary search in case of binary search the cases get reduced by the power of 2

N  ->  N/2  ->  N/2^2  ->....->  N/2^k

N/2^k= 1 (since it will be the last element )
therefore k=log(N);


for implementation check BinarySearch.cpp

<------------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 13**\

practice problems
1) find position of elements in first occurence and last occurence (binary search )
2) find total occurence
3) find peak mountain index also done in vs code check binarySearch_peakindex.cpp
// we could have done it through linear search by comparing it with intmin but the time complexity of that would be O(n) whereas for
  // below code it is O(logn)
4) find pivot index we can check the code at binarySearch_pivotindex.cpp

<----------------------------------------------------------------------------------------------------------------------------------->

/**Lecture 14**\

1) find the pivot integer
2) search in a rotated sorted array (problem-33)
3) sqrt of x(problem-69)
4) sqrt of x (in decimal)=sqrt.cpp

<------------------------------------------------------------------------------------------------------------------------------------>

/** Lecture 15 **\

1) books allocation problem - unable to find same problem but did the same like painters problem
2) painters problem -https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmE5c2xPTVBIZjNNVFhjMzJ4UlV5QnVSLWhIZ3xBQ3Jtc0trR2xsUE9uWUdLd2lqUjUyZW1NWjRJVWhtdDJ1SDlPcjJocXhGMlVLckRKcXZiaUVQbEtBY0tvMDVwa0pHWU9HMFpwNXZFa0VUd2RmM05PWU1UcWZXMXNQZkt0SkVlQ1JVWlBpUE9zdURoV3FrZjM0WQ&q=https%3A%2F%2Fbit.ly%2F31v3Jiy&v=YTTdLgyqOLY
3) aggressive cow question is also discused but we solved another type of same question in leetcode 410
4)split array question 410 also commited in github


<------------------------------------------------------------------------------------------------------------------------------------->

/**Lecture 16**\

Selection sorting : traversing through each element first fixing one element as minimum index and then comparing it with other
elements of the array

time complexity= O(n^2)
space complexity = O(1)
best case time complexity = O(n^2)
worst case time complexity = O(N^2)
for code visit- Sorting_SelectionSort.cpp
stable & unstable codes
stable code- like merge sort and bubble sort they did retain the original order of the element
unstable code - like selection sort and quick sort the did not guarantee you that it will retain its order or not;

<-------------------------------------------------------------------------------------------------------------------------------------->


/** LECTURE 17**\

Bubble sorting :
in this type off sorting we will we be comparing the adjacent elements and will be swapping accordingly

time complexity :O(n^2)
space complexity :O(1)
best case time complexity = O(n)
--- for best case we will be using break statement to exit the loop as i did in question no 75 3rd submission
worst case complexity = O(n^2)
for code visit - Sorting_BubbleSort.cpp
it is an stable code


<-------------------------------------------------------------------------------------------------------------------------------------->

/**Lecture 18**\

Insertion sort:
like card example inserting according to sorting
time complexity :O(n^2)
space complexity :O(1)
best case time complexity = O(n)
worst case complexity = O(n^2)
for code visit - Sorting_InsertionSort.cpp
it is an stable code



<-------------------------------------------------------------------------------------------------------------------------------------->


/** Lecture 19 **\

---> C++ STL (Standard Template Library) <----
link=https://drive.google.com/file/d/1vVxvwFvQUxbLTQm0SZ_zEy18xLVPeERV/view
link=https://whimsical.com/c-stl-XVxuHHof5GTWA4NXZhXQhx

 will look more into this STL through striver series also for the time being vectors and pair are done;


<-------------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 20**\

1) completed question of reversing array with the help of vector STL visit lecture 20 folder
2) merge sorted array (lecture 20.cpp)
3) move zeroes.

<-------------------------------------------------------------------------------------------------------------------------------------->
/**Lecture 21**\

1) Rotate array problem lecture 21.cpp
2) check if array is sorted and rotated lecture 21.cpp
3) sum 2 array lecture 21.cpp
4) check out q-989 on leetcode
5) also check q-66 on leetcode similar to 989.

<-------------------------------------------------------------------------------------------------------------------------------------->

/**Lecture 22**\

 Char array is used to store multiple char character and syntax is :
 char name[];\
 for input write cin>>name;
 it stores a null vector whenever there is a
 --> space, tab, enter ;
 while when it stores in the arrays at the end of the arrays a null vector is stored "\0";

char array vs string (string_vs_chararray.cpp)
ispalindrome questions are very good check out its two methods in lecture 22;

reversewords.cpp
maximumoccur.cpp
replacespaces.cpp


<--------------------------------------------------------------------------------------------------------------------------------------------->

-----------------------------------------------------------------resume--------------------------------------------------------
/** LECTURE 23 **\

introduction to 2d array and initialization and all
***** important thing *****
if printing 2d array then remember if we want to print row wise then do run first loop row and second loop of column but do fix the structure of
arr[row][column] and if printing column wise then remember to chan first loop column and second loop row but keeping the arr[row][column] fixed
1) 2darrayintro.cpp
2) waveprint.cpp
********************3) spiral.cpp*****************(extremely important)(question-54)
4)rotateimage.cpp
5)search a 2d matrix.cpp
6) search a 2d matrix II.cpp(important question)

<----------------------------------------------------------------------------------------------------------------------------------->
/**LECTURE 24**\

***Sieve of erastothenes***
prefer seeing question-204) count primes

basically in this what we do is we mark every no as prime no. but then
after one number is marked as prime then its multiple is marked as not prime numbers for obvious reasons
than it won't iterate all the elements and its time complexity will be reduced to
** O(n*log(log(n)))**

***Segmented sieve***

*****GCD******
gcd(a,b)=gcd(a-b,b)=gcd(a%b,b)
checkout gcd_of_two_no.cpp[time complexity of this code is O(min(x,y))]

****Euclid's algorithm for gcd ****
checkout euclid_gcd.cpp[time complexity is O[log(min(x,y))]]

LCM(a,b)*GCD(a,b)=a*b;
therefore lcm = a*b/gcd;

***** modulo arithmetic *****
basically here we have some functions of modulo operation which or some std modulo arithmetic rules checkout moduloexponentiation.cpp
First off, some important identities about the modulo operator:

(a mod m)+(b mod m)  mod m=a+b  mod m

(a mod m)−(b mod m)  mod m=a−b  mod m

(a mod m)⋅(b mod m)  mod m=a⋅b  mod m

//home work
pigeon hole based problem -- Q}287. Find the duplicate number
Q-172) factor-trailing zeroes


<----------------------------------------------------------------------------------------------------------------------------------->
/**LECTURE 25**\

POINTERS--
+ The pointer basically stores the address.

+ Whenever we are initializing a ptr make sure to give it a value since it will be a bad practice if we did not initialize the ptr with a
constant.

+ The datatype of ptr must be same as the data type of actual variable.

+ A pointer is a dereference operator.

+ The size of the pointer depends on the system whether it is 32 bit/ 64 bit
for 32 bit it is 4 and for 64 bit it is 8.

+ always add paranthesis in pointers
cout<<num<<endl;
(*ans)++;
cout<<num<<endl;

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 26 **\

For pointers in array remember that :
arr[i]=*[arr+i];
also remember that :
i[arr]=*(i+arr);

+++++++++++ size ++++++++++++
1) array - no.of block *4;
2) pointer - for 32 bits-4 bytes and for 64 bits -8 bytes


*** IMPORTANT CONCEPT ***

The behaviour of char arrays and int array is different when it comes to
pointers:
checkout- pointer_char_array.cpp

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 27 **\

int value=5;
-----> int *ptr=&value;
why are we not writing this like this pointer ptr=&value; ?
ans== because this specifies that :-
1) kis type ka data hai like int,double and all.
2) kitne byte ko consider krna hai.
similar as we write that while declaring any other data type;

-----> pointers store the address of the data type like
mentioned in previous lectures..

now for double pointers
int i=5;
int *ptr=&i;
int **ptr2=&ptr;

***we need double pointers for dynamic memory allocation for arrays of pointers***

/// sirf dusro ke liye ///

remember that :
** if you are initializing a pointer as null pointer than you have to assign values in a fixed manner
like :
   //// *** +++ ERROR +++ ***\\\
    int *p = 0;
    int first = 110;
    *p = first;
    cout << *p << endl;
  ////*** +++ Correct +++ ***\\\\
    int *p=0;
    int firsts =110;
    p=&first;
    cout<<*p<<endl;

**make sure to checkout the mcq section of pointers video of lecture 27 its really helpful for deep understanding ;


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 28 **\

+ Reference variable is basically a kind of giving another name to a variable every function remain same it is not like pass by value.
+ pass by value \/ pass by reference
- in pass by value it creates a copy of the variable
- and pass by value also take memory separartely
- while in case of pass by reference it does not create a copy it is basically renaming of variable
- it does not take its separate memory unlik pass by value;

+ using pass by reference through return type function like this is strictly prohibited same as pointer also;
int& func(int a) {
    int num = a;
    int& ans = num;
    return ans;
}


+ declaring array like this is a bad practice
int array[n];
because of some memory allocation prblem in stack vs heap memory allocation
-- then how can we make variable size array ???
simply using heap memory
*and for using heap memory we need to use (new) keyword

++ so when we use stack we use static memory while when we use heap memory
we use dynamic memory

in order to intitialise a variable sized array we can use the pointers to
form a connection between stack and heap memory

++++ char* ch = new char; ++++

so, basically we will be intializing a variable in heap memory and then in
stack memory we will be using pointers so that to link the stack with heap .

*** so this is how we can create a array in heap memory with variable array size
int *arr = new int[5];
the L.H.S here is the stack memory while the R.H.S here is the heap memory

static memory vs dynamic memory;
1) dynamic memory takes more memory than static since it also have the memory of pointer
2) static memory is deleted automatically while we need to delete the dynamic memory
manually using delete keyword.

for single element  deletion : - delete i
for array deletion :- delete []arr;

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 29 **\

In this lecture we studied how to create 2d_array using dynamic memory of heap memory
visit 2d_array.cpp for details

int **arr = new int *[row];

arr
┌────┬────┬────┬────┐
│ *  │ *  │ *  │ ...│ (Each * represents an int pointer)
└────┴────┴────┴────┘

for (int i = 0; i < row; i++) {
    arr[i] = new int[col];
}

arr
┌────┬────┬────┬────┐
│ *  │ *  │ *  │ ...│
└─┬──┴─┬──┴─┬──┴───┘
  ↓    ↓    ↓
┌────┐ ┌────┐ ┌────┐
│int │ │int │ │int │ ...
│int │ │int │ │int │ ...
│... │ │... │ │... │
└────┘ └────┘ └────┘



<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 30 **\

++] Macros -In C++, macros are preprocessor directives defined with #define to create constants,
   functions, or expressions that get replaced directly in the code during preprocessing (before compilation).
   They are often used to simplify code and improve readability, but they lack some of the safety features of functions or constants.

++] Global variables : when a variable is declared outside any scope it is known as global variable and also we avoid the use
    of global variable since anyone can change its value;

++] INLINE FUNCTION : In C++, an inline function is a function whose definition is expanded in place where it is called,
    instead of going through the typical function call mechanism. The inline keyword is a request to the compiler to replace a function call with the actual code of the function,
    which can potentially reduce the overhead of the function call, especially for small, frequently used functions.
    ( ONLY VALID FOR 2-3 MAX LINES OF CODE )

++] DEFAULT ARGUMENTS : In C++, default arguments are values specified in a function declaration or
    definition that automatically fill in for missing arguments when the function is called.
    They allow you to call a function with fewer arguments than it typically requires by providing default values for those that aren’t specified.
--]. Rules for Default Arguments : Default arguments must be specified from right to left. If you want to provide a default for one parameter, all parameters to its right must also have defaults.
     Default values are typically provided in the function declaration (in a header file) rather than the definition (in the source file). This ensures that other files using the function know the defaults.

++] CONSTANT VARIABLE : 
In C++, a constant variable is a variable whose value cannot be changed after it is initialized. It is declared using the const keyword.
Constant variables help prevent accidental modification of values that are meant to remain unchanged throughout the program.

 
<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 31 **\

RECURSION : function calls itself directly or indirectly ;
|
|
|---->BASE CASE
|
|---->RECURSIVE RELATION(RR)
|
|---->PROCESSING(cout,update,etc)  [OPTIONAL]

if (RR is in the end of a function than it is TAIL recursion)
if(RR is before processing than it is known as HEAD recursion)
// checkout count.cpp for better understanding of tail and head recursion

*** What's base case in Recursion : ***
Base case is basically where the recursion is going to stop for example in case of factorial problem if(n==0)return 1 is the base case
and it is mandatory to write return in base case;

How does recursion works : 
checkout-) factorial_recursion.cpp
firstly 
it will call the functions and once the base case is reached i=unwinding of recursion will take place
Recursion Tree for n = 4:
Recursive relation ||  unwinding
                4  ->4*6
              ↙   
            3   ->  3*2
          ↙  
        2    ->   2*1
      ↙      
    1    -> 1*1   
  ↙ 
0 ->1

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 32 **\

solve the basic problem of recursion 
1) walking.cpp
2) fibonacci.cpp
3) climb stairs.cpp(code studio)
here is example recursion tree 
                fib(4)
               /      \
          fib(3)     fib(2)
         /      \       /    \
    fib(2)    fib(1) fib(1) fib(0)
   /      \
fib(1)  fib(0)

done only with the recursion 

4) say digits problem .cpp

recursive tree :-
example :- 

             number(412)
             /        \
          [41]        [2]  
          /  \
        [4]   [1]
       /   \    
     [0]--->[4]  


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 33 **\

elimination.cpp(leetcode 390)
isSortedarray.cpp
sumthroughrecursion.cpp
ispresent.cpp
**** Binary search .cpp


****** Reattempt all question from lecture 12 to 15 of binary search *******
1) Q-34 leetcode
2) Q-2485 leetcode  
3) Q-852 leetcode
4) Q-33 leetcode(***)


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 34 **\

---- Remember whenever making a function make sure to pass array and string 
by reference and not by value

remember just solve one case and rest leave on recursion.

1) Q-check_plaindrome.cpp
2) reverse_String.cpp
3) exponent.cpp
4) bubble sort.cpp
5) selection sort.cpp
6) insertion sort.cpp

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 35 **\


---------- MERGE SORT----------
Divide and Conquer technique.
Q) Merge_sort.cpp
Q) Inversion_count.cpp

Applications of Merge Sort:
Merge Sort is efficient for linked lists due to its sequential data access and ability to merge without extra space. 
It outperforms Quick Sort for linked lists as random access is not needed.


| Algorithm         | Best Case        | Worst Case       | Average Case     | Space Complexity | Stability |
|-------------------|------------------|------------------|------------------|------------------|-----------|
| **Quick Sort**    | `O(n log n)`     | `O(n^2)`         | `O(n log n)`     | `O(log n)`       | No        |
| **Merge Sort**    | `O(n log n)`     | `O(n log n)`     | `O(n log n)`     | `O(n)`           | Yes       |
| **Heap Sort**     | `O(n log n)`     | `O(n log n)`     | `O(n log n)`     | `O(1)`           | No        |
| **Insertion Sort**| `O(n)`           | `O(n^2)`         | `O(n^2)`         | `O(1)`           | Yes       |
| **Bubble Sort**   | `O(n)`           | `O(n^2)`         | `O(n^2)`         | `O(1)`           | Yes       |
| **Selection Sort**| `O(n^2)`         | `O(n^2)`         | `O(n^2)`         | `O(1)`           | No        |


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 36 **\

Quick_sort.cpp

Algorithm Steps
Choose a Pivot: Select an element from the array as the pivot (common choices include the first element, the last element, the middle element, or a random element).

Partitioning:

Rearrange the elements so that:
All elements smaller than the pivot are to its left.
All elements greater than the pivot are to its right.
This is done in-place using two pointers.
Recursive Sorting:

Recursively apply the same process to the left and right sub-arrays formed by partitioning.
Base Case:

If the array has one or zero elements, it is already sorted.

--> INPLACE(An algorithm is in-place if it uses only a constant amount of extra memory (O(1)) besides the input data structure.
 It modifies the input data directly without requiring additional space for temporary or auxiliary structures.)
---> NOT STABLE


stable: an algorithm is stable if it maintains the relative order of elements with equal values in the input.


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 37 **\

Q - 78 ) Subsets
// try this question with bit manipulation 

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 38 **\

17) Letter combination of a phone number 

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 39 **\

Q-46) Permutation

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 40 **\
rat in a maze problem in gfg
rat_in_maze.cpp


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 41 **\

Time complexity discussion 
T.C :- 
Time complexity refers to the amount of time an algorithm takes to complete based on the input size n.
 It is usually expressed using Big O notation.
It helps in analyzing how the runtime of an algorithm grows as the input size increases.


factorial :- O(n)
Binary search :- O(logn)
merge sort :- O(nlogn)
fib series :- O(2^n)




Space complexity  :- 
Space complexity refers to the amount of memory an algorithm needs to execute relative to the input size n.
It includes both auxiliary space (extra space used by the algorithm) and input space (space required to store the input itself).
factorial :- O(n)
Binary search :- O(logn)
merge sort :- O(n)
fib series :- O(n)


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 44 **\
Linked list :-
It is a type of linear data structure 
Basically a collection of nodes containing data and the address to the next node 

why it is used?
because array is not dynamic in nature while in linked list we have a feature because of which 
we do not need to give contiguos memory location to linked list since it can be anywhere in the heap
memory, since we have the address of the pointer so we can get to the next node easily 

------> intro.cpp <-------

TOPICS OF LINKED LIST :- (BASICS)
-> formation of basic outlook
-> traversal in linked list 
-> insertion of a node 
-> deletion of a node 

------> Followed striver's sheet for single linked list check that out for reference <--------

TOPICS: -
1) SINGLE LINKED LISTS
2) DOUBLY LINKED LISTS
3) CIRCULAR LINKED LISTS


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 45 **\


1)✅, Reverse linked list Q-206 (with three approach)
2)✅, find middle of the linked list Q-876 ( with two approach )

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 46 **\

1)✅ Q-25 Reverse Nodes In K-Group 
2)✅ circularly linked link :- https://www.naukri.com/code360/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=PROBLEM


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 47 **\

Detect loop approaches:-
loop.cpp



✅Q-141 detect loop (through map)
✅(floyd detection)
✅Q-142) LINKED LIST CYCLE 2 really good question explained beautifully by love babbar
✅ use approach three in lecture 47  to solve this problem..

just see loop.cpp you will understand a lot



<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 48 **\

Questions Links:
✅Remove Duplicates from Sorted Linked List: https://bit.ly/3rjMQC5 
✅Remove Duplicates from Un-Sorted Linked List: https://bit.ly/3uaGRRU 




<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 49 **\

Questions Links:
✅Sort 0s, 1s and 2s : https://bit.ly/3s3fAOu  (two approaches )
✅Merge 2 sorted Linked List : https://bit.ly/3rfFdfV (two approaches)


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 50 **\

✅ Check Palindrome
multiple approaches do check leetcode problem 234

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 51 **\




✅ add 2 numbers
✅ add 1 to a number 
do check problem 2 of leetcode 
and also check striver a to z sheet for this 2 problem..





<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 52 **\

✅ 138.) Copy List with Random Pointer
solved this problem with three approaches.a


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 53 **\


✅ merge sort in linked list :- 
https://www.naukri.com/code360/problems/mergesort-linked-list_630514?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb

✅ flatten linked list problem :-
https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 54 **\
 -                                                     SHREE GANESH

 -                                                         STACK

🔹Stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, 
a LIFO (last-in, first-out) data structure.

for example : plates arranged in a wedding is a common example of stack 

🔹 Key Operations of a Stack
✅ Push(x) → Adds an element x to the top of the stack.
✅ Pop() → Removes the top element from the stack.
✅ Top() / Peek() → Returns the top element without removing it.
✅ isEmpty() → Checks if the stack is empty.
✅ Size() → Returns the number of elements in the stack

🔹 Stack Representation
A stack can be implemented using:

✅ Arrays (Fixed size)
✅ Linked List (Dynamic size)

📌 Real-World Applications of Stack
✅ Function Calls (Recursion uses a call stack)
✅ Undo/Redo in text editors
✅ Browser History (Back/Forward)
✅ Expression Evaluation & Conversion (Infix to Postfix, etc.)
✅ Memory Management (Stack Memory in C/C++)



Do check out 
✅ INTRO.cpp
✅ Arr_Implementation.cpp
✅ LinkedList_Implementation.cpp
✅ Two Stacks.cpp(coding ninjas)[two stacks using single array](memory utilization best).



<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 55 **\


-                                         📌📌IMPORTANT QUESTION FROM RECURSION AND STACK BASICS POV 📌📌
📌Do check the recursion method for problems(delete the middle value and insert element at bottom and reverse using recursion)📌

❓ Reverse a string using stack (reverse_name.cpp)
❓ Delete the middle value in a stack (https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION)
❓ (q-20)Valid parentheses(leetcode)
❓ Insert an element at the bottom of the stack (https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION)
❓ Reverse stack using recursion (https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION)
❓ Sort a Stack (https://www.naukri.com/code360/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=SUBMISSION)
❓ Reduntant brackets (https://www.naukri.com/code360/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio)
❓ Minimum Cost To Make String Valid (https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM)


📌 1249. Minimum Remove to Make Valid Parentheses   📌
📌                                                  📌
📌 Also check the operation and properties of set   📌
📌 in set.cpp                                       📌
📌                                                  📌
📌 2116. Check if a Parentheses String Can Be Valid 📌
📌 150. Evaluate Reverse Polish Notation            📌

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 56 **\


❓ Next Smaller elements (https://www.naukri.com/code360/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM)
❓📌 📌  Q-84). Largest Rectangle in Histogram 📌 📌 ❓

📌 503) NEXT GREATER ELEMENT 📌

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 57 **\

❓📌 Celebrity Problem (https://www.geeksforgeeks.org/problems/the-celebrity-problem/1) 📌
❓📌 Leetcode 85 Max rectangle (use problem 84 as well for this.) 📌 
❓ Number of greater elements in the right in gfg (strivers sheet).
❓


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 58 **\📌

❓📌 N -Stacks https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa3RNdkpOZzlmejRDa2hvV0dCYkJ2ODBDYkFXd3xBQ3Jtc0tuekNuVVd4Vl95UnpHbXhBWUtONDFRZVo0ZEl2VXM1REgwblIxMVVFaGw3MEYxSTVLS055VnF2MG00a0JlZEZ6TzlVWi1WMHlnT0NGQk1FSE9EX1hVY2QxbkREbTBQSmQ5ZC02dzAwUFFFOW9ZaGV4QQ&q=https%3A%2F%2Fbit.ly%2F3BexNwv&v=lrSXKLmnMV8


<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 59 **\📌

❓📌  Design a stack that supports getMin() in O(1) time and O(1) extra space() https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar&leftPanelTabValue=PROBLEM

<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 60 **\




🔹🔹A Queue is a linear data structure that follows the FIFO (First In, First Out) principle. The element added first is removed first.

1. Basic Operations on Queue:-

🔹Enqueue(x) → Insert an element x at the rear.

🔹Dequeue() → Remove an element from the front.

🔹Front() / Peek() → Get the front element without removing it.

🔹isEmpty() → Check if the queue is empty.

🔹isFull() → Check if the queue is full (for a fixed-size queue).

🔹🔹
### Deque (Double-Ended Queue) in DSA  

A **Deque (Double-Ended Queue)** is a linear data structure that allows insertion and deletion from both ends.  

---

## 1. Types of Deque  
1. **Input Restricted Deque** → Insertion is allowed only at one end, but deletion can happen from both ends.  
2. **Output Restricted Deque** → Deletion is allowed only at one end, but insertion can happen from both ends.  

---

## 2. Basic Operations on Deque  
1. **push_front(x)** → Insert an element `x` at the front.  
2. **push_back(x)** → Insert an element `x` at the rear.  
3. **pop_front()** → Remove an element from the front.  
4. **pop_back()** → Remove an element from the rear.  
5. **front() / peekFront()** → Get the front element without removing it.  
6. **back() / peekRear()** → Get the rear element without removing it.  
7. **isEmpty()** → Check if the deque is empty.  
8. **isFull()** → Check if the deque is full (for a fixed-size deque).  


Questions :- 
❓queue implementation- https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbmJGb19wNWVXdVE4a3c0NnUyNTh1SVpnYXhIUXxBQ3Jtc0tsWXJhbi1mNnRnWnlBMkktVmpPT1FhTFlIOWVHdUdWY1laNnU0eDlIX3ZqY19QeUM2WGs2Nm9jcTA1TVNwSE1EMkRlc0JicDRlaTJSTUJxVGQtMlByc2wwTkF2QlJyQVJFVWpSaWdCTlMtdE51Z2ZjQQ&q=https%3A%2F%2Fbit.ly%2F3uL7QDG&v=W7uB9-TKfTg
❓Circular Queue :https://bit.ly/34xocVZ
❓📌Doubly Ended Queue Implementation:https://bit.ly/3JoEvmF






<--------------------------------------------------------------------------------------------------------------------------------->
/** Lecture 61 **\

❓
❓📌

❓ Queue Reversal: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblJGNlR2cU9USG01amNJa0ZiUHZSbGo5OE5WQXxBQ3Jtc0tuc3o1V3B2UlBmVFl0eGVIWW9mZ1N3dXo2MHZsSjA3QkJoQk85NHozSEVtLU9XQTQ0cW1BUkYxSE95TEJ1enZMMFNmTWYwejFYb09KSnpFTGtyVmhzOGtFQzdhaERub2F4cDhmaFlBLU12TW00UDlPVQ&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Fqueue-reversal%2F1&v=_gJ3to4RyeQ
❓📌📌 First negative integer in every window of size K:https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbUVISTNPQmUyMXU1aGQ3cEFoQ2NCaVZhUFBUQXxBQ3Jtc0tuM1hBc3g0WTFGMk5ONWRRQmVFZVduVjUtLWk5a1YwLUkyYndVMDFYcTdoSXRwb1hTYTNiYjN0eDRDV1ZUUm5VYjQ4b1IxQjFQSUxCbGRWdmJOMC0zajNyWlZTTmdnOVRVeWRyN3FEMVAwYjNUMTRuOA&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Ffirst-negative-integer-in-every-window-of-size-k3345%2F1&v=_gJ3to4RyeQ
❓Reverse first K element of Queue: https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa0JzNTV0aXNDdnB6TEkzOUV1RC1laHJTaXBsUXxBQ3Jtc0ttOE12NzNHR1lJbDFrVllOWkFFX1Z5a2JJU0pfeEk1Rzg5QVh5UHRaUEJXdF9IdTBkamFBZk1Zbm5fOHY0T21ybS1lWkJ4dExTdXpwakFabjJ0cGJlVFkyNU1Kc21FT0poYmVmUXdBSkJHdEhLSHE1cw&q=https%3A%2F%2Fpractice.geeksforgeeks.org%2Fproblems%2Freverse-first-k-elements-of-queue%2F1%2F&v=_gJ3to4RyeQ
❓📌📌📌📌First Non-Repeating character in stream:https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
❓📌📌📌Circular tour(Gas Station): Leetcode -134
❓Interleave the first half of the queue with the second half(GFG)
❓K Queue in Single Array:https://www.geeksforgeeks.org/efficie...
❓Sum of min & max elements of all subarray of size K: https://www.geeksforgeeks.org/sum-min...


❓📌📌implement queue using stack (232)
❓📌📌implement stack using queue (225)



📌📌📌📌 📌📌📌📌📌📌📌📌 remember one thing in these types of question of conversion btw infix, prefix, and postfix that a single character is not a string so whenever such conditon occur 
make sure that you make a character a string by doing this string(1,arr[i]) 📌📌📌📌📌📌📌📌




❓📌📌 conversion question between infix , prefix and postfix check out the striver sheet for that i did all
these questions from gfg
📌📌📌📌📌📌Infix to Postfix Conversion using Stack
     1) check for the precdence of the operator first like ^ is 3 and * and / is 2 and + and - are 1 .
     2) now if ( this comes then push it directly to the stack and if ) this comes then through a while loop empty the stack until there is (
     3) now then check for the precedence of operator if precedence of operator is lower than that of stack top element than empty it untll there is low precedence

📌📌Prefix to Infix Conversion
     simply check the string from backward and accordingly convert it..
📌📌Prefix to Postfix Conversion
     similar to what it was in prefix to infix just change the order of how the elements gone push.. 
📌📌Postfix to Prefix Conversion
     similar to what's going on above just two changes first is the same order changes and the second one is an extra
     while loop that runs in the end to empty the stack and push it in ans..
📌📌Postfix to Infix
     similar to what we are doing in above problem just one thing order and that's all everything else is same..
📌📌Convert Infix To Prefix Notation
     now, this and the top one are the most difficult one so revise this essentially..
     process:-
     1) reverse the infix first make sure to change the paranthesis also ))()
     2) now convert the infix to postfix make sure you convert only when ^ this is encounterd or a closing paranthesis
     3) now reverse the postfix expression and you are good to go..

do check out striver's sheets problem marked as revise...

sliding window maximum problem 
slidingwindow.cpp







































































*/