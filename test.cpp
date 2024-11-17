#include <iostream>
#include <cassert>
#include "queue.h"

const int MIN_QUEUE_SIZE = 4;

int calculateSize(Queue* queue) {   
    if (queue == nullptr || queue->head == nullptr)
        return 0; 

    Node *current = queue->head;
    int size = 1;
    while (current->next != queue->head) {
        current = current->next;
        size++;        
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
    assert(read(queue) == 1);
    assert(read(queue) == 0);
    assert(read(queue) == 0);
    assert(read(queue) == 0);
    assert(read(queue) == 1);

    std::cout << read(queue) << std::endl;
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
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
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
    Queue* queue = new Queue(MIN_QUEUE_SIZE);
    createQueue(queue, 100);
    assert(queue != nullptr);
    destroy(queue);
    assert(queue == nullptr);
}



int main() {
    //testGetNumberOfElements();
    testCreateQueue();
    // testWriteQueue();
    // testReadQueue();
    // testResizeQueue();
    // testDestroy();
    return 0;
}