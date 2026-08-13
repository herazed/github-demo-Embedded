#include "stdio.h"
#include "stdlib.h"

typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float integrator;      // Biến tích lũy của khâu I
    float prev_error;      // Sai số của chu kỳ trước (cho khâu D)
    float sample_time;     // Chu kỳ trích mẫu (Ts)
} PID_Controller;


float PID_Update(PID_Controller *pid, float setpoint, float feedback){

    float error = (float)(setpoint - feedback);
    float factor_P = (float)(pid->Kp * error);
    float factor_D = (float)((pid->Kd * (error - pid->prev_error)) / pid->sample_time);

    float potential_integrator = pid->integrator + (error * pid->sample_time);
    float factor_I = (float)(pid->Ki * potential_integrator);


    float raw_output = (factor_P + factor_I + factor_D);
    float final_output = raw_output;

    if(final_output > 100.0f){
        final_output = 100.0f;
    }
    else if(final_output < 0.0f){
        final_output = 0.0f;
    }

    int dynamic_saturation = (final_output != raw_output);
    int same_sign = ((error > 0 && raw_output > 0) || (error < 0 && raw_output < 0));

    if(!(dynamic_saturation && same_sign)){
        pid->integrator = potential_integrator;
    }

    pid->prev_error = error;

    return final_output;

}

