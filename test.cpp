#include <iostream>
#include <cassert>
#include "queue.h"

void testCreateQueue() {
    Queue* queue = new Queue(4);
    createQueue(queue, 4);
}

void testWriteQueue() {
    Queue* queue = new Queue(4);
    createQueue(queue, 4);
    write(queue, 1);
}

void testReadQueue() {
    Queue* queue = new Queue(4);
    createQueue(queue, 4);
    write(queue, 1);
    std::cout << read(queue) << std::endl;
}

void testGetNumberOfElements() {
    Queue* queue = new Queue(4);
    createQueue(queue, 4);
    write(queue, 1);
    write(queue, 2);
    write(queue, 3);
    write(queue, 4);
    write(queue, 5);
    std::cout << getNumberOfElements(queue) << std::endl;
}

int calculateSize(Queue* queue) {    
    Node *current = queue->head;
    int size = 1;
    while (current->next != queue->head) {
        current = current->next;
        size++;        
    }
    return size;
}

void testResizeQueue() {
    Queue* queue = new Queue(4);
    createQueue(queue, 4);
    std::cout << calculateSize(queue) << " ";
    resize(queue, 1000);
    std::cout << calculateSize(queue) << " ";
    resize(queue, 54);
    std::cout << calculateSize(queue) << " ";
    resize(queue, 55);
    std::cout << calculateSize(queue) << " ";
    resize(queue, 21);
    std::cout << calculateSize(queue) << " ";
}

void testDestroy() {
    Queue* queue = new Queue(4);
    createQueue(queue, 100);
    assert(queue != nullptr);
    destroy(queue);
    assert(queue == nullptr);
}

int main() {
    // testCreateQueue();
    // testWriteQueue();
    // testReadQueue();
    // testGetNumberOfElements();
    //testResizeQueue();
    testDestroy();

    // std::cout << "Queue size: " << queue->size << std::endl;
    // std::cout << "Number of elements: " << getNumberOfElements(queue) << std::endl;
    // std::cout << "Read queue: " << read(queue) << std::endl;
    return 0;
}