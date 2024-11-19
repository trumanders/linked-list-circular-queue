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

struct node_t;
struct queue_t;

/**
 * @brief Creates a new instance of the circular queue and creates the nodes
 * 
 * @param size The number of nodes that will be created in the queue
 * @return queue_t* The pointer to the created queue
 */
queue_t* create(size_t size);

/**
 * @brief Write data to the queue.
 * 
 * @param queue The queue to write to.
 * @param data The data to write.
 * 
 * If the queue is not full, increment the element counter and write the data to the next
 * node. If the queue is full, move the head to the next node to overwrite the oldest data.
 */
void write(queue_t* queue, int data);

/**
 * @brief Read data from the front of the queue
 * 
 * @param queue The Queue object to be read from
 * @return The data at the front of the queue
 * @throw std::runtime_error if the element is empty
 */
int read(queue_t* queue);


/**
 * @brief Make the queue empty.
 * 
 * This function will move the tail to the node before the head, effectively
 * making the queue empty. The counter will be set to 0.
 */
void emptyQueue(queue_t* queue);


/**
 * @brief Return the number of elements in the queue.
 * 
 * @param queue The queue for which to return the number of elements.
 * @return The number of elements in the queue.
 */
int getNumberOfElements(queue_t* queue);

/**
 * @brief Resizes the queue to a new size. If the new size is larger than the old size,
 * new nodes are allocated and linked in. If the new size is smaller than the old size,
 * nodes are deleted and the memory is deallocated. The function does nothing if the
 * new size is equal to the old size, or if the new size is less than the minimum allowed size.
 * 
 * @param queue The queue to be resized.
 * @param newSize The new size of the queue.
 */
void resize(queue_t* queue, size_t new_size);


/**
 * @brief Destroys the queue, deallocating all dynamically allocated memory.
 * 
 * Iterates over all nodes in the circular queue, deleting each node. 
 * Finally, deletes the queue itself and sets the queue pointer to nullptr.
 * 
 * @param queue Reference to the pointer of the Queue to be destroyed. It is passed by reference
 * to allow access to the pointer itself.
 */
void destroy(queue_t*& queue);

#endif