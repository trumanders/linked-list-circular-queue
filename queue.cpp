#include "queue.h"
#include <assert.h>
#include <climits>
#include <cstddef>
#include <iostream>

const int MIN_QUEUE_SIZE = 4;

struct node_t {
  int data;
  struct node_t *next;
  bool isEmpty;
};

struct queue_t {
  node_t *head;
  node_t *tail;
  size_t size;
  size_t element_counter;

  queue_t() : head(nullptr), tail(nullptr), element_counter(0) {
  }
};

queue_t *get_(){return }

queue_t *create(const size_t size) {
  assert(size >= MIN_QUEUE_SIZE);
  queue_t *queue = nullptr;
  try {
    queue = new queue_t();
    queue->size = size;
    queue->head = new node_t;
    queue->tail = queue->head;
    for (size_t i = 0; i < size - 1; i++) {
      node_t *newNode = nullptr;
      newNode = new node_t;
      queue->tail->next = newNode;
      queue->tail = newNode;
    }
    queue->tail->next = queue->head;
  } catch (std::bad_alloc &e) {
    destroy(queue);
  }
  return queue;
}

void write(queue_t *queue, int data) {
  if (queue) {
    queue->tail = queue->tail->next;
    queue->tail->data = data;
    queue->tail->isEmpty = false;
    if (queue->element_counter < queue->size) {
      queue->element_counter++;
    } else {
      queue->head = queue->head->next;
    }
  }
}

bool read(queue_t *queue, int &data) {
  bool status = false;
  if (queue && queue->element_counter != 0) {
    data = queue->head->data;
    queue->head->isEmpty = true;
    queue->head = queue->head->next;
    queue->element_counter--;
    status = true;
  }
  return status;
}

void emptyQueue(queue_t *queue) {
  if (queue) {
    node_t *current = queue->head;
    while (current->next != queue->head) {
      current = current->next;
    }
    queue->tail = current;
  }
}

int getNumberOfElements(queue_t *queue) {
  return queue->element_counter;
}

void resize(queue_t *queue, size_t newSize) {
  assert(queue != nullptr && newSize >= MIN_QUEUE_SIZE &&
         newSize != queue->size);
  if (newSize > queue->size) {
    for (size_t i = 0; i < newSize - queue->size; i++) {
      node_t *newNode = new node_t;
      newNode->next = queue->tail->next;
      queue->tail->next = newNode;
    }
  }
  if (newSize < queue->size) {
    for (size_t i = 0; i < queue->size - newSize; i++) {
      node_t *deletedNode = queue->tail->next;
      queue->tail->next = deletedNode->next;
      delete deletedNode;
      deletedNode = nullptr;
    }
  }
  queue->size = newSize;
}

void destroy(queue_t *&queue) {
  if (!queue || !queue->head)
    return;
  node_t *current = queue->head;
  node_t *temp = nullptr;
  do {
    temp = current->next;
    delete current;
    current = temp;
  } while (current != queue->head);
  delete queue;
  queue = nullptr;
}

void hej() {
  int a = 1;
}