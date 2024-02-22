#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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

    // Receive a message from the message queue with message type 1
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Display the received data
    printf("Data Received is: %s \n", message.mesg_text);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}