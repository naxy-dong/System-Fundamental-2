# Unit 1
## 1/24/23
220 people...
## 1/26/23
packages in Java are used to avoid name clashing with other java files.

C doesn't have that packages. So be careful with global namespaces

If you access the out of bound of the array, C will not tell you an error! But it improves runtime significantly.

The compiler decided how many bytes of integer does this machine have. So the size of integer will cause some conflicts with other platforms.

C preprocessor processes the macros.
### Danger of C
1. Pointers are muc hmore dangerous because you can access a null object pointer points to.
2. Malloc to allocate memory and you will need to give it back in the end.

gcc hello_world.c gcc stands for GNU compiler

cc is also a C compiler

a.out. You can just run it by using a. But it runs into some problems such as the filename has the name of the system commands (like **ls**). 

So if we want to run the 
./a.out

gcc -o myprog myfile1.c myfile2.c

If you want to have a large build
you don't want to recompile files that you have not changed.
gcc -c myfile.c
gcc -c myfile2.c
gcc -o myprog mfile1.o myfile2.o

### Java compiler
Java aims to produce platform independent code. It produces bytecode that can be interpreted in the JVM.

**Advantages:**
bytecode is the same regardless of the machine it's running.

**Disadvantages:**
Intepretations is slower than direct execution

### C compiler
**Advantages:** It's fast because it produces machine code.

**Disadvantages:** The C compiler: there are difference versions of machine code. Like (Intel or SPARC). So you need to distribute the corresponding machine in order to work.

loaded on-demnd
references are resolved automatically at first use by the JVM.

## 1/31/23
cross-compiler:
entrypoint is main

The entire program is like static class.
**One-pass compilation**.

C requires **declaration before use**. 

You place extern in front of a function. It's saying to the compliler that the function isn't defined here, but here's some information about it.
### Macro Definitions
Definition vs Declaration
**variable definition** declares the name and type.
```C
int x;
```

**function definition** declares the name, parapmeter, and reutrn type of a function and provide code
```C
void inc(int x) { return x + 1;};
```

I can only define the variable and function once. 

**declarations**
```C
// Using extern
extern int x;
extern void inc(x);

// Using function prototype
void inc(int x);
```
static keyword - deals with global variables

**#include** directive is going to insert the content from the other file

**header guards** prevents the program to **#include** the file more than once

```C
#define HELLO "Hello world\n"
```
macro expansion, literally collect definitions and substitute wherever need it.

### conditional compilation.
```C
#if #ifdel #else #elif #endif

#define OS linux

#if OS == linux
    puts("Linux!");
#else
    puts("Something else");
#endif
```

```C
#define name const-expression
#define name(param, param2, ...) const-expression
#undef symbol  // this undo the definition

// It's best practice to put parenthesis to avoid parsing error.
#define valid(x) ((x) > 0 && (x) < 20)

//we don't want to treat macro as function definition. 

// The use of macros by substitute using a++ 
//we increment it twice because of pass by name (we delay to calculation as soon as possible)
valid(x)
||
valid(a++) ==> ((a++) > 0 && (a++) < 20)
```

### Predefined macros
```C
__LINE__ // current line number of source file
__FILE__ // name of the current source file
__TIME__ // time of translation
__STDC__ // 1 if the compiler conforms ANSI C
```

### File inclusion
```C
#include "mydefinitions.h"
#include "hw1/useful.h"
```

### Disadvantages Preprocessor
1. It's confusing to read.
2. not visible in debugging

limit to .h file
isolate .h files with OS files.
### variables
1. Java
    1. initialize variables to a default value
    2. prohibits use of uninitialzed local variables
2. C
    1. global variables is not initialized and can be some garbage values
## 2/2/23
Defining new types
```C
// the new type that's defined is at the end of declaration
typedef short int smallNumber;
//short int is the existing type

typedef unsigned char byte;

typedef char String[100];

smallNumber x;
byte b;
String name;

typedef char boolean;
#define FALSE 0;
#define TRUE 1;

check = x > 0; // x > 0 is not always going to give you 1
if (check == TRUE){}
//It's not guaranteed to work
```

```C
typedef enum{
    Red, Orange, Yello ...
} Color;
// This defaults to a number
// We need the typedef here!!!
enum weather {rain, snow = 2, sun = 4};
```
C is weakly typed, meaning that the compiler assumes the programmer knows what he/she is doing.

Allows casting of anything to anything else (AKA coercion).

In C, type checking errors will print warning only AND continue.

There is a flag -w in gcc that makes warning as errors.

```C
int x;
char *y;
x = y // integer to an pointer. Compiler will warn them. 
```

Lifetime of a variable

- outside of any function: Lifetime :becomes alive when program is loaded and lasts until the program terminates.

- Inside of any function:
becomes alive when function is called and lasts until the function returns.
```C
Sizeof (A) gives the number of bytes in the array
can computer the length = sizeOf(A)/ sizeOf(A[0])

//Function with arrays you need to pass in the length
printArray(A, VECSIZE){}
```

variable
```C
name and type
address
size
storage class (static or auto)
scope
lifetime
```

- stack - local vars
- static - global vars

```C
static int x; // allowed, static mean multiple things?
auto int x; // NOT ALLOWED, auto needs to be in a function
extern X; // someone else is doing it 
// the variables inside the function have local scope. IMPORTANT
int f(){
    int x; // auto, belongs to the stack.
    register int x; // compilers were bad. hint to the compiler that we're going to use this variable a lot but keep it in the CPU register(faster) instead of putting it on the stack. Not used because compiler is very good at optimizing the variables now.
    static int y; //static, BUT have global lifetime.

    extern static int y;
    // extern is just saying someone else is doing it.
}
```
Employees click on suspicious email links
Data matching data mining 
Do we, or should we have control over our data?

Main source of surveillance.
Government 
domestic surveillance

Giving up data means that 
- the third party can use it.
- Data collections
  
Informed consent: You need to be well aware of it. In a medical context, people often is not informed enough because of the lack of specialty

### How data is stored
begin```----------```

stack

```----------```

Heap

```----------```

data/bss

```----------```

text

```----------```End

### Stack
stack grows from high number address to lower number addresses.
- frame pointer
- stack pointer
- storature class **auto**
- read/write short-lived varaibles
### Heap
- read/write long-lived data. (malloc/free)
### Data section
- Initialized data segment
- Unintialized data segment is called BSS
- read/write long-lived variables
- Storage class **static**
### Text
- Program Counter
- Read only
- Executable
- Binary
  
SPRK sets the break pointer so that it can move the break pointer to leave more space to the heap and the stack
```C
// stores in the data segment
static int x = 3;
// stores in the BSS segment
static int x;
```

Programmer must ensure that variables are initialized before use.

