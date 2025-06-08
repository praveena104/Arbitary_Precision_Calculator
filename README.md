# Arbitary_Precision_Calculator--->Data_structures & Algorithms

This project implements an Arbitrary Precision Calculator (APC) that performs mathematical operations on integers of any size, limited only by system memory.In contrast to built-in arithmetic in ALUs (Arithmetic Logic Units) which is restricted by data types like int or long, this calculator supports big-number arithmetic by representing numbers as linked lists and implementing custom algorithms for arithmetic operations.
This type of arithmetic is crucial in fields like cryptography, especially in public-key systems such as RSA, which operate on very large integers.

Technology Used:

Key Concepts:

    Data Structures (Linked List)

    Abstract Data Types (ADT)

    Order Complexity Analysis

Programming Language: C

Core Areas:

    Manual memory management

    Algorithm design for big-number operations

 Features:
 
    ➕ Addition of large numbers

    ➖ Subtraction with sign support

    ✖️ Multiplication using digit-by-digit approach

    ➗ Division with remainder

    🧮 Modulus operation

    ⚡ Exponentiation (Power function for big integers)

    🧱 Numbers represented using Doubly Linked Lists

    📉 Emphasis on Time and Space Complexity

    🧠 Clean abstraction using ADT principles

Note:

In this repository only addition and subtraction is focused.

makefile is created to generate .o files. It is compiled using command called make.

makefile:

OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
slist.exe: $(OBJ)
        gcc -o $@ $^
clean:
        rm *.exe *.o


