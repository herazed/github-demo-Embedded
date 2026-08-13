#include "stdint.h"

void MyMemcpy(char *des, char *src, size_t number){

    for(uint32_t i = 0; i < number; i++){
        des[i] = src[i];
    }
    
}

void *MyMemcpy(void *des, char *src, size_t number){



}

