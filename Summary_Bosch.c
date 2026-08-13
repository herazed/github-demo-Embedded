/* 1. Thao tác Bit chuyên sâu (Bit Manipulation) */

#include "stdio.h"
#include "stdbool.h"

bool bit_manipulation(uint16_t reg_val){

    /*Set bit*/
    reg_val |= (1UL << 3) | (1UL << 7);

    /*Clear bit*/
    reg_val &= ~(1 << 5);

    /*Toggle bit*/
    reg_val ^= (1 << 12);

    /*Check bit*/
    if((reg_val >> 2) & 0x01){
        return true;
    }
    else{
        return false;
    }

} 

/* 2. Đóng gói và Giải mã gói tin (Data Packing / Parsing) */

#include "stdio.h"

int16_t Parse_Steering_Angle(uint8_t *data){

    int16_t SW_Angle |= ((int16_t)(data[0] >> 4) | (data[1] << 4));

    if(SW_Angle & (0x01 << 11)){
        return SW_Angle |= (0xF000);
    }

    return SW_Angle;

}

/* 3. Thuật toán Lọc số cơ bản (Digital Filtering) */

#include "stdio.h"

#define WINDOW_Size 4

float Moving_Average_Filter(float new_sample){

    static float ring_buffer = {0.0f};
    static float sum = 0.0f;
    static float avg_value = 0.0f;

    static uint32_t index = 0;

    ring_buffer[index] = new_sample;
    index = ((index + 1) % WINDOW_Size);
    
    for(uint8_t i = 0; i < WINDOW_Size; i++){
        sum += ring_buffer[i];
    }

    avg_value = (sum / (float)WINDOW_Size);

    return avg_value;
}

/* 4. Quản lý Bộ đệm Dữ liệu (Ring Buffer / FIFO) */

#include "stdio.h"
#include "stdbool.h"

#define MAX_Buffer 20

typedef struct {

    uint8_t data[MAX_Buffer];
    volatile uint32_t head; 
    volatile uint32_t tail;

}Ring_Buffer_t;


void init(Ring_Buffer_t *bf){

    bf->head = 0;
    bf->tail = 0;

}

bool is_empty(Ring_Buffer_t *bf){

    if(bf->head == bf->tail){
        return true;
    }

    else{
        return false;
    }

}

bool is_full(Ring_Buffer_t *bf){

    uint32_t next_head = (bf->head + 1) % MAX_Buffer;

    if(next_head == bf->tail){
        return true;
    }

    else{
        return false;
    }

}

int push_Queue(Ring_Buffer_t *bf, uint8_t mdata){

    if(!is_full(bf)){
        bf->data[bf->head] = mdata;
        bf->head = (bf->head + 1) % MAX_Buffer;
        return 1;
    }

    else{
        printf("Buffer is full !");
        return 0;
    }

}


int pop_Queue(Ring_Buffer_t *bf, uint8_t *mBuffer){

    if(!is_empty(bf)){
        *mBuffer = bf->data[bf->tail];
        bf->tail = (bf->tail + 1) % MAX_Buffer;
        return 1;
    }

    else{
        printf("Buffer is empty !");
        return 0;
    }

}

/* 5. Tối ưu hóa chuỗi logic Trạng thái (State Machine Implementation) */

#include "stdio.h"

typedef enum{

    OFF, 
    INT /*(Gạt gián đoạn)*/, 
    LOW /*(Gạt chậm)*/, 
    HIGH /*(Gạt nhanh)*/

} Wiper_Sys_State_t;

Wiper_Sys_State_t wiper_state = OFF;

void Wiper_State_Machine_Update(void){

    switch(wiper_state){

        case OFF:
            wiper_sys_init();
            wiper_state = INT;
            break;

        case INT:
            change_low_state();
            wiper_state = LOW;
            break;

        case LOW:
            speed_up_wiper();
            wiper_state = HIGH;
            break;

        case HIGH:
            turn_off_wiper();
            wiper_state = OFF;
            break;

        default:
            wiper_state = OFF;
            break;

    }
    
}


/* Sua 1 chut cho vui ne hihihi */
