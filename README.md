# learn-c
My code while learning C and some data

## first-one

### Overview

This program greets my cat in many colors. The trick used here is simple, you take number 31, which stands for
red, and iterates until 37, meaning it will never hit 38, thus `i < 38`. All of this lays inside for loop
with `man 3 printf` statements that clears color encoding with `\033[0m` and interpolates `i` variable as a 
decimal - `%d`. At the end of each loop there is a `\n` character that mean to break a line and start over.

Overall program1 will print 7 times this sentence in different color:

```
Cześć Nutek, mówi Szymon!
```

### Why?

I'm reading __Learn C The Hard Way__ by _Zed Shaw_ probably availabla here - `help@learncodethehardway.org`.
The first task was to create a program that does something with 100 km away, so after hacking colors in _bash_
earlier the day, I thought it would be cool to start a new learning project to lay a ground for my future work.
Maybe you will get something from this too.

### What's next?

#### Reading and writing

Don't worry I have skills, so you can follow along. My language is somewhat all around the computer, but just in
case I have __ChatGPT__ to help me along the way. Set sail!

#### Makefile

There wouldn't be any of this if not __Copilot's__ long description of macros in my small _Makefile_. It made
me jelous about the technical writing skills of AI robot vs a human being, and I know that there is a room for
both.

```Makefile
CFLAGS=-Wall -g
```

This, first, line tells that every compiler command should warn us about anything wrong in the code. Something
like this:

```c
program1.c:5:11: error: array initializer must be an initializer list
    char *name[] = "Szymon";
          ^
program1.c:7:61: warning: format specifies type 'char *' but the argument has type 'char **' [-Wformat]
        printf("\033[0;\"%d\"mCześć Nutek, mówi %s.", i, name);
                                                ~~       ^~~~
1 warning and 1 error generated.
```

You can clearly see, that I tried to duplicate the `*argv[]` declaration inside main function, which produced
an error, and then I get someow related warning that my string interpolation is not the type it should be.

#### Compilation

You can compile your program with just invoking `clang input.c -o program`, but I have also made object file,
with `clang -c program1.c`, that will be neccesairly later in debuging in __lldb__ (you can use _gdb_). I had 
no idea how to do this, because all of my linking, object creating and compiling was with higher order 
programming languages, so I relied on _Copilot_ code generation. It also made me a clean task for easier 
management.

## printf();

In C programming language, the `printf()` function is used to output data to the console or terminal window. 
It is a powerful function that can be used to format and print various types of data, including text, numbers, 
and variables. Some of the things you can do with the `printf()` function include:

1. Print text: You can use the `printf()` function to output any text that you want to the console. For example,
`printf("Hello, world!");` will output the text "Hello, world!" to the console.

2. Print variables: You can use the `%d` format specifier to print integer variables, `%f` to print float variables,
`%c` to print character variables, and `%s` to print string variables. For example, `int x = 10; printf("The value of x is %d", x);` will output "The value of x is 10" to the console.

3. Format output: You can use a wide range of formatting options with the `printf()` function to control how 
your output is displayed. For example, you can specify the width and precision of numbers, add leading zeros, 
and control the alignment of your output.

### Precision of floating point bumber

To display a floating point number with a precision of two decimal places using the `printf()` function in C, 
you can use the `%0.2f` format specifier.

```c
#include <stdio.h>

int main() {
    float number = 3.14159;
    printf("The number is: %.2f\n", number);
    return 0;
}
```

This will display number `3.14`

### Leading zeros

To display a number with six leading zeros in C, you can use the `%06d` format specifier with the `printf()` 
function.

```c
#include <stdio.h>

int main() {
    int number = 42;
    printf("The number with six leading zeros is: %06d\n", number);
    return 0;
}
```

This will display number 000042

### Hexadecimal output

#### Integer

To display an integer in hexadecimal format using the `printf()` function in C, you can use the `%x` format 
specifier.

