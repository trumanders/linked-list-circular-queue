#include <iostream>
#include <cstddef>
#include <climits>
#include "queue.h"

struct node_t {
    int data;
    struct node_t *next;
};

struct queue_t {
    node_t *head;
    node_t *tail;
    size_t size;
    size_t min_size;
    size_t element_counter;
};

const int queueMinSize = 4;

bool createQueue(Queue *queue, size_t size)
{
    bool isCreated = false;
    if (size >= queue->minSize) {   
        Node *firstNode = new Node();
        firstNode->data = INT_MIN;
        queue->head = firstNode;
        queue->tail = firstNode;

        for (int i = 0; i < size - 1; i++)
        {
            Node *newNode = new Node();
            newNode->data = INT_MIN;
            queue->tail->next = newNode;
            queue->tail = newNode;
        }
        queue->tail->next = queue->head;
        queue->size = size;
        isCreated = true;
    }
    return isCreated;
}

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


int read(Queue* queue) {
    if (!queue->head) {
        throw std::runtime_error("Queue is empty");
    }
    int readData = queue->head->data;
    queue->head->isEmpty = true;
    queue->head = queue->head->next;
    queue->elementCounter--;
    return readData;
}

void emptyQueue(Queue* queue) {
    if (queue->elementCounter == 0) {
        return;
    }
    Node *current = queue->head;
    while (current->next != queue->head) {
        current = current->next;
    }
    queue->tail = current;
}


int getNumberOfElements(Queue* queue) {
    return queue->elementCounter;
}

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

void destroy(Queue*& queue) {
    if (!queue)
        return;
    Node *current = queue->head;
    Node *temp;
    do {
        temp = current->next;  // points to what last iteration?
        delete current;
        current = temp;
    } while (current != queue->head);
    delete queue;
    queue = nullptr;
}