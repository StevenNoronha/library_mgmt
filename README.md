# Library Management System

This program is a simple Library Management System that allows you to store and issue books to students. The program is written in C and uses data structure (linked lists) to store information about books and students.

## Features
1. Add new books to the system 
2. Add new students to the system
3. Issue books to students
4. Display the list of all available books
5. Display the list of all issued books and to which student they were issued



## Code Structure
The code is organized as follows:
There are two structures defined - one for books and one for students.
The program uses a linked list to store information about books and students. The firstb and lastb pointers point to the first and last elements of the book linked list respectively. Similarly, firsts and lasts pointers point to the first and last elements of the student linked list respectively.

The main functions of the program are:
* void issue() - to issue a book to a student
* void displayl() - to display the list of issued books to a particular student
* void display() - to display the list of all available books
* void displays() - to display the list of all issued books with the student names they were issued to.
