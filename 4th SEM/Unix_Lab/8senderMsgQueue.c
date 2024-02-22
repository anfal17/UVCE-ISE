#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate a key based on a file path and an identifier
    key = ftok("progfile", 65);

    // Create or get a message queue with the specified key
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Set the message type to 1
    message.mesg_type = 1;

    // Read data from the user and store it in the message buffer
    printf("Write Data: ");
    fgets(message.mesg_text, MAX, stdin);

    // Send the message to the message queue
    msgsnd(msgid, &message, sizeof(message), 0);

    // Display the sent data
    printf("Data sent is: %s \n", message.mesg_text);

    return 0;
}
