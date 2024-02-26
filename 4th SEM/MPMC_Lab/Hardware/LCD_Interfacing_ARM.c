/*
To interface LCD with ARM Processor, Write and execute programs in C language for
displaying text messages and numbers on LCD
*/


#include<stdio.h>
#include<LPC214x.h>

void delay() {
    unsigned int i, j;
    for (i = 0; i < 0xFF; i++) {
        for (j = 0; j < 0xFF; j++);
    }
}

int main() {
    unsigned int number = 0x00;
    
    // Configure the GPIO pins for 7-segment display
    IO0DIR = 0X0000007C;  // Configure P0.2 to P0.6 as outputs for 7-segment display
    IO0SET = 0X0000007C;  // Set initial state for display

    while (1) {
        // Turn off the common cathode for the 7-segment display
        IO0CLR = 0X0000003C;

        // Set the appropriate segments for the current number
        IO0SET = IO0SET | (number << 2);

        // Introduce a delay for visual display
        delay();
        delay();

        // Wait for the switch (connected to P0.7) to be pressed
        while (IO0PIN & 0X000080000);

        // Wait for the switch to be released
        while (!(IO0PIN & 0X000080000));

        // Increment the number and reset to 0 if it exceeds 9
        number++;
        if (number > 9)
            number = 0x00;
    }

    return 0;
}
