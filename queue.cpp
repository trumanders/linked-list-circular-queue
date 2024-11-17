#include <iostream>
#include <cstddef>
#include "queue.h"

/**
 * @brief A multiple instance circular queue implemented using a circular singly
 * linked list to store and restore data of type int.
 * 
 */

// struct Node {
//     int data;
//     Node *next;
// };

// struct Queue {
//     Node *head;
//     Node *tail;
//     int size;
// };

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

    // final node:
    // next shall point to the node that is pointed to by HEAD (CIRCULAR)
    // TAIL is left at this last node

const int queueMinSize = 4;

void hej() { std::cout << "hejhej" << std::endl; }

bool createQueue(Queue *queue, size_t size)
{
    if (size < queueMinSize) {
        return false;
    }
    queue->elementCounter = 0;
    Node *firstNode = new Node();
    queue->head = firstNode;
    queue->tail = firstNode;

    for (int i = 0; i < size - 1; i++)
    {
        Node *newNode = new Node();
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->tail->next = queue->head;
    queue->size = size;
    return true;
}


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


/**
 * @brief Writes data to the queue at the position indicated by the tail.
 * 
 * @param queue Pointer to the Queue object where data is to be written.
 * @param data The integer data to be written into the queue.
 */
void write(Queue* queue, int data) {
    queue->tail = queue->tail->next;
    queue->tail->data = data;
    if (queue->elementCounter < queue->size) {
        queue->elementCounter++;        
    }
    else {
        queue->head = queue->head->next;
    }        
}


/* READ FUNCTION */
    // We read from HEAD - store the data in variable
    // MOVE HEAD to next node!
    // repeat
    // DECREASE COUNTER FOR EVERY READ

    // After reading last node - the queue is EMPTY, MOVE HEAD TO NEXT NODE
    // If reading when empty, return error / false // nullptr or something
int read(Queue* queue) {
    int readData = queue->head->data;
    queue->head->data = 0;
    queue->head = queue->head->next;
    queue->elementCounter--;
    return readData;
}


/* FUNCTION TO MAKE QUEUE EMPTY */
    // Move TAIL to node BEFORE HEAD
void emotyQueue(Queue* queue) {
    if (queue->elementCounter == 0) {
        return;
    }
    Node *current = queue->head;
    while (current->next != queue->head) {
        current = current->next;
    }
    queue->tail = current;
}


/* FUNCTION TO RETURN NUMBER OF ELEMENTS */
    // Return counter
int getNumberOfElements(Queue* queue) {
    return queue->elementCounter;
}


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
void resize(Queue* queue, size_t newSize) {
    if (newSize == queue->size || newSize < 0 || newSize < queue->minSize) {
        return;
    }
    if (newSize > queue->size) {
        for (int i = 0; i < newSize - queue->size; i++) {
            Node *newNode = new Node();
            newNode->next = queue->tail->next;
            queue->tail->next = newNode;
        }
    }
    if (newSize < queue->size) {
        for (int i = 0; i < queue->size - newSize; i++) {
            Node *deletedNode = queue->tail->next;
            queue->tail->next = deletedNode->next;
            free(deletedNode);
            deletedNode = nullptr;
        }
    }
    queue->size = newSize;
}

/* DESTROY FUNCTION */
    // Free memory of the deleted node. Release the allocated memory.
    // This is because we allocate memoty dynamcally during runtime!! (using new?)
void destroy(Queue*& queue) {
    if (!queue)
        return;
    Node *current = queue->head;
    Node *temp;
    do {
        temp = current->next;  // points to what last iteration?
        free(current);
        current = temp;
    } while (current != queue->head);
    free(queue);
    queue = nullptr;
}


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