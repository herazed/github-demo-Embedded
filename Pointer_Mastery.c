#include "stdio.h"

int main(){

    int sensor_speed_A = 80;
    int sensor_speed_B = 85;
    const int LIMIT_SPEED = 120;

    int *const ptr_to_const = &sensor_speed_A;
    *ptr_to_const = 100; /*Vì đây là hằng con trỏ cho nên giá trị vẫn sẽ thay đổi được => Compiler success*/
    ptr_to_const = &sensor_speed_B; /*Vì đây là một hằng con trỏ nên địa chỉ của nó sẽ không thể thay đổi sau khi gán => Compile Eror*/

    const int *const_ptr = &sensor_speed_A;
    const_ptr = &sensor_speed_B; /*Vì đây là con trỏ hằng nên giá trị mà nó trỏ tới là hằng số và không thể thay đổi được => Compile Eror*/
    *const_ptr = 150; /*Vì đây là con trỏ hằng nên nó vẫn có thể trỏ tới địa chỉ của một ô nhớ khác => Compiler success*/

    return 0;
}
