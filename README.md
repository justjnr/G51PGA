# G51PGA
Programming &amp; Algorithms Module Coursework

## Introduction

This coursework focuses on writing three interesting programs using loops, arrays and pointers. There are three tasks to complete, details of which are given below.

## Task 1

### Overview

**Pascal's triangle** (see [here](https://en.wikipedia.org/wiki/Pascal%27s_triangle) and [here](http://www.mathsisfun.com/pascals-triangle.html)) is an interesting pattern of numbers named after the French mathematical Blaise Pascal. Your task is to write a program to calculate and print out Pascal's triangle.

Your C source file for this task *must* be named `task1.c` and placed in the top-level directory of your git project for this coursework.

### Details

Your program should calculate Pascal's triangle for a given number of rows specified by the user and print out the triangle in the format described below. There are many ways to calculate the triangle (see the links in the [Overview](#overview) above for a starting point).

You are free to choose whichever method you want to implement your program with the following restrictions:

* you must *calculate* the values in the triangle, rather than e.g. store them in a precomputed lookup table
* your implementation must contain a correctly declared `main` function
* you are not allowed to use global variables

Your program should allow the user to specify the number of rows to print as a command line argument when your program is run. That is, if the user wants to print out the first **5** rows of Pascal's triangle, they will type:

```bash
$ ./task1 5
```

Your program should only allow users to specify integer values between *1* and *20* inclusive for the number of rows to print. If any other value for the number of rows is specified by the user (or no value at all), then your program should print an error message and return a *non-zero* exit value. If a valid value is specified, your program should print Pascal's triangle for the specified number of rows and return an exit value of *zero* (i.e. success).

**Hint**: Use `argc` and `argv` to get the number of rows specified by the user when the program is run. Use the standard library function `strtol` to convert the number of rows entered from a string to an integer and to check that the user has entered an integer. If you write your string to integer conversion code as a function, you can easily reuse it in Tasks 2 and 3 below.

Your program should output the rows of Pascal's triangle to `stdout` in *reverse order*. Here is an example output:

```bash
$ ./task1 5
1   4   6   4   1
  1   3   3   1
    1   2   1
      1   1
        1
```

As in this example, you should output the numbers as a **triangle**.

One possible way of implementing this task is to write *three* functions (in addition to `main`). The first function takes the number of rows `n` input by the user as an argument and calculates and outputs the values in each row of the triangle using two nested loops. The outer loop iterates over the rows i.e. `i = [n, 0]`, and the inner loop iterates over the range `j = [0, i]`. In the inner loop, a second function which calculates `C(i, j)` (the possible combinations of `i` objects from a set of `j` objects) is called repeatedly. This second function uses the standard equation to calculate `C(i, j)`, calling a third function several times to calculate the factorial of a given number i.e. this third function takes a number `x` as an argument and returns `x!`. Be careful with integer overflow, as calculating factorials of even small numbers will produce numbers which may be too big to store in an `int` type.

## Task 2

### Overview

Your task is to write a program which calculates and outputs all the [prime numbers](https://en.wikipedia.org/wiki/Prime_number) in a given interval.

Your C source file for this task *must* be named `task2.c` and placed in the top-level directory of your git project for this coursework.

### Details

Your program should calculate all the prime numbers between two numbers specified by the user and print out the prime numbers. There are many ways to calculate prime numbers, with the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) being a good starting point for an implementation.

You are free to choose whichever method you want to implement your program with the following restrictions:

* your implementation must contain a correctly declared `main` function
* you are not allowed to use global variables

Your program should allow the user to specify the interval `[a,b]` to calculate all the prime numbers in as command line argument when your program is run. That is, if the user wants to print out all the prime numbers between 134 and 298 *inclusive* (i.e. `[134,298]`), they will type:

```bash
$ ./task2 134 298
```

Your program should restrict users to intervals when `b <= 1000000`. Your program should only allow users to specify valid positive integer values for the start and end of the interval. If any other value is specified by the user (or an invalid interval i.e. first number is greater than the second), then your program should print an error message and return a *non-zero* exit value. If a valid interval is specified, your program should print all the prime numbers in the specified interval and return an exit value of *zero* (i.e. success).

