#include "stdint.h"

size_t MyStrlen(const char *str);

size_t MyStrlen(const char *str){

    uint32_t counter = 0;
    while(*str > 0){
        counter++;
        str++;
    }
    return counter;

}
