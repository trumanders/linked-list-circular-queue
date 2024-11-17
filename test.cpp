#include <iostream>
#include <cassert>
#include "queue.h"

const int MIN_QUEUE_SIZE = 4;

int calculateSize(Queue* queue) {
    int size = 0;
    if (queue != nullptr && queue->head != nullptr) {    
        Node *current = queue->head;
        size++;
        while (current->next != queue->head) {
            current = current->next;
            size++;        
        }        
    }
    else {
        size = 0;
    }
    return size;
}

void testCreateQueue() {
    std::cout << "Test create Queue of size 4: ";
    size_t size = 4;

    try {
        Queue* queue = new Queue(MIN_QUEUE_SIZE);
        bool isCreated = createQueue(queue, size);
        
        assert(queue != nullptr);
        assert(calculateSize(queue) == size);
        assert(queue->size == size);
        assert(queue->elementCounter == 0);
        assert(isCreated);
        std::cout << "ok!" << std::endl;
    } catch (...) {
        assert(false && "Exception thrown");
    }    
}

void testWriteQueue() {
    size_t queueSize = 4;
    std::cout << "Test write to queue: ";
    
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    bool isCreated = createQueue(queue, queueSize);
    
    assert(isCreated);
    write(queue, 1);
    assert(queue->tail->data == 1);
    assert(queue->elementCounter == 1);

    write(queue, 2);
    assert(queue->tail->data == 2);
    assert(queue->elementCounter == 2);

    write(queue, 3);
    assert(queue->tail->data == 3);
    assert(queue->elementCounter == 3);

    write(queue, 4);
    assert(queue->tail->data == 4);
    assert(queue->elementCounter == 4);

    write(queue, 5);
    assert(queue->tail->data == 5);
    assert(queue->head->data == 2);
    assert(queue->elementCounter == 4);

    std::cout << "ok!" << std::endl;

    destroy(queue);
}

void testGetNumberOfElements() {
    size_t queueSize = 4;   

    std::cout << "Test getNumberOfElements: ";
    Queue* queue = new Queue(MIN_QUEUE_SIZE);

    createQueue(queue, queueSize);
    assert(getNumberOfElements(queue) == 0);

    write(queue, 1);
    write(queue, 2);
    write(queue, 3);
    assert(getNumberOfElements(queue) == 3);

    write(queue, 4);
    assert(getNumberOfElements(queue) == 4);

    write(queue, 5);
    assert(getNumberOfElements(queue) == 4);

    std::cout << "ok!" << std::endl;
}

void testReadQueue() {
    std::cout << "Test read from queue: ";

    size_t queueSize = 4;
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    createQueue(queue, 4);

    write(queue, 1);
    write(queue, 2);
    write(queue, 3);

    assert(read(queue) == 1);
    assert(read(queue) == 2);
    assert(read(queue) == 3);

    std::cout << "ok!" << std::endl;
}

void testResizeQueue() {
    std::cout << "Test resize queue: ";
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    createQueue(queue, 4);
    assert(calculateSize(queue) == 4);

    resize(queue, 1000);
    assert(calculateSize(queue) == 1000);

    resize(queue, 54);
    assert(calculateSize(queue) == 54);

    resize(queue, 55);
    assert(calculateSize(queue) == 55);

    resize(queue, 21);
    assert(calculateSize(queue) == 21);

    std::cout << "ok!" << std::endl;
}

void testDestroy() {
    std::cout << "Test destroy queue: ";
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    createQueue(queue, 100);
    assert(queue != nullptr);
    destroy(queue);
    assert(queue == nullptr);

    std::cout << "ok!" << std::endl;
}

void testOverWriteAndRead() {
    std::cout << "Test overwrite and read: ";
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    createQueue(queue, 4);
    write(queue, 1);
    write(queue, 2);
    write(queue, 3);
    write(queue, 4);
    write(queue, 5);
    assert(read(queue) == 2);
    assert(read(queue) == 3);
    assert(read(queue) == 4);
    assert(read(queue) == 5);
    assert(read(queue) == 0);
    assert(read(queue) == 0);
    std::cout << "ok!" << std::endl;
}

int main() {
    testCreateQueue();
    testWriteQueue();
    testGetNumberOfElements();    
    testReadQueue();
    testResizeQueue();
    testDestroy();
    testOverWriteAndRead();   

    return 0;
}