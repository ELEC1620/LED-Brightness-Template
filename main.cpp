/*  LED-Brightness-Template
*   This template code is configure to work with a RGB LED. Three PwmOut objects are created to control the red, green and blue colours.
*   The program cycles through two colours (red and green) in turn, ramping the brightness by incrmenting the duty cycle by 2% per loop iteration.
*   
*   The code should be modified in accordance with ADC & PWM Activity 2. 
*
*   Board: NUCLEO L476RG
*   Author: James Chandler 2021
*/
#include "mbed.h"

#define WAIT_TIME_MS 50 //Wait timw used to set the for loop frequency (i.e. increment 2% per 50 ms = 100% in 2.5 s)

PwmOut red_LED(PB_3);   //PWM output to red led
PwmOut green_LED(PB_5); //PWM output to green led
PwmOut blue_LED(PB_4);  //PWM output to blue led

float frequency = 100;  //Create frequency variable to set PWM frequencies to 100 Hz

void init();            // Declare led initialisation function

int main()
{
    init();
    
    while (true)
    {
        
        for(float PWM = 0.00; PWM <= 1.00; PWM += 0.02){   //cycle up from 0% duty cycle to 100% in increments of 2% 
                red_LED.write(PWM);                        //write PWM duty cycle to LED
                thread_sleep_for(WAIT_TIME_MS);
        }
        red_LED.write(0.0);                                //Set the red LED to 0 after the for loop completes
        thread_sleep_for(1000);                            // Sleep for 1 s to make the transition between colours more obvious

        for(float PWM = 0.00; PWM <= 1.00; PWM += 0.02){   //cycle up from 0% duty cycle to 100% in increments of 2% 
                green_LED.write(PWM);                      //write PWM duty cycle to LED
                thread_sleep_for(WAIT_TIME_MS);
        }
        green_LED.write(0.0);                               //Set the green LED to 0 after the for loop completes
        thread_sleep_for(1000);                             // Sleep for 1 s to make the transition between colours more obvious

    }
}

void init(){
    red_LED.write(0.0);                 //initialise leds with inital PWM value to 0.0 = 0%
    green_LED.write(0.0); 
    blue_LED.write(0.0);
        
    red_LED.period(1/frequency);        //set the period of the wave form as 1/100Hz
    green_LED.period(1/frequency); 
}