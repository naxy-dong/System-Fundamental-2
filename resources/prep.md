<style>
r { color: Red }
o { color: Orange }
g { color: lightgreen }
y { color: yellow}
c { color: cornflowerblue}
</style>
# C for Java Beginner

1. Forget about **public final static abstract**
2. String in Java is char[] in C
3. There are not boolean data types. In C, 0 means **false** and any other data value are **true**
---
## Formatter
- <o>%d</o> — for numbers
- <o>%s</o> — for strings
- <o>%c</o> — for characters
- <o>%f</o> — for floats
- <o>%li</o> — for long
- <o>%i</o> — for integers
- <o>%p</o> — for addresses/pointers
---
## Pointers
Pass by reference
---
```
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```
---
## 4 stages of compilation
### <c>Preprocessor</c>: converts/replaces the #include\<header file\> with the actual source code from other programs.
### <c>Compiling</c>: Converts the source code into assembly language
### <c>Assembling</c>: Convert the assembly code into machine code (0 & 1s)
### <c>Linking</c>: Combine the machine code from other libraries into your own file.

---
## C libraries
string.h <br>
ctype.h

---
## Passing command line arguments 
```C
int main(int argc, string argv[]){
    //write code here
}
```
- **argc** is the argument count (including the executable file name itself).

- **argv** is list of arguments (including the executable file name itself as the first item)

---

## Exit status
When returning a value in the main function. You essentially wrote the exiting status of the program.
```C
int main(int argc, string argv[]){
    if(SomethingWrong){
        return 1;
    }
    return 0;
}

```
### In the terminal type this to figure out the exit status. 
```bash
echo $?
``` 

---

## Structs
```C
struct Car {
    char brand[50];
    char model[50];
    int year;
}

int main(){
    struct Car car1 = {"BMW", "X5", 1999}
    return 0
}
```

```C
// typedef defines a custom data type
typedef struct 
{
    char name[50];
    char number[50];
}
person

int main(){
    person p1;
    p1.name = "Brian";
    p1.number = "343-125-1235";
    return 0;
}
```
---
## Memory
- <g>\&</g> - <u>address of</u> a variable
- <g>\*</g> - AKA <c>**dereference**</c> operator: goes to an address
-  \0 is for characters,  NULL is for pointers 

Example 1: the & operator
```C
#include<stdio.h>

int main(){
    int n = 50;
    //prints the memory of the int
    printf("%p\n", &n);
    return 0;
}
```
Example 2: pointer
```C
#include<stdio.h>

int main(){
    int n = 50;
    //this is a pointer, a pointer stores an address of a value
    // the type int in this case is the type of variable we're pointing to.
    int *p = &n;
    //prints the memory of the int
    printf("%p\n", p);
    return 0;
}
```
Example 3: pointer w. strings
```C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    //char * is equivalent to string in other languages. It refers to the address of the first character of the string
    char *n = "HI!";

    //prints the address of the string. The address will start at n[0]
    printf("%p\n", n);

    //print out the character one by one
    printf("%c\n", n[0]);
    printf("%c\n", n[1]);
    printf("%c\n", n[2]);

    //print out the character using pointer arithmetic
    printf("%c\n", *n);
    printf("%c\n", *(n+1));
    printf("%c\n", *(n+2));

    //comparing 2 strings are just comparing their addresses. This is why we want to use strcmp() from <string.h>

    //Segmentation fault, touching a segment of memory where you shouldn't have
    printf("%c\n", *(n+4000000));
    return 0;
}

int shallowcopy(){
    char *s = "hi!";
    char *t = s;

    t[0] = toUpper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    //Both s and t will be changed to "Hi!". Why. Because they're addresses pointing the the same string
    return 0;
}

int deepcopy(){
    char *s = "hi!";

    //We need the +1 because of the null character
    char *t = malloc(strlen(s) + 1);
    

    //If malloc is unable to provide us with any more memory
    if(t == NULL){
        return 1;
    }

    for(int i = 0, n = strlen(s); i <= n; i++){
        *(t + i) = *(s + i);
        // is the same as t[i] = s[i];
    }

    //after the for loop, only t will be capitalized
    t[0] = toUpper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    //If you ask for memory, you better give it back. If you don't, it can cause a memory leak
    free(t);

    return 0;
}
```
Example 4: Garbage Values
```C
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *x;
    int *y;

    x = malloc(sizeof(int));
    //notice how y is uninitialized
    // y will be an address containing the garbage value

    *x = 42;
    // the value that the address points to will be 13
    *y = 13;

    y = x; 

    *y = 13;
} 
```
Example 5: Swap with pointer
```C
#include<stdlib.h>

int main(void){
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x,&y);
    // swap(x,y); This is wrong
    printf("x is %i, y is %i\n", x, y);
} 

void correct_swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void wrong_swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
```
---
## File I/O
### Introducing scanf() function
We need the & operator because the scanf needs to assign the value to the reference itself and not the copy of it created in the function.
```C
//get_int();
int main(){
    int x;
    printf("Enter a number: ");

    scanf("%i", &x);
    printf("x: %i\n ", x);
}

void get_string(){
    //char *s; the program will not be happy, because uninitialized addresses are filled with garbage values
    char *s = NULL;
    printf("Enter a string: ");
    scanf("%s", s); // notice we don't need the & operator
    printf("s: %s\n ", x);
}
```

