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
