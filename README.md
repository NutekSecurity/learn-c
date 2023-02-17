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
