#include "error.h"
#include "fixed_size_queue.h"


#include <assert.h>

#define DATA_SIZE 9

int main(){
    size_t limit = 7;
    error_t error = SUCCESS;
    
    FixedSizeQueue *queue = FixedSizeQueue_new(limit, &error);
    assert(NULL != queue);
    assert(SUCCESS == error);
    assert(limit == queue -> in -> buffer_size);
    assert(limit == queue -> out -> buffer_size);

    
    int data[DATA_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    for(i = 0; i < DATA_SIZE / 2; i++){
        FixedSizeQueue_enqueue(queue, data[i], &error);
        assert(SUCCESS == error);
    }

    int num = FixedSizeQueue_peek(queue, &error);
    assert(SUCCESS == error);
    assert(4 == num);

    FixedSizeQueue_print(queue, &error);
    assert(SUCCESS == error);

    bool is_queue_empty = FixedSizeQueue_is_empty(queue, &error);
    assert(not is_queue_empty);
    assert(NULL != queue);
    assert(SUCCESS == error);

    FixedSizeQueue_dequeue(queue, &error);
    assert(SUCCESS == error);
    assert(3 == FixedSizeQueue_get_size(queue, &error));

    FixedSizeQueue_print(queue, &error);
    assert(NULL != queue);
    assert(SUCCESS == error);

    num = FixedSizeQueue_peek(queue, &error);
    assert(SUCCESS == error);
    assert(4 == num);

    is_queue_empty = FixedSizeQueue_is_empty(queue, &error);
    assert(not is_queue_empty);
    assert(NULL != queue);
    assert(SUCCESS == error);

    FixedSizeQueue_delete(&queue, &error);
    assert(SUCCESS == error);
    assert(NULL == queue);



    printf("\nTest.exe return 0!\n");

}