```c
#include <stdio.h>

int main() {
    int number = 255;
    printf("The number in hexadecimal format is: %x\n", number);
    return 0;
}
```

In this example, the number variable is an integer type with the value of 255. The `printf()` function is used 
to output the value of number in hexadecimal format using the format specifier `%x`. The output will be 
"The number in hexadecimal format is: ff".

### Float

Note that the `%x` format specifier only works with integers. If you want to display a floating point number 
in hexadecimal format, you can use the `%a` format specifier instead. For example:

```c
#include <stdio.h>

int main() {
    float number = 3.14159;
    printf("The number in hexadecimal format is: %a\n", number);
    return 0;
}
```

In this example, the number variable is a floating point type with the value of _3.14159_. The `printf()`
function is used to output the value of number in hexadecimal format using the `%a` format specifier. 
The output will be "The number in hexadecimal format is: 0x1.921fap+1".

### String

To display a string as a sequence of hexadecimal values using the `printf()` function in C, you can use the 
`%x` or `%X` format specifier in combination with a loop that iterates through each character in the string.

Here's an example code snippet that shows how to do this using the %x format specifier:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        printf("%x ", str[i]);
    }
    printf("\n");
    return 0;
}
```

In this example, the str variable is a string that contains the text "Hello, world!". The len variable is the 
length of the string, which is obtained using the `strlen()` function. The for loop iterates through each 
character in the string, and the `printf()` function is used to output the hexadecimal value of each character 
using the `%x` format specifier. The output will be a sequence of hexadecimal values, one for each character 
in the string.

Note that the `%x` format specifier displays the hexadecimal value of each character using lowercase letters 
(a-f) for values greater than 9. If you want to use uppercase letters (A-F) instead, you can use the `%X` format
specifier.

3. ...continur on what `printf()` can do...

4. Print special characters: You can use special escape sequences to print characters such as tabs, newlines, 
and quotes. For example, `printf("This is a tab:\tAnd this is a newline:\n");` will output "This is a tab: And
this is a newline:" to the console.

### Ring a bell

```c
#include <stdio.h>