**Hint**: use a similar approach as in [Task 1](#task-1) above using `argc`, `argv` and `strtol` to process the command line arguments. Feel free to reuse your string to integer conversion code from Task 1 in this task.

For a valid interval, your program should output the prime numbers in order, one per line. An example output is:

```bash
$ ./task2 175 298
179
181
191
193
197
199
211
223
227
229
233
239
241
251
257
263
269
271
277
281
283
293
```

The execution time of your program will be assessed and points will be awarded based on the execution time as detailed in [Assessment](#assessment) above. Execution time will be calculated as a sum of user CPU time and system CPU time. Multiple runs of your program will be performed, and the minimum execution time will be used. If you want to time your code yourself, you can for example use the Linux `time` command (sum the times given on the *user* and *sys* lines):

```bash
$ time ./task2 143 3982
...
real    0m0.016s
user    0m0.012s
sys     0m0.004s
```

## Task 3

### Overview

Cellular automata are fascinating models which have been studied extensively and have a wide range of applications in many fields. In this task you will implement an [elementary cellular automaton](http://mathworld.wolfram.com/ElementaryCellularAutomaton.html).

Your C source file for this task *must* be named `task3.c` and placed in the top-level directory of your git project for this coursework.

### Details

[Cellular automata](https://en.wikipedia.org/wiki/Cellular_automaton) have a long history in mathematics and computer science and were first discovered in the 1940s by John von Neumann and Stanislaw Ulam, two of the founding fathers of computer science. Since then they have found many applications in diverse field including artificial life, physics and biology. While simple to describe and implement, they are capable of generating amazingly complex behaviour, including chaotic dynamics and universal computation.

For this task you will implement the simplest type of cellular automaton - an [elementary cellular automaton](http://mathworld.wolfram.com/ElementaryCellularAutomaton.html). You should first read [this chapter](http://natureofcode.com/book/chapter-7-cellular-automata/), which will give you a good introduction to what an elementary cellular automaton is (you only need to read up to and not including Section 7.6). It also provides some example code. You should not copy this code directly, but use it to help you understand how to implement your own program.

Your program when run should take *three* values from the user as command line arguments. These values are:

1. the number of cells in the one-dimensional grid (a positive integer)
2. the number of generations to evolve and output the cellular automata for (a positive integer)
3. the Wolfram code specifying which the rule set to evolve your cellular automata with (an integer in the range `[0,255]`).

These three arguments should be specified in this order on the command line when the user runs your program. You should check that the arguments are all valid and within the ranges given. If the user enters the wrong number of arguments or invalid arguments e.g. the number of cells as `-10`, then your program should print an error message and exit with a non-zero exit value.

For the values specified by the user, your program should calculate and print each generation of the cellular automata on a newline. You should print a `*` (asterisk) character to show a cell is alive, and a ` ` (space) character to show a cell is dead. For the initial generation, you should start with a row of cells that are all dead, except for the centre cell (or left of centre cell for an even number of cells) which is alive. You should assume that your row wraps around, that is, the neighbour of the left-most cell is the right-most cell and vice versa.

For example, the output when the users run your program with 30 cells for 20 generations with rule 110 should be:

```bash
$ ./task3 30 20 110
               *
              **
             ***
            ** *
           *****
          **   *
         ***  **
        ** * ***
       ******* *
      **     ***
     ***    ** *
    ** *   *****
   *****  **   *
  **   * ***  **
 ***  **** * ***
** * **  ***** *
******* **   ***             *
      ****  ** *            **
     **  * *****           ***
    *** ****   *          ** *
```

You are free to choose whichever method you want to implement your program with the following restrictions:

* your implementation must contain a correctly declared `main` function
* you are not allowed to use global variables

Some hints for possible ways to implement your program are given below.

You could store the states of cells in the current and next generations in two arrays. The length of each array will be the number of cells specified by the user. Since this length is specified at runtime, you will need to allocate the memory for these arrays dynamically using `malloc` or `calloc`.

The main computation in your program could be performed by two nested loops. The outer loop would iterate over each generation. For each generation, an inner loop would iterate over all the cells in the current generation array. Based on the state in the current generation of each cell and its two neighbours, you can calculate the state in the next generation and store this in the next generation array. After calculating the next generation states for all cells in the current generation, you can then print out the next generation. Finally you can copy the next generation array to the current generation array, and perform the whole procedure again for the next generation.

To calculate the state of a cell in the next generation from it and its neighbours current state, you can use some simple binary manipulation. For example, say you were using the ruleset with Wolfram code 110 and you wanted to calculate the state in the next generation of a dead cell with two live neighbours i.e. `101`. First, treat `101` as a binary number and convert it to decimal i.e. `5`. Now right shift the rule number i.e. `101` by `5` and look at the value of the least significant bit i.e. `1`. This is the state of the cell in the next generation.  A complete set of pictures for each Wolfram code is given [here](http://mathworld.wolfram.com/ElementaryCellularAutomaton.html). [Rule 90](https://en.wikipedia.org/wiki/Rule_90) and [Rule 110](https://en.wikipedia.org/wiki/Rule_110) are particular interesting.

## 
Resporitory for Archival Purposes, All Rights Reserved.