```C
#include<stdio.h>
void main(void){
    //open and goes to the address of the file
    FILE *file = fopen("somefile.csv", "a");
    if(file == NULL){
        return 1;
    }

    char name[50];
    char number[50];
    scanf("Name: %s", s);
    scanf("Number: %s", s);

    //fprintf prints to the file
    fprintf(file, "%s,%s\n", name, number);

    fclose(file)
}
```
---
## Errors
Heap overflow and Stack overflow

Stack goes up
Heap goes down
eventually they're going to collide

Infinite recursion will cause a segmentation fault, as each recursion takes memory in the stack.

Buffer overflow 
Going over beyond the boundaries of an array

---
# Data structure in C
## Linkedlist
### Resizing the array the traditional way
```C
//to use the malloc function
#include<stdlib.h>
int main(void){
    int *arr = malloc(3 * sizeof(int));
    if(arr == NULL){
        return 1;
    }

    list[0] = 1;
    list[1] = 1;
    list[2] = 1;

    int *tmp = malloc(4 * sizeof(int));
    if(tmp == NULL){
        free(list);
        return 1;
    }

    //copy the elements
    for(int i = 0; i < 4; i++){
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    //freeing the original address of the list
    free(list);
    list = tmp;

    //freeing the new address of the list
    free(list);
    return 0;
}
```
### Introducing realloc() function. 
This is the same code but with the realloc() function. 

```C
#include<stdlib.h>
int main(void){
    int *arr = malloc(3 * sizeof(int));
    if(arr == NULL){
        return 1;
    }

    list[0] = 1;
    list[1] = 1;
    list[2] = 1;

    int *tmp = realloc(list, 4 * sizeof(int));
    if(tmp == NULL){
        free(list);
        return 1;
    }
    list = tmp;

    //no need copy the elements
    tmp[3] = 4;

    //no need to free the original list
    free(list);

    return 0;
}
```
## Linkedlist data structure in C
```C
#include<stdlib.h>
//review of struct
typedef struct{
    char name[50];
    char phone_number[50];
}
person;

//the wrong way of declaring a linkedlist
typedef struct{
    int number;
    node *next;
}
node;

//the correct way of declaring a linkedlist
typedef struct node{
    int number;
    struct node *next;
}
node;
```
### Making linkedlist nodes
```C
typedef struct node{
    int number;
    struct node *next;
}
node;

int main(void){
    node *list = NULL;
    /*** linkedlist of size 0 ***/
    node *n = NULL;

    /*** linkedlist of size 1 ***/
    node *n = malloc(sizeof(node));

    //goes to the node pointer and set the number to 1
    (*n).number = 1;
    //another way to write this code
    n->number = 1;
    n->next = NULL;

    list = n;

    /*** linkedlist of size 2 ***/
    node *n = malloc(sizeof(node));
    n->number = 1;
    n->next = list;
    list = n;
}
```
### Linkedlist example dealing with CLI
```C
typedef struct node{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[]){
    node *list = NULL;

    for(int i = 1; i < argc; i++){
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL){
            //still needs to free the nodes created
            return 1;
        }

        n->number = number;
        n->next = list;
        list = n;
    }

    // iterating through a linkedlist
    node *ptr = list;
    while(ptr != NULL){
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    //for loop can also do the trick
    for(node *ptr = list; ptr != null; ptr = ptr->next)

    //free the memory
    ptr = list;
    while(ptr != NULL){
        node *next = ptr.next;
        free(ptr);
        ptr = next;
    }
}
```
## Trees
```C
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}
TreeNode;
```