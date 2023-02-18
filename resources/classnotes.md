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

```C
The sizeof function takes care of size of x in compile time. Has data type size_t 
```
size_t is an unsigned type

Do more research about ```size_t```

& is ```address of``` operator

if * is on the left handside,
*ip = 3 will say, set the value at the address ip equals to 3

j = *ip, on the left handside, we will access the value ip and set j to that value.
```C
int array[10];
int *ptr = array;
ptr++;

// You can subtract 2 pointers to get an int
int x = ptr - array;
//x = 1
```
when you do pointer arithmetic, there will be implicit multiplication to let be the correct size. 

There is a difference between
(*argv)++  and *argv++

the latter increment argv first, then points 

void * is a generic pointer type
```C
void *v;
char *s = v;

char str1[100];
char str2[100];

memcpy((void*)str2, (void*)str1, 100)
```
memcpy

### Call-by-Value
```C
//C uses call-by-value

int inc (int x);

int main(void){
    int a = 3;
    inc(a);
}

int inc(int x){
    x++;
    return x;
}
```

- An actual parameter expression is eval to obttain is **R-value/L-value**, which is the actual parameter
- The actual parameter is transmitted to the called function, and used to initialize the formal parameter, which subsequently behaves like a local variable
- R value is an expression evaluated on the right hand side of the statemnt
- L value is an expression evaluated on the right hand side of the statemnt

``` 3 = 4; ```
will throw an error is because the left hand side is a R value.

### Call be reference
```C
int inc (int *x);

int main(void){
    int a = 3;
    inc(&a);
}

int inc(int *x){
    *x = *x++;
    return x;
}
/*
the L value of *x is just what the x points to.
the R value of *x is the value of the variable
*/
```
### Arrays in C
```C
Arrays in C
int a[10];
// sizeof(a) == 10 * sizeof(int)
char c[100];
// sizeof(c) == 100 * sizeof(char)
float *p[10];
// sizeof(p) == 10 * sizeof(float *) 
float * is a pointer, every pointer has 8 bytes.
```

Fun fact: Loop using pointer is faster than loops using indices
```C
int *v, *last;
int sum = 0;
last = &vec[VECSIZE];
for (v = vec; v < last; v++)
    sum += *v;
```

```C
int month[12];

month[3] = 7;

//Type of month is an int;
ptr = month + 2;

ptr[5] = 12;

ptr++;

(ptr + 4)[2] = 12;
```

let's say weekends is int[52][2]
```C
weekends[2][1] = *(*(weekends + 2) + 1)
//How? Trace:
weekends[2][1]
==> *(weekends[2] + 1)
==> *(*(weekends + 2) + 1)
```

--Something called flex array, basically the array passed in the arguent without having to specify what's the size of the array.

passing 2D array into a function
flex array would need to specify 
```C
int f(int Matrix[size_needed][]){

}
```


### File I/O
```C
char c = 'a';
// How to get a character way #1
while(fscanf(in, "%c", &c) != EOF){
    printf("%c", c);
}
// How to get a character way 2
while(1){
    c = fgetc();
    if(c == EOF){
        break;
    }
}
```
## 2/14/23

### String literal in C
```C
char *MakeBig(char *s){
    s[0] = toupper(s[0]);
    return s;

    makeBig("a cat")
}
```
compiler would make string literal in the read only part of the memory.

```C
char *str = "My string"
char *s;
s = &str[0];
s = str;

s = &str[0]; s = str;
```


```
char *s;
for (s = str; *s; s++)
    putchar(*s);
```

### Copying strings
```C
char myBuffer[100];
mybuffer = "a cat";

// copy a string
char str[100] = "a cat";
char *s = str;
char *t;
t = s;

// better way to copy a string
strcpy(myBuffer, "a cat")
// myBuffer must be big enough to strore , so it's not totally safe.
strncpy(myBuffer, "a cat", sizeof(myBuffer))
/// this is different argument that you can pass in additional argument telling the method not going over the size of the buffer

strdup()// creates memory for you.
```
### Read the man page for the string.h library.

### Demonstration
```C
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    char line[100];
    char *family = NULL, *given, *gap;
    printf("Enter your name: ");
    // limits how much you can type the input. If not, there's a stack overflow and there would be a big security risk.
    // Don't use gets(). It allows user input size to be unlimited.
    fgets(line, sizeof(line), stdin);
    given = line;

    [J,O,E, ,B,L,O,W,\n,\0] ->
    [J,O,E,\0,B,L,O,W,\0,\0]
    Family/(Family name) will point to BLOW. 
    for(gap = line; *gap != '\0'; gap++) {
        if(*gap == '\n') {
            *gap = '\0';
        // a whitespace includes space character, line feed, new line characters, tabs.
        } else if(isspace(*gap)) {
            *gap = '\0';
            family = gap+1;
        }
    }
    printf("Your name: %s, %s\n", family, given);
    return 0;
}
```

