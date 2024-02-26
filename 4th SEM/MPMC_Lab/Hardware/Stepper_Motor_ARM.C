/*\To interface Stepper Motor with ARM Processor, Write a program to rotate stepper
motor.
*/

#include<LPC214x.h>

unsigned int count = 0;  // Global variable to keep track of the step count
unsigned int j = 0;      // Global variable used in loops
unsigned int clock[4] = {0x00030000, 0x00090000, 0x000C0000, 0x00060000};  // Sequence for clockwise direction
unsigned int anti_clock[4] = {0x00060000, 0x000C0000, 0x00030000, 0x00090000};  // Sequence for anticlockwise direction

void delay_1s(unsigned int n) {
    unsigned int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 1000; j++);
    }
}

void clock_wise_direction(unsigned int STEP, unsigned int TIME) {
    for (j = 0; j <= STEP; j++) {
        IO0PIN = clock[count];  // Output the current step pattern
        count++;
        delay_1s(TIME);  // Delay to control the speed of rotation
        if (count == 4)
            count = 0;  // Reset count if it reaches the end of the sequence
    }
}

void anti_clock_wise_direction(unsigned int STEP, unsigned int TIME) {
    for (j = 0; j <= STEP; j++) {
        IO0PIN = anti_clock[count];  // Output the current step pattern
        count++;
        delay_1s(TIME);  // Delay to control the speed of rotation
        if (count == 4)
            count = 0;  // Reset count if it reaches the end of the sequence
    }
}

int main() {
    IO0PIN = 0x000F0000;  // Initial state of the stepper motor
    while (1) {
        clock_wise_direction(10, 500);       // Rotate clockwise for 10 steps, delay 500 ms
        anti_clock_wise_direction(10, 500);  // Rotate anticlockwise for 10 steps, delay 500 ms
    }
    return 0;
}
