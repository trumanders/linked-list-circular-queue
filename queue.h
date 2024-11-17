/**
 * @file queue.h
 * @author Anders Johansson (anderssvenaxelj@gmail.com)
 * @brief A multiple instance circular queue implemented using a circular singly
 * linked list to store and restore data of type int. It has functions for creating, writing to, reading from,
 * resizing, and destroying the queue.
 * @version 0.1
 * @date 2024-11-17
 * 
 * @copyright Copyright (c) 2024 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
    size_t size;
    const int minSize;
    size_t elementCounter;

    Queue(int minSize) : head(nullptr), tail(nullptr), size(0), minSize(minSize), elementCounter(0) {}
};

/* CREATE FUNCTION */
    // Use function to create instance
    // Size is passed to the function, size > 3
    // Create and link nodes in this create function

    // Queue has HEAD and TAIL poiters
    // start as nullptr

    // Create a node
    // head and tail points to one node

    // create new node
    // "next" of TAIL-node (previous node) now points to new node
    // move tail to point at this node

    // final nodde:
    // next shall point to the node that is pointed to by HEAD (CIRCULAR)
    // TAIL is left at this last node

/**
 * @brief Create a queue with the given size. The size must be >= 4.
 * 
 * @param queue Pointer to the Queue object to be created.
 * @param size The size of the queue.
 * @return True if the queue was created, false otherwise.
 */
bool createQueue(Queue *queue, size_t size);

/* WRITE DATA FUNCTION */
    // Since we're creating a QUEUE, we write to the TAIL

    // To write:
    // First MOVE TAIL to the next node, write there at this tail.

    // Write again:
    // MOVE TAIL to next node, write there.

    // Use COUNTER to count elements written. Increment when storing data

    // OVERWRITE
    // When queue is full, OVERWRITE. Counter cannot be larger than number of nodes
    // MOVE TAIL as usual, overwrite.
    // MOVE HEAD to next node - because head must point to the oldest data.
void write(Queue *queue, int data);

/* READ FUNCTION */
    // We read from HEAD - store the data in variable
    // MOVE HEAD to next node!
    // repeat
    // DECREASE COUNTER FOR EVERY READ

    // After reading last node - the queue is EMPTY, MOVE HEAD TO NEXT NODE
    // If reading when empty, return error / false // nullptr or something
int read(Queue *queue);

/* FUNCTION TO MAKE QUEUE EMPTY */
    // Move TAIL to node BEFORE HEAD
void emotyQueue();


/* FUNCTION TO RETURN NUMBER OF ELEMENTS */
    // Return counter
int getNumberOfElements(Queue *queue);

/* FUNCTION TO RESIZE QUEUE - NEW SIZE MUST BE > 3- CHECK THAT! */ 
    // order is important:
    // Create a new node - it's next shall point to the node after tail, which is the same as TAIL NEXT pointer.
    // TAIL NEXT pointer shall point to new node 
    // Tail is not moved

    // DECREASE SIZE (delete nodes):
    // One by one
    //
    // Delete node WITHOUT DATA
    // We delete node AFTER TAIL
    // Create pointer "deletedPointer" to node AFTER NEXT which is TAIL NEXT
    // Point TAIL NEXT to deletedPointer-next
    // The node pointed to by "deletedPointer" is now out of the list
    // Free the memory of deleted node even if it was empty.
    //
    // IF THE DELETED NODE HAS DATA:
    // MOVE HEAD to "deletedPointer"-next, so that HEAD points to the oldest data!
    // 
    // WHen decreasing size of list, since we delete after tail, the nodes that we delete
    // will either be empty OR HEAD, satisfying the requirement that always delet the oldest DATA (head)
void resize(Queue* queue, size_t new_size);

/* DESTROY FUNCTION */
    // Free memory of the deleted node. Release the allocated memory.
    // This is because we allocate memoty dynamcally during runtime!! (using new?)
void destroy(Queue*& queue);

/**
 * @brief Check if passed data is in the list
 * 
 * @param data The integer data look for in the list
 */

#endif

/* TEST THE MODULE USING ASSERTIONS */

/* SHALL BE A Makefile or CMakeLists.txt to build and run tests */
    // Source files:
        // queue.cpp
        // tests.cpp
    // Header file
        // queue.h
    
    // Generated files when building shall be in FOLDER build


/* Submit ZIP-file with FOUR FILES: queue.cpp, tests.cpp, queue.h, makefile.txt */

// Use function to destroy instance
