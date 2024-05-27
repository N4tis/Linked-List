# Linked-List
Linked lists are fundamental data structures used in various computer science applications. This library provides an easy-to-use and efficient implementation of linked lists in C, making it a valuable resource for developers who need to manage dynamic collections of data. The library can be integrated into larger projects or used for educational purposes to understand linked list operations.

This project provides a C library for managing a singly linked list data structure. It includes functions for creating, manipulating, and cleaning up linked lists.

The Linked List Library offers a set of functions to perform various operations on a linked list, including:
-    Creating a new node
-    Inserting nodes at the beginning, end, or a specific position
-    Removing nodes from the beginning, after a specific position, or from a specific position
-    Reversing the linked list
-    Cleaning up the entire linked list
-    Counting the number of nodes in the linked list

## How Users Can Get Started with the Project
- Clone the repository:
`git clone https://github.com/N4tis/Linked-List.git`

- Navigate to the project directory:
`cd Linked-List`

- Compile the library:
`make`

- Install the library:
`sudo make install`

## Usage

Include the library header in your C program and link against the compiled shared library:
```c
#include <llist.h>

int main() {
    node_t *head = NULL;
    int data = 5;
    node_t *new_node = create_node(&data);
    insertBeginning(&head, new_node);

    // Perform other operations

    cleanup(&head);
    return 0;
}
```
