#include <iostream>
#include <cstddef>
#include <climits>
#include <assert.h>
#include "queue.h"

const int MIN_QUEUE_SIZE = 4;

queue_t* create(const size_t size)
{
    assert(size >= MIN_QUEUE_SIZE);
    queue_t *queue = new queue_t();
    queue->size = size;

    node_t *firstNode = new node_t;
    firstNode->isEmpty = true;
    queue->head = firstNode;
    queue->tail = firstNode;

    for (size_t i = 0; i < size - 1; i++)
    {
        node_t* newNode = new node_t;
        newNode->isEmpty = true;
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->tail->next = queue->head;

    return queue;
}

void write(queue_t* queue, int data) {
    queue->tail = queue->tail->next;
    queue->tail->data = data;
    queue->tail->isEmpty = false;
    if (queue->element_counter < queue->size) {
        queue->element_counter++;        
    }
    else {
        queue->head = queue->head->next;
    }        
}


int read(queue_t* queue) {
    if (queue->head->isEmpty) {
        throw std::runtime_error("Queue is empty");
    }
    int readData = queue->head->data;
    queue->head->isEmpty = true;
    queue->head = queue->head->next;
    queue->element_counter--;
    return readData;
}

void emptyQueue(queue_t* queue) {
    if (queue->element_counter == 0) {
        return;
    }
    node_t *current = queue->head;
    while (current->next != queue->head) {
        current = current->next;
    }
    queue->tail = current;
}


int getNumberOfElements(queue_t* queue) {
    return queue->element_counter;
}

void resize(queue_t* queue, size_t newSize) {
    assert(queue != nullptr && newSize >= MIN_QUEUE_SIZE && newSize != queue->size);
    if (newSize > queue->size)
    {
        for (size_t i = 0; i < newSize - queue->size; i++) {
            node_t* newNode = new node_t;
            newNode->next = queue->tail->next;
            queue->tail->next = newNode;
        }
    }
    if (newSize < queue->size) {
        for (size_t i = 0; i < queue->size - newSize; i++) {
            node_t* deletedNode = queue->tail->next;
            queue->tail->next = deletedNode->next;
            delete deletedNode;
            deletedNode = nullptr;
        }
    }
    queue->size = newSize;
}

void destroy(queue_t*& queue) {
    if (!queue)
        return;
    node_t *current = queue->head;
    node_t *temp;
    do {
        temp = current->next;
        delete current;
        current = temp;
    } while (current != queue->head);
    delete queue;
    queue = nullptr;
}