thorn character ascii.
### structs and union 
### standard I/O stuff
"pipeline"
```bash
$prog1|prog2
```

```C
#include <stdio.h>
```
- Defines FILE * type
- Define stdin, stdout, stderr
- Always defind streams: stdin, stdout, stderr
- fflush() is useful 
- fseek() skip to the a position at a distance
  - only diff files are seekable
- ftell() tells how far away from the beginning am I 
  

### if file is connected via terminal
- it will fflush() 
### if file is connected via disc file
- you'll have to close it
```C
 fprintf(stdout,"Who are you?")
 fflush(stdout)
 // get user input data
```

FILE is in the app layer

--- User ---\
--- OS ---\
--- Hardware ---
```C
FILE *fopen(const char *path, const char *mode)

int fclose();
- close the stream FILE *;
- return 0 if successful, EOF if not;

EOF = int - 1

first Assign EOF
int c;
while((c == getchar()) != EOF){
    char x = c;
}
```
getchar will return EOF, EOF to char is a legitimate character so both version might be conduced.

## 2/16/23
### End of files

```C
don't do:

while(!feof(stdin)){
    fgetc(stdin);
}
```

[CTRL-D] fast forward the end of the file.

### struct
```C
struct {
    int x;
    char y;
    float z;
} rec;
```
- similar to Java objects/class defintions.
- Components can be any type but (not recursive)
- accessed using the same syntax struct.field

```C
// Define struct this way - has to specify complex.
struct complex {double real; double imag;};
struct complex a, b;

// a and b has a type of "struct complex"

// Define struct this way
typedef struct {double read; doubl eimag;} Complex;
Complex c;

// a and b has a type of "Complex"
```
You can't define recursive typedef.
```C
struct complex{
    real x;
    imag y;
    struct complex *next;
}
```
A pointer works. Think about how it will turn out in memory without pointers.
```C
struct Tnode{
    int data;
    struct Tnode *left;
    struct Tnode *right;
};
// how to create a variable
struct Tnode n;

typedef struct Tnode{
    int data;
    struct Tnode *left;
    struct Tnode *right;
} TNODE;
// how to create a variable.
TNODE n;
```

```C
struct {
    char x;
    int y;
    char z;
} s1;

struct {
    char x, z;
    int y;
} s2;

sizeof(s1) = ?
sizeof(s2) = ?
```
**Their sizes are different!!**
Because of something called a **natural alignment**, which is a value of size 2^n ahs to be stored at the address which is a mult 2^n.

char has 1 byte, so it a size of 1 byte

int has 4 bytes, so it has to be assigned to an address that's in the multiple of 4
```C
int size_diff = (char *) &y - (char *) &x;
```
### Nested struct
```C
struct person{
    char name[41];
    int age;
    float height;
    struct {
        int month;
        int day;
        int year;
    } birth;
};
```
### OS programming
```c
// example of a network packet.
typedef struct{
    unsigned int version:2;
    unsigned int p:1;
    unsigned int cc:4;
    unsigned int m:1;
    unsigned int pt:7;
    u_int16 seq;
    u_int32 seq;
} rtp_hdr_t;
```
- the colons is just to specify the size of those fields;

x &= ~0x6
0x3 << 8

### Dereferencing pointers to struct
```C
(*sp).element = 42;
y = (*sp).element;
//is the same as 
sp->element = 42;
```

### Unions
union u_tag{
    int ival'
    float fval;
    char *sval;
}u;

Concepts: only one field will be used.
- only need to allocate space for the biggest one. 
- Allows the same region of memory to hold different objects.
- All elements occupy the same memory spaces
  
Ex: ) a tree with differnet kinds of a node.
```C
enum union_type { WHILE, IF, ELSE that}
// we did enum because of name conveniency: we know that WHILE = 0, IF = 1, etc.
struct Node{
    union_type type;
    union syntax{
        struct while w;
        struct if i;
        struct elsethat
    }
}
```
C doesn't keep track of what type is the union. So usually you would create a type variable and a struct variable 

ask more about 
The use of fscanf(), fgets() and sscanf();