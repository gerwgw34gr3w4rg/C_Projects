#ifndef FIXED_SIZE_QUEUE_H
#define FIXED_SIZE_QUEUE_H


#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


#include "fixed_size_stack.h"
#include "error.h"

typedef struct {
    FixedSizeStack *out;
    FixedSizeStack *in;
} FixedSizeQueue;


FixedSizeQueue *FixedSizeQueue_new(size_t limit, error_t *error);
void FixedSizeQueue_delete(FixedSizeQueue **queue_pointer, error_t *error);

void FixedSizeQueue_enqueue(FixedSizeQueue *queue, int data, error_t *error); // положить элемент на верхушку стека
int FixedSizeQueue_dequeue(FixedSizeQueue *queue, error_t *error); // взять последний положенный элемент со стека
int FixedSizeQueue_peek(const FixedSizeQueue *queue, error_t *error); // посмотерть верхний элемент стека
size_t FixedSizeQueue_get_size(const FixedSizeQueue *queue, error_t *error); // колличество элементов в стеке
bool FixedSizeQueue_is_empty(const FixedSizeQueue *queue, error_t *error); // проверка пустой стек или нет

void FixedSizeQueue_print(const FixedSizeQueue *queue, error_t *error);

#endif
