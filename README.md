# learn-c

## My code while learning C and some data for you

Szymon Bronisław Błaszczyński © 2023 museyoucoulduse@gmail.com

___


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

[![asciicast](https://asciinema.org/a/562498.svg)](https://asciinema.org/a/562498?autoplay=1&speed=2&theme=solarized-dark)

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

### Precision of floating point number

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

    - [Neovim](https://neovim.io/)

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
what's working in our programs and what's not. _Don't Reapeat Yourself_ and write down the exact flow of
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
CFLAGS = -std=c11 -Wall -Wextra -Werror -I../unity

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

## Dockerfile

Docker is a popular open-source platform for building, shipping, and running distributed applications. 
It allows developers to package applications and their dependencies into a portable container that can
run on any machine, regardless of the underlying operating system and hardware.

Here are a few common use cases for Docker:

1. Application deployment: Docker simplifies the deployment process by allowing developers to package their
applications and their dependencies into a single container. This container can then be easily deployed 
to any environment, whether it's a development machine, staging environment, or production server.

2. Microservices architecture: Docker's lightweight containers make it easier to break down monolithic
applications into smaller, independently deployable microservices. Each microservice can be packaged 
and deployed as a separate container, allowing for greater flexibility and scalability.

3. Continuous integration and deployment (CI/CD): Docker can be used in a CI/CD pipeline to automate 
the build, test, and deployment process. Developers can create a Docker image of their application, 
and then use that image to deploy the application to multiple environments automatically.

4. Development environments: Docker can be used to create consistent development environments across 
multiple machines. Developers can create a Docker image that includes all the tools and dependencies 
they need to develop their applications, and then use that image to spin up development environments 
on any machine.

5. Cloud computing: Docker is widely used in cloud computing environments such as AWS, Google Cloud Platform,
and Microsoft Azure. By using Docker containers, developers can create scalable, fault-tolerant applications
that can run on cloud infrastructure.

Overall, Docker provides a powerful tool for developers and system administrators to manage their
applications and infrastructure, and is widely used in modern software development and deployment practices.

From now on, I'm assuming you're using Linux, Unix or something like that. No, not really. As you've read
you should probably get the impression that I'm going to ask you to install another tool. But that's not
your oridinary LAMP server on your bare metal Windows box. You can have [Docker](https://www.docker.com/) 
([Podman](https://podman.io/) too) on your Windows too. All you need is that `git` for source version control
and OCI containers...

### What is OCI container

OCI (Open Container Initiative) container is a standard for container image format and runtime specification. 
It is a set of open standards and specifications for creating, packaging, and running containerized 
applications.

The OCI was formed by a group of companies and organizations in the container ecosystem to create open 
standards for container technology, and it is now a Linux Foundation project. The OCI container standard 
defines a common specification for the format and runtime of container images, ensuring that they are 
interoperable across different container runtimes.

The OCI image format defines the structure and layout of container images, while the OCI runtime 
specification defines how the container should be run and managed. The OCI standard provides an 
interoperable, vendor-neutral container format that can be used by any container runtime, enabling 
developers to build and distribute containerized applications without worrying about the underlying
infrastructure.

The OCI container standard is widely used by container platforms and orchestrators such as Docker,
Kubernetes, and containerd, which use the standard to ensure that container images and runtimes are
compatible and interoperable. By using the OCI standard, developers can ensure that their containerized
applications can run on any container runtime that supports the standard, providing greater flexibility
and portability.

### What is Fedora

Since my recent switch to dnf-based systems, I have tried CentOS Stream 9, Alma Linux, and Fedora, and this
one, Fedora, will be the one I will use since it's aimed at more day-to-day usage and broader package
coverage because it's base for the Red Hat Enterprise Linux package development management. The first
step is Fedora, then, CentOS Stream and RHEL at last (also Rocky and Alma Linux).

### What is DNF

DNF (Dandified Yum) is a package manager used on some Linux distributions that are based on the Fedora
operating system, such as Fedora itself, CentOS, and Red Hat Enterprise Linux (RHEL). It is the next
generation version of the Yum package manager, which was the default package manager on these distributions
prior to the introduction of DNF.

DNF is designed to provide improved performance and usability compared to Yum, while still maintaining
compatibility with existing Yum repositories and packages. Some of the key features of DNF include:

1. Faster performance: DNF is designed to be faster and more efficient than Yum, with better performance
for tasks such as package installation, updates, and dependency resolution.

2. Improved dependency handling: DNF includes improved dependency handling, with better tracking of
dependencies and conflicts between packages.

3. Modular architecture: DNF has a modular architecture, which makes it easier to extend and customize
for different use cases and environments.

4. Better error handling: DNF includes improved error handling, with more informative error messages
and better error reporting.

5. Support for other package formats: DNF can also work with other package formats besides the RPM
format used on Fedora-based systems, such as the Snappy format used on Ubuntu.

Overall, DNF provides a modern, powerful package management tool for Fedora-based systems, with
improved performance and usability compared to its predecessor, Yum.

### What is Linux

Linux is an open-source operating system kernel created by Linus Torvalds in 1991, and is the basis
for many popular Linux-based operating systems, commonly referred to as "Linux distributions". 
Linux is a Unix-like operating system, which means it shares many similarities with the original
Unix operating system, such as a hierarchical file system, a command-line interface, and a focus
on modular design and composability.

Linux is a popular choice for both personal and enterprise computing, as it is highly customizable,
secure, and can run on a wide range of hardware, from embedded devices and smartphones to servers and
supercomputers. Linux is widely used for web servers, cloud computing, scientific research, and
embedded systems, among other applications.

One of the key strengths of Linux is its open-source nature, which means that the source code is
freely available and can be modified and distributed by anyone. This has led to a vibrant ecosystem
of developers, companies, and communities working together to improve and maintain Linux, resulting
in a highly stable, reliable, and flexible operating system.

Linux is also known for its wide range of available software, including many free and open-source
applications, making it a popular choice for developers and users who value freedom, flexibility,
and community-driven innovation.

### What is GNU/Linux

GNU/Linux is a term used to refer to a complete operating system that is built on top of the Linux
kernel and includes a set of GNU tools and software. The GNU project was started by Richard Stallman
in 1983, with the goal of creating a free and open-source software ecosystem, and has since grown
into a large and influential community of developers, users, and advocates.

The Linux kernel, created by Linus Torvalds in 1991, provides the low-level services and interfaces
that allow the operating system to interact with the hardware of a computer or other device. The GNU
tools and software, which were developed independently of the Linux kernel, provide the higher-level
functionality that is typically associated with an operating system, such as user interfaces, file
systems, utilities, and programming tools.

The combination of the Linux kernel and the GNU software creates a powerful and flexible operating
system that is widely used in both personal and enterprise computing. The open-source nature of GNU/Linux
has led to a vibrant ecosystem of developers, companies, and communities that contribute to its
development, support, and distribution, resulting in a highly customizable, reliable, and secure
operating system.

GNU/Linux is used in a wide range of applications, from personal desktops and laptops to servers,
mobile devices, and embedded systems. It is known for its stability, security, and flexibility,
as well as for the wide range of available software and the passionate community of users and
developers who support it.

### Sum up the briefing

I hope that you now see, that what we'll be using is really useful and combinig all the skills
you will really distinguish yourself in the community so you might do your work faster, organize
better and deliver in full, not in parts. Now might be a good time to get you up and going with the
last tool I have introduced to you, `git`. It's ment to help collaborate and share source code, but it's
usege surpass that, and now even books are written using git, just like this one. What it do?
It keeps track of your changes to files, it is able to send data to git servers, such as [GitHub](https://github.com) or [GitLab](https://gitlab.com/kalilinux). Unfortunately, or not, it doesn't do this automatically.

[![asciicast](https://asciinema.org/a/562489.png)](https://asciinema.org/a/562489?autoplay=1&speed=2&theme=solarized-dark)

1. Initialize new .git repository (note that you do this only once, and some tools do this for you)

    - `git init`
    - you might have to set your username and email
        * git config --global user.name "FIRST_NAME LAST_NAME"
        * git config --global user.email "MY_NAME@example.com"

2. Stage your files for commit
    
    - `git add path/to/your/file another/file .gitignore` or
    - `git add *` - this will add all files except those in `.gitignore` but not always all, so check with:
    - `git status`

3. Commit your change

    - `git commit -m "Initial commit"`, where `-m` stands for message

4. Add remote

    4.1. create git repository on GitHub, it may be private (for free)
    4.2. follow the instructions on screen, or click the green button and copy the https link
    4.3. `git add remote origin https://your.link.git`, origin stands for name of the remote

5. Pull code from GitHub

    5.1. `git status`, and note the branch you're currently on, or:
    5.2. `git branch -l`, and check if the desired name is free
    5.3. `git pull origin main --rebase`, this is usually the main or master branch,
        but you might want to use another local branch, and `--rebase` option let's you
        choose which changes you wish to preserve from upstream or local branch
    
    - you might need to merge branches, so do `git checkout main` to change to main branch,
        and then, `git merge upstream`

6. Push code to GitHub

    - `git push origin main --set-upstream`, this will upload the code to GitHub and let you
        use just `git push` to send source code to GitHub.

### Repeat, what is git, elaborative description

Git is a distributed version control system that allows developers to manage and track changes to code
and other files over time. It was created by Linus Torvalds in 2005 to manage the development of the
Linux kernel, and has since become one of the most widely used version control systems in the software
development industry.

Git enables multiple developers to collaborate on the same project by allowing them to create their own
local copies (or "clones") of the code repository. Each developer can then make changes to their local 
copy and push those changes back to the central repository. Git uses a system of branching and merging 
to manage changes, allowing developers to work on different features or bug fixes in isolation and 
then merge their changes back into the main codebase when they are ready.

Some of the key features of Git include:

- Distributed architecture: Git stores a complete copy of the code repository on each developer's machine,
allowing them to work offline and reducing the risk of data loss or corruption.
- Branching and merging: Git allows developers to create multiple "branches" of the codebase to work
on separate features or bug fixes in isolation, and then merge those changes back into the main codebase
when they are ready.
- Version history: Git tracks every change made to the codebase, allowing developers to view a complete
history of all changes and revert to previous versions if necessary.
- Collaboration: Git enables multiple developers to work on the same project concurrently, sharing their
changes and resolving conflicts as needed.

Overall, Git is a powerful tool that enables developers to work more efficiently and collaboratively, 
while also providing a robust and reliable system for managing and tracking changes to code over time.

### When you're done

After the initial setup of `Podman & git` you can spin up this simple container. It consist of `Fedora`, 
GNU/Linux, `Development Tools` - our main focus here is `make` - for _Makefiles_ and `gcc` for __C__, 
and `Ruby` - dynamic programing language. Why another language? I want to show how to call C code from
other programming languages, and it's much more easier, and sane, to create a website using Ruby than using C.
We will also explore using JSON in C and in Ruby. We will create a KISS website containing data
download using `libcurl from ifconfig.me service and Apple Music API. Everything will be executed inside
a container with much less configuration needed to be performed and much safer way to publish your code.
We won't forget to make few unit tests, and to be honest, I'm learning this Test Driven Development with you.

1. Create file named Dockerfile in a folder that is available to share in Docker or Podman. There you
will store the rest of this new project.

```Dockerfile
FROM fedora:latest

WORKDIR /app

RUN dnf groupinstall -y 'Development Tools'
RUN dnf install ruby && gem install bundler

RUN bundle install

EXPOSE 9292 # not neccesairly needed, good practice

ENTRYPOINT [ "bundle exec rerun -- bundle exec rackup config.ru" ]
```

When you save this file in your system, then you can build it with `docker build --tag c-dev .` from the
same directory of the `Dockerfile`. This will build for you a Docker image with `Fedora` system and
development tools installed. To run this you use `docker run -it --name dev -v $(pwd):/app -p 9292:9292 c-dev`.
This command will create a dev container (change name how you like it), from the
build image. I have deliberatedly omitted --rm option, which would remove our container after stopping it.
If you want to remove this container, use this commad: `docker rm --force dev`.

Let's not jump quickly into conclusions, that this container will actually run. It wouldn't. 💄 RED -> 🐢 GREEN
-> 💫 REFACTOR. Remember? I have story to be laid out, and you have a lesson to learn. Bear with me, a little bit longer.

For the excuses I have another container that you can run, and it will be cURL image, the program that we will use,
thus we stay in the scope of this excercise. To run cURL container you will simply use this command (you have to
be connected to the Internet), so it before with `docker pull rancher/curl:latest`, this one will be very fast
because the image is of 5.33 MB. Now that you have the cURL program from image, you can run it:

```bash
docker run --rm -it rancher/curl ifconfig.me
```

[![asciicast](https://asciinema.org/a/562493.svg)](https://asciinema.org/a/562493?autoplay=1&theme=solarized-dark)

What you should expect? You will get the text response with your current IP number terminated by `%`.

## Shared and dynamic libraries

Dynamic and shared libraries are both types of libraries that contain code and data that can be shared among
different programs. However, there are some key differences between these two types of libraries:

1. Loading time: Dynamic libraries are loaded into memory at runtime when a program starts, whereas shared
libraries are loaded at link time when a program is built. This means that dynamic libraries can be loaded
and unloaded as needed, while shared libraries are loaded into memory for the entire lifetime of the program.

2. Memory usage: Because dynamic libraries are loaded into memory at runtime, they can be loaded and unloaded
as needed, which can help conserve memory usage. Shared libraries, on the other hand, are loaded into memory
for the entire lifetime of the program, which can lead to higher memory usage.

3. Linking: Dynamic libraries are linked dynamically at runtime, which means that the library can be updated
without recompiling the entire program. Shared libraries, on the other hand, are linked statically at link
time, which means that any changes to the library require recompiling the entire program.

4. Platform independence: Dynamic libraries are platform-independent, which means that a single dynamic
library can be used across multiple platforms without recompiling the library. Shared libraries, on the
other hand, are platform-specific, which means that a separate shared library needs to be compiled for each
platform.

In summary, dynamic libraries are loaded at runtime, can be loaded and unloaded as needed, and are
platform-independent, while shared libraries are loaded at link time, are loaded into memory for the
entire lifetime of the program, and are platform-specific.

### Compile shared library

To compile a shared library from a C file, you can use the "-shared" flag with the GCC 
(GNU Compiler Collection) command. Here's an example of how to do this:

1. Write your C code in a file named "my_library.c". For example:

```c
int add_numbers(int x, int y) {
    return x + y;
}
```

2. Compile the C code as a shared library using the GCC command with the "-shared" flag:

```bash
gcc -shared -o libmy_library.so my_library.c
```

This will create a shared library file named "libmy_library.so" in the current directory.

The "-shared" flag tells GCC to produce a shared library instead of an executable. The "-o" 
flag specifies the output file name.

Note that the file extension for shared libraries can vary depending on the platform. On Linux 
and other Unix-like systems, the file extension is typically ".so". On macOS, the file extension 
is typically ".dylib". On Windows, the file extension is typically ".dll".

Once you have compiled the shared library, you can link it with other programs that use the library.

### Compile dynamic library

Dynamic libraries, also known as shared object files (or shared libraries on Windows), are libraries
that are loaded into memory at runtime when a program starts or when the library is first used. Dynamic
libraries can contain code and data that can be shared among different programs, which can help reduce
the size of executables and reduce memory usage.

1. Write your C code in a file named "my_library.c". For example:

```c
int add_numbers(int x, int y) {
    return x + y;
}
```

2. Compile the C code as a dynamic library using the GCC command with the "-fPIC" (position-independent code)
and "-shared" flags:

```bash
gcc -fPIC -shared -o libmy_library.so my_library.c
```

This will create a dynamic library file named "libmy_library.so" in the current directory.

The "-fPIC" flag tells GCC to generate position-independent code, which is required for building shared
libraries. The "-shared" flag tells GCC to produce a dynamic library instead of an executable. The "-o"
flag specifies the output file name.

Note that the file extension for dynamic libraries can vary depending on the platform. On Linux and other
Unix-like systems, the file extension is typically ".so". On macOS, the file extension is typically ".dylib".
On Windows, the file extension is typically ".dll".

Once you have compiled the dynamic library, you can load it into a program using a dynamic linker, such as 
the "dlopen" function in C or the equivalent functions in other programming languages. The dynamic linker 
will load the library into memory at runtime and resolve any symbols that the program needs from the library. 
This allows programs to share code and data with dynamic libraries, which can help reduce memory usage and 
make it easier to update and maintain the shared code.

### RuboCop

[RuboCop](https://rubocop.org/)
