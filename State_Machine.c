#include "stdint.h"

typedef enum{

    IDLE = 0,
    WAIT_COMMAND,
    PROGRAM,
    VERIFY

} State_Machine_t;

void Bootloader_Task(void)
{

    static State_Machine_t current_state = IDLE;

    switch (current_state)
    {
        case IDLE:
            /* code */
            if(){
                current_state = WAIT_COMMAND;
            }
            break;
        
        case WAIT_COMMAND:
            /* code */
            if(){
                current_state = PROGRAM;
            }
            break;
        
        case PROGRAM:
            /* code */
            if(){
                current_state = VERIFY;
            }
            break;

        case VERIFY:
            /* code */
            if(){
                current_state = IDLE;
            }
            break;

        default:
            current_state = IDLE;
            break;
        }

}