int main() {
    printf("\a");
    return 0;
}
```

This program will ring a system bell if it can. Check it out! Here is some trivia: In this example, the `\a` 
escape sequence is used to generate the ASCII bell character, which will cause the system to ring the bell. 
The `printf()` function is used to output the bell character to the console. When you run this program, the 
system will ring the bell once.

Note that the behavior of the `\a` escape sequence may vary depending on the system and terminal emulator 
you are using. In some cases, it may not actually ring the system bell, but instead generate a visual or 
auditory signal in some other way.

5. Use conditionals: You can use conditional statements within the printf() function to output different text
based on the value of a variable. For example, `int x = 10; printf("x is %s", x > 5 ? "greater than 5" : "less than or equal to 5");` will output "x is greater than 5" to the console.

These are just a few examples of what you can do with the printf() function in C programming language. It is a versatile and powerful function that you can use to output all kinds of data to the console.

## C operators

In C programming language, there are different types of operators that can be used to perform various operations on values. Here are some of the most commonly used operators in C:

### Arithmetic Operators:

`+` : Addition
`-` : Subtraction
`*` : Multiplication
`/` : Division
`%` : Modulo (Remainder)

### Comparison Operators:

`==` : Equal to
`!=` : Not equal to
`<` : Less than
`>` : Greater than
`<=` : Less than or equal to
`>=` : Greater than or equal to

### Logical Operators:

`&&` : Logical AND
`||` : Logical OR
`!` : Logical NOT

### Assignment Operators:

`=` : Assign value
`+=` : Add and assign value
`-=` : Subtract and assign value
`*=` : Multiply and assign value
`/=` : Divide and assign value
`%=` : Modulo and assign value

### Increment and Decrement Operators:

`++` : Increment by 1
`--` : Decrement by 1

### Bitwise Operators:

`&` : Bitwise AND
`|` : Bitwise OR
`^` : Bitwise XOR
`~` : Bitwise NOT
`<<` : Bitwise left shift
`>>` : Bitwise right shift

### Ternary Operator:

`? :` : Conditional operator (also known as ternary operator)

These are some of the most commonly used operators in C. Understanding how to use these operators can help you 
perform various operations on data in your C programs.

### Pointers 

Pointers are used to store memory addresses of variables. To manipulate and access the data stored at those 
memory locations, pointer operators are used. Here are some of the most commonly used pointer operators in C:

`&` operator:

The `&` operator is used to get the address of a variable.
Example: `int x = 10; int* ptr = &x;` will assign the address of the variable x to the pointer ptr.

`*` operator:

The * operator is used to access the value stored at the memory address pointed to by a pointer.
Example: `int x = 10; int* ptr = &x; int y = *ptr;` will assign the value of x (which is 10) to the variable y.

`++` and `--` operators:

The `++` and `--` operators can be used to increment or decrement the memory address pointed to by a pointer.
Example: `int arr[] = {1, 2, 3}; int* ptr = arr; ptr++;` will increment the pointer ptr to point to the next 
element in the array.

`->` operator:

The `->` operator is used to access a member of a structure or union through a pointer.
Example: `struct Point { int x, y; }; struct Point p = {1, 2}; struct Point* ptr = &p; int x = ptr->x;` 
will assign the value of p.x (which is 1) to the variable x.

`[]` operator:

The `[]` operator can be used to access elements of an array through a pointer.
Example: `int arr[] = {1, 2, 3}; int* ptr = arr; int x = ptr[1];` will assign the value of arr[1] (which is 2) 
to the variable x.

These are some of the most commonly used pointer operators in C. Understanding how to use these operators can 
help you manipulate and access data stored in memory through pointers.

## C keywords

* `auto`: This keyword is used to define local variables that are automatically initialized to garbage values.

* `break`: This keyword is used to exit a loop or switch statement early.

* `case`: This keyword is used to define a case in a switch statement.

* `char`: This keyword is used to define a character variable.

* `const`: This keyword is used to define a variable as constant, i.e., its value cannot be changed.

* `continue`: This keyword is used to skip to the next iteration of a loop.

* `default`: This keyword is used to define the default case in a switch statement.

* `do`: This keyword is used to define a do-while loop.

* `double`: This keyword is used to define a double-precision floating-point variable.

* `else`: This keyword is used to define an alternative branch in an if statement.

* `enum`: This keyword is used to define an enumeration type.

* `extern`: This keyword is used to declare a variable or function that is defined in another file.

* `float`: This keyword is used to define a single-precision floating-point variable.

* `for`: This keyword is used to define a for loop.

* `goto`: This keyword is used to jump to a labeled statement.

* `if`: This keyword is used to define a conditional statement.

* `int`: This keyword is used to define an integer variable.

* `long`: This keyword is used to define a long integer variable.

* `register`: This keyword is used to define local variables that are stored in the CPU registers.

* `return`: This keyword is used to return a value from a function.

* `short`: This keyword is used to define a short integer variable.

* `signed`: This keyword is used to define a signed integer variable.

* `sizeof`: This keyword is used to determine the size of a variable or data type.

* `static`: This keyword is used to define local variables that are only initialized once and retain 
their values between function calls.

* `struct`: This keyword is used to define a structure type.

* `switch`: This keyword is used to define a switch statement.

* `typedef`: This keyword is used to define a new data type.

* `union`: This keyword is used to define a union type.

* `unsigned`: This keyword is used to define an unsigned integer variable.

* `void`: This keyword is used to define a function that does not return a value, or to define a pointer
to an unspecified data type.

* `volatile`: This keyword is used to tell the compiler that a variable's value may change at any time,
so it should not optimize out reads or writes to it.

```
auto     double   int      struct
break    else     long     switch
case     enum     register typedef
char     extern   return   union
const    float    short    unsigned
continue for      signed   void
default  goto     sizeof   volatile
do       if       static   while
```

## C language constructs

### if

* `if`: The `if` statement is used for conditional execution of code. Here's an example:

```
int x = 5;
if (x > 0) {
    printf("x is positive\n");
}
```

This code will print "x is positive" because the condition `x > 0` is true.

### switch

* `switch`: The `switch` statement is used for multi-way branching. Here's an example:

```
int day = 3;
switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    default:
        printf("Unknown day\n");
        break;
}
```

This code will print "Wednesday" because the variable `day` is set to 3.

### while

* `while`: The `while` statement is used for loop execution as long as a condition is true. Here's an example:

```
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}
```

This code will print the numbers 0 through 9 because the condition `i < 10` is true for those values of `i`.

### do while

* `do while`: The `do while` statement is used for loop execution at least once, and then repeatedly as
long as a condition is true. Here's an example:

```
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 10);
```

This code will print the numbers 0 through 9 because the `do` block is executed at least once, and then 
repeatedly as long as the condition `i < 10` is true.

### for

* `for`: The `for` statement is used for loop execution with a fixed number of iterations. Here's an example:

```
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

