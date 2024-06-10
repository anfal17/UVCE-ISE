#include<stdio.h>
#include<string.h>

// Define character arrays for various purposes
char data[100], concatdata[117], src_crc[17], dest_crc[17], frame[120], divident[18], divisor[18] = "10001000000001000", res[17] = "0000000000000000";

// Function to calculate CRC
void crc_cal(int node) {
    int i, j;
    // Loop through each character in concatdata starting from the 17th character
    for(j = 17; j <= strlen(concatdata); j++) {
        // If the first character of divident is '1', toggle divident based on the divisor
        if(divident[0] == '1') {
            for(i = 1; i <= 16; i++)
                // If divident[i] differs from divisor[i], set divident[i-1] to '1'
                if(divident[i]!= divisor[i]) divident[i - 1] = '1';
                // Otherwise, set divident[i-1] to '0'
                else divident[i - 1] = '0';
        } 
        // If the first character of divident is '0', shift divident left
        else {
            for(i = 1; i <= 16; i++) divident[i - 1] = divident[i];
        }
        // Depending on the node, append the next character from concatdata or frame to divident
        if(node == 0) divident[i - 1] = concatdata[j];
        else divident[i - 1] = frame[j];
    }
    // Null-terminate divident after processing all characters
    divident[i - 1] = '\0';
    // Print the updated divident, which represents the CRC
    printf("\ncrc is %s\n", divident);
    // Copy the updated divident to either src_crc or dest_crc based on the node
    if(node == 0) strcpy(src_crc, divident);
    else strcpy(dest_crc, divident);
}

int main() {
    int i, len, rest;
    // Prompt the user to enter the data to be sent
    printf("\n\t\t\tAT SOURCE NODE\n\nEnter the data to be sent: ");
    // Use gets() for simplicity, though it's unsafe due to potential buffer overflow
    gets(data);
    // Concatenate the entered data with a fixed pattern
    strcpy(concatdata, data);
    strcat(concatdata, "0000000000000000");
    
    // Initialize divident with the first 17 characters of concatdata
    for(i = 0; i <= 16; i++) divident[i] = concatdata[i];
    // Null-terminate divident
    divident[i + 1] = '\0';
    
    // Calculate CRC for source data
    crc_cal(0);
    
    // Print the data and the calculated CRC
    printf("\nData is: \t");
    puts(data);
    printf("\nThe frame transmitted is: \t");
    printf("\n%s%s", data, src_crc);
    
    // Prompt the user to enter the received frame
    printf("\n\t\tSOURCE NODE TRANSMITTED THE FRAME ---->\n");
    printf("\n\n\n\n\t\t\tAT DESTINATION NODE\nEnter the received frame: ");
    // Again, use gets() which is unsafe
    gets(frame);
    
    // Update divident with the received frame
    for(i = 0; i <= 16; i++) divident[i] = frame[i];
    // Null-terminate divident
    divident[i + 1] = '\0';
    
    // Calculate CRC for the received frame
    crc_cal(1);
    
    // Compare the calculated CRC with the expected remainder
    if(strcmp(dest_crc, res) == 0) // If they match, the frame is error-free
        printf("\nReceived frame is error-free.");
    else // If they do not match, the frame has errors
        printf("\nReceived frame has one or more errors.");
    
    return 1;
}
