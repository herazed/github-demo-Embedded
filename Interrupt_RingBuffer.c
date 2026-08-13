#include "stdint.h"
#include "stdbool.h"

#define bufer_max_size 20

volatile uint8_t arrived_data_flag = 0;

typedef struct {

    uint8_t buffer[bufer_max_size];
    volatile uint32_t head;
    volatile uint32_t tail;


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

        uint32_t next_tail = ((bf->tail + 1) % bufer_max_size);
        *data = bf->buffer[bf->tail];
        bf->tail = next_tail; 

        return 1;
    }

}

void USART1_IRQHandler(){

    arrived_data_flag = 1;
    static Ring_Buffer_t rx_buff;
    uint8_t received_data = USART1->DR;
    Push(&rx_buff, received_data);

}


int main(){

    uint8_t mdata[bufer_max_size];

    while(1){
        
        if(arrived_data_flag == 1){
            arrived_data_flag = 0;
            Pop(&rx_buff, mdata);
        }

        if(parse(mdata) == UDS_Service[id]){
            USART_Send_Msg(UDS_Service[id]);
        }

    }

    return 0;
}

volatile uint32_t arrived_data_flag = 0;

void USART1_IRQHandler(){

    arrived_data_flag = 1;

}

int main(){

    if(data_received()){
        arrived_data_flag++;
    }

    return 0;
}