This code will print the numbers 0 through 9 because the loop runs for 10 iterations with the variable `i`
starting at 0 and incrementing by 1 each time.

### goto

* `goto`: The `goto` statement is used for unconditional branching to a labeled statement. Here's an example:

```
int i = 0;
start:
printf("%d\n", i);
i++;
if (i < 10) {
    goto start;
}
```

This code will print the numbers 0 through 9 because the `goto` statement jumps back to the `start` label as 
long as the condition `i < 10` is true.

### function

* Function: A function is a named block of code that can be called from other parts of the program. 
Here's an example:

```
int add(int a, int b) {
    return a + b;
}

int result = add(3, 4);
printf("%d\n", result);
```

This code defines a function called `add` that takes two integer arguments and returns their sum. 
It then calls the `add` function with arguments 3 and 4 and prints the result, which is 7.

### typedef

* Typedef: The `typedef` keyword is used to define a new type based on an existing type. Here's an example:

```
typedef int myint;
myint x = 5;
```

This code defines a new type called `myint` that is an alias for the `int` type. It then declares a 
variable `x` of type myint and initializes it to 5.

### struct

* Struct: A `struct` is a user-defined data type that groups together related data items. Here's an example:

```
struct Person {
    char name[50];
    int age;
    float height;
};

struct Person john = {"John", 30, 1.75};
printf("%s is %d years old and %f meters tall\n", john.name, john.age, john.height);
```

This code defines a `struct` called `Person` that contains a character array for the name, an integer
for the age, and a floating-point number for the height. It then declares a variable `john` of type
`Person` and initializes its fields with values. Finally, it prints out some information about `john`.

### typedef struct

* Typedef struct: The `typedef struct` keyword combination is used to define a new type based on a `struct` 
type. Here's an example:

```
typedef struct {
    char title[50];
    int year;
} Book;

Book book = {"The Catcher in the Rye", 1951};
printf("%s was published in %d\n", book.title, book.year);
```

This code defines a new type `Book` based on an anonymous `struct` that contains a character array for the 
title and an integer for the year. It then declares a variable `book` of type `Book` and initializes its 
fields with values. Finally, it prints out some information about the book.

### union

* Union: A `union` is a user-defined data type that can hold data of different types in the same memory 
location. Here's an example:

```
union Data {
    int i;
    float f;
    char str[20];
};

union Data data;
data.i = 10;
printf("data.i = %d\n", data.i);
data.f = 3.14;
printf("data.f = %f\n", data.f);
strcpy(data.str, "Hello");
printf("data.str = %s\n", data.str);
```

This code defines a `union` called `Data` that can hold an integer, a floating-point number, or a character 
array. It then declares a variable `data` of type `Data` and initializes its integer field with a value. It 
then sets the floating-point field and the character array field to other values and prints out some 
information about `data`. Note that only one field of the `union` can be accessed at a time, and the other
fields may contain garbage data.

### difference between union and struct

In C, a `struct` is a user-defined data type that groups together related data items of different types. 
Each field within a `struct` has its own memory location, and all fields are allocated memory simultaneously.
Each field can be accessed independently and manipulated as needed.

On the other hand, a `union` is also a user-defined data type that can hold data of different types 
in the same memory location. Unlike a `struct`, a `union` can only hold one value at a time, and all fields 
share the same memory location. When a new value is assigned to a field of a `union`, the previous value 
is overwritten. Accessing any field of the union returns the currently stored value, regardless of what type
it is.

The main difference between a `struct` and a `union` is how they use memory. A `struct` allocates memory 
for all of its fields simultaneously, while a `union` allocates memory for only one of its fields at a time.
This makes `unions` more space-efficient than `structs` in certain situations, but also less flexible, 
since only one field can be accessed at a time.

Another important difference is that the size of a `struct` is the sum of the sizes of all its fields, 
while the size of a `union` is the size of its largest field. This means that the memory allocation 
of a `union` is based on its largest field, which may waste memory if the other fields are smaller.

In summary, a `struct` is used to group related data items of different types together, while a `union`
is used to represent different types of data in the same memory location. Both `structs` and `unions`
have their own unique uses and advantages depending on the situation.

## Why learn C?

Learning C language can be a great foundation for future development in other programming languages. 
Here are some steps you can take to learn C language quickly, reliably, and with the best results for 
future development:

1. Start with the basics: Begin by understanding the fundamentals of programming such as data types, 
variables, operators, loops, and functions. You can refer to a good C programming book or online tutorial 
to understand these concepts.

2. Practice coding: The best way to learn any programming language is by writing code. Try to solve small 
problems using C language, and gradually move to more complex problems. You can find many online platforms 
and coding challenges to practice your skills.

    - [Codewars.com](https://www.codewars.com/)

3. Learn from other people's code: Look at other people's code and try to understand how they are solving 
problems using C language. You can find open-source projects on GitHub or other platforms, read through 
the code and try to understand how it works.

    - [GitHub](https://github.com)

4. Get familiar with tools and IDEs: Use an Integrated Development Environment (IDE) that supports C 
programming. IDEs like CodeBlocks, Dev-C++, or Visual Studio Code can be helpful in writing and 
debugging code. Also, get familiar with tools like GCC and Makefile, which can be useful in compiling 
and building C code.

5. Keep learning and updating yourself: C language is a foundational language for many other programming 
languages, so it's important to keep learning and updating yourself with the latest developments in C 
language. Join online forums and communities, participate in discussions, and read blogs and articles 
to stay updated.

By following these steps, you can learn C language quickly, reliably, and with the best results for 
future development in other programming languages. Remember that learning a programming language takes time, 
so be patient and keep practicing.

## Rule the World, but first, complete this function

### Get git

No, seriously, get [git](https://git-scm.com/). Then head over to [Unity](https://github.com/ThrowTheSwitch/Unity) and 
click on the **green** button. Copy the _https_ link, don't worry it's completely free, like with me. Open
Termian on your computer, it might be called Console or Powershell, it does not matter, you will be talking
to the computer using commands, not being source of meta data - you just embark on your journey to become a
**dev**, so act like one and create yourself a folder where your source code will live and then, write in 
terminal `git clone https://github.com/ThrowTheSwitch/Unity`, press `<Enter>`, and that's it. You just 
cloned your first open source project. This one is unit testing framework that will help us get to know 
what's working in out programs and what's not. _Don't Reapeat Yourself_ and write down the exact flow of
the commands and maybe some additional notes what happened, because it's important.

### Unity, unit testing framework

Now we have to compile Unity. Actually we don't. We will just do this by the way... I mean we will eventally
compile the program, as it's not interpreted as for examply your macOS Ruby or Python, but it will be very easy.

```c
#include "path/to/folder/with/unity/src/unity.h" // see? It's just a mean of providing a correct path
// we don't have to link any external library or something, so it is relatively easy for this stage of your
// dev level (I hope you're eager to grow)

// now the first function
void setUp(void)
{
    // your code to setup the unit tests, like initializig connection to database
}

void tearDown(void)
{
    // close the connection to database, by the way - I'm non magically connecting/disconnecting here,
    // it's just my comments
}

// your first test function
void test_function_should_fail(void)
{
    // following red, green, refactor policy ♥️ -> 🐢 -> 🛤
    TEST_FAIL();
}

int main(void)
{
    UNITY_BEGIN();
    /* 
    Why should we fail, you ask?
    First of all it helps to catch false positives,
    and for the second argument, you will write a better test
    next time, or prepare/plan you work befer you go...
    */
    RUN_TEST(test_function_should_fail);
    return UNITY_END();
}
```

Now, I have to explain what we're actually doing. We want to know if a particular part of program is doing
what it's suppose to do, so we break the programs into smaller pieces, and then build up from them the
parts that will set to motion all the machinery inside your computer. I have to warn you. If you don't like
this it's fine, but if you want to find a job as a developer, you will be testing your programs all the day
long. If you write for fun, it's just good practice. Just good. What can I say to encourage you to do this?
You get the Unity for free, and are free to choose it.

Let's end the gibberysh talk and get to the point. Compilation. Ha, ha... Now we compile.

### Compile your first unit test

I have `clang` on my computer, you might have something else, so I will stick to the common ground and set on
`gcc` which should be available on most of the platforms.

```bash
gcc -Wall -g name_of_your_source_code_file.c path/to/unity.c -o test-if-fail
./test-if-fail
```

You should be presented with the output:

```text
-----------------------
1 Tests 1 Failures 0 Ignored
FAIL
```

I hope you're not feeling tremendously horrible with yourself right now. You should be proud! Your program
do exactly what you tell it to do, and nothing else.

### Let's spin the roulette around and see if we can... Yes, we can 🎨!

Instead of `TEST_FAIL()`, and yeah I know, I thought it's some kind of `Python` and that it will return false
and I could simply reverse it with `TEST_ASSERT_FALSE()`, but no, it's not like that. It's macro. We'll have
to embark on this journey together to know where it leads us. For now we will just refactor our RED/GREEN
case, assuming we wanted to fail and we had nothing before, to a bigger program. Now you judge me, or the
students. Let's assume there is a gradebook and we wan't to know who pass and what grade we will assign.

For the gradebook, you should be able to at least understand, if not write yourself, one of the first
`katas` from mentioned `Codewars` - Grasshopper - Grade book.

Find an averega of the 3 integer numbers (e.g. grades from the tests) and assign a final grade based on this
conditions:

```
if the average is less than 60, return 'F'
if the average is between 60 and 69, return 'D'
if the average is between 70 and 79, return 'C'
if the average is between 80 and 89, return 'B'
if the average is between 90 and 100, return 'A'
```

And I provide the test cases for you. If you haven't already, please open your text editor, IDE or
take a pen and piece of paper and follow along.

#### Test cases for grade book.

Modify the previous program, test function name to `test_function_should_assignGrades` and change it's
content to:

```c
TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(95, 90, 93), "95, 90, 93 should return 'A'");
TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(92, 93, 94), "92, 93, 94 should return 'A'");
TEST_ASSERT_EQUAL_INT_MESSAGE('A', get_grade(100, 85, 96), "100, 85, 96 should return 'A'");
TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(70, 70, 100), "70, 70, 100 should return 'B'");
TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(82, 85, 87), "82, 85, 87 should return 'B'");
TEST_ASSERT_EQUAL_INT_MESSAGE('B', get_grade(84, 79, 85), "84, 79, 85 should return 'B'");
TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(70, 70, 70), "70, 70, 70 should return 'C'");
TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(60, 82, 76), "60, 82, 76 should return 'C'");
TEST_ASSERT_EQUAL_INT_MESSAGE('C', get_grade(75, 70, 79), "75, 70, 79 should return 'C'");
TEST_ASSERT_EQUAL_INT_MESSAGE('D', get_grade(60, 60, 60), "60, 60, 60 should return 'D'");
TEST_ASSERT_EQUAL_INT_MESSAGE('F', get_grade(30, 30, 30), "30, 30, 30 should return 'F'");
TEST_ASSERT_EQUAL_INT_MESSAGE('F', get_grade(48, 55, 52), "48, 55, 52 should return 'F'");
```

Also, change in the main function, the line `RUN_TEST(test_function_should_assignGrades);`. Now you are ready
to write your first function on your own. You can do it in the same file, and to pass the tests, it's name
should be `get_grade`, or otherwise you will have to change all the invocations to name chosen by you.

### Grade book source code

My solution:

```c
int get_grade(int grade1, int grade2, int grade3)
{
    int average = (grade1 + grade2 + grade3) / 3;
    if (average < 60)
        return 'F';
    else if (average < 70)
        return 'D';
    else if (average < 80)
        return 'C';
    else if (average < 90)
        return 'B';
    else
        return 'A';
}
```

After running this code, or your code, along with the main test function you should get this result:

```text
-----------------------
1 Tests 0 Failures 0 Ignored
OK
```

Congratulation on your first passed test 🚀.

Here is the `Makefile` to cheer you up, with a little explanation:

```Makefile
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -I../unity

SRC = grasshoper-gradebook.c
UNITY_SRC = ../unity/unity.c

TARGET = grasshoper-gradebook

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC) $(UNITY_SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
```

Here's an explanation of each part of the Makefile:

* `CC = gcc`: This sets the variable CC to gcc, which specifies the C compiler to use for building the program.

* `CFLAGS = -std=c99 -Wall -Wextra -Werror -I../unity`: This sets the variable CFLAGS to a list of compiler 
flags that will be used when compiling the program. `-std=c99` specifies that the C99 standard should be used, 

* `-Wall -Wextra -Werror` enable warnings and treat them as errors, and `-I../unity` specifies that the 
compiler should look in the `../unity` directory for header files.

* `SRC = grasshoper-gradebook.c`: This sets the variable `SRC` to the name of the C source file for the program.

* `UNITY_SRC = ../unity/unity.c`: This sets the variable `UNITY_SRC` to the name of the Unity source file that 
will be used for testing.

* `TARGET = grasshoper-gradebook`: This sets the variable `TARGET` to the name of the executable file that 
will be created.

* `.PHONY: all clean`: This declares the all and clean targets as phony, meaning that they don't correspond 
to actual files and should always be considered out of date.

* `all: $(TARGET)`: This declares the all target, which depends on the `$(TARGET)` file. When make `all` is run, 
it will build the `$(TARGET)` file.

* `$(TARGET): $(SRC) $(UNITY_SRC)`: This specifies that the `$(TARGET)` file depends on the `$(SRC)` and 

* `$(UNITY_SRC)` files. When make is run and `$(TARGET)` is out of date, it will rebuild the file by 
compiling `$(SRC)` and `$(UNITY_SRC)` together.

* `$(CC) $(CFLAGS) $^ -o $@`: This is the command that is run to build the `$(TARGET)` file. `$(CC)` and 

* `$(CFLAGS)` specify the compiler and its flags, `$^` expands to the list of dependencies (`$(SRC)` and 

* `$(UNITY_SRC)`), and `$@` expands to the target name (`$(TARGET)`).

* `clean: rm -f $(TARGET)`: This declares the clean target, which removes the `$(TARGET)` file when run.

