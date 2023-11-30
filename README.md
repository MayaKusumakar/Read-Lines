# Read-Lines
## Problem
The programming language Python has some really nice functions for dealing with files. One of them is called readlines and it reads the lines of the files into an array. For this project you will be implementing readlines in C.

## Starter Code
Please see main.c and other files from [ReadLinesStarter.zip](https://github.com/MayaKusumakar/Read-Lines/files/13506508/ReadLinesStarter.1.zip)

## Specifications
Your program should work on a file regardless of
  - The file's size
  - The number of lines in the file
  - The number of words in the file
  - The size of a line
  - The size of a word

For this assignment you will be creating a function and not an entire program. Make sure you start from the given starter code

The function you create should have the following signature: 
  - void read_lines(FILE* fp, char*** lines, int* num_lines)

This function should:
  - read all of the lines in the file pointed to by fp and
  - Set each row of lines to contain one line of the file
  - Set num_lines to be equal to the number of lines that were in the file
  - If the file is empty lines should be set to NULL and num_lines to 0
  - You cannot edit main.c

main.c and the Makefile are provided in the [ReadLinesStarter.zip](https://github.com/MayaKusumakar/Read-Lines/files/13506523/ReadLinesStarter.1.zip) and your code must compile using this Makefile and main.c

## Restrictions
  - You may not allocate fixed sized arrays for this problem. If you do you will receive ZERO CREDIT on this assignment.
      - As an example, a fixed size array could be an array of 100 characters or 100 ints regardless of whether you statically allocated it, char array[100], or dynamically allocated it, char another_array = (char*)(calloc(100, sizeof(char)).
  - You can of course still make space in your program, but it shouldn't be an arbitrary, fixed amount that never changes
## Assumptions
Input will always be valid

## Valid Input
File Path: the path to the text file whose lines we want to read
This will be passed as the first command line parameter

# Examples

## Example 1
./read_lines.out Makefile

1. read_lines.out: read_lines.o main.o
2.      gcc -g -Wall -Werror -o read_lines.out read_lines.o main.o
3.
4. main.o: main.c read_lines.h
5.      gcc -g -Wall -Werror -c -o main.o main.c
6.
7. read_lines.o: read_lines.c read_lines.c
8.      gcc -g -Wall -Werror -c -o read_lines.o read_lines.c
9.
10. clean:
11.     rm -f *.out *.o
