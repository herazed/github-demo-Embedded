#include "stdint.h"
#include "stdbool.h"

#define bufer_max_size 20

typedef struct {

    uint8_t buffer[bufer_max_size];
    uint32_t head;
    uint32_t tail;


} Ring_Buffer_t;


void Init(Ring_Buffer_t *bf){

    bf->head = 0;
    bf->tail = 0;

}


bool IsEmpty(Ring_Buffer_t *bf){

    if(bf->head == bf->tail){
        return true;
    }

    else{
        return false;
    }

}


bool IsFull(Ring_Buffer_t *bf){
    
    uint32_t next_head = (bf->head + 1) % bufer_max_size;

    if(next_head == bf->tail){
        return true;
    }

    else{
        return false;
    }

}


int Push(Ring_Buffer_t *bf, uint8_t data){

    if(IsFull(bf)){
        return 0;
    }

    else{

        Init(bf);
        uint32_t next_head = ((bf->head + 1) % bufer_max_size);
        bf->buffer[bf->head] = data;
        bf->head = next_head; 

        return 1;
    }

}

int Pop(Ring_Buffer_t *bf, uint8_t *data){

    if(IsEmpty(bf)){
        return 0;
    }

    else{

        Init(bf);
        uint32_t next_tail = ((bf->tail + 1) % bufer_max_size);
        *data = bf->buffer[bf->tail];
        bf->tail = next_tail; 

        return 1;
    }

}
