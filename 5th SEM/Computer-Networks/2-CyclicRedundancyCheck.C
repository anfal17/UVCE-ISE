#include <stdio.h>
#include <string.h>

int main() {
    int i, j, keylen, msglen, flag = 0;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];

    // Input the data and the key
    printf("Enter Data: ");
    scanf("%s", input);
    printf("Enter Key: ");
    scanf("%s", key);

    keylen = strlen(key);
    msglen = strlen(input);
    strcpy(key1, key);

    // Append zero bits to the input data
    for (i = 0; i < keylen - 1; i++) {
        input[msglen + i] = '0';
    }
    input[msglen + keylen - 1] = '\0';

    // Initialize temp with the first part of the input data
    for (i = 0; i < keylen; i++) {
        temp[i] = input[i];
    }

    // Perform the division using XOR and update quotient and remainder
    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0];
        if (quot[i] == '0') {
            for (j = 0; j < keylen; j++) {
                key[j] = '0';
            }
        } else {
            for (j = 0; j < keylen; j++) {
                key[j] = key1[j];
            }
        }
        for (j = keylen - 1; j > 0; j--) {
            if (temp[j] == key[j]) {
                rem[j - 1] = '0';
            } else {
                rem[j - 1] = '1';
            }
        }
        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }

    strcpy(rem, temp);

    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++) {
        printf("%c", quot[i]);
    }

    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }

    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++) {
        printf("%c", input[i]);
    }
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }
    printf("\n");

    char temp1[100];
    printf("Enter received data: ");
    scanf("%s", temp1);

    for (i = 0; i < keylen; i++) {
        temp[i] = temp1[i];
    }

    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0];
        if (quot[i] == '0') {
            for (j = 0; j < keylen; j++) {
                key[j] = '0';
            }
        } else {
            for (j = 0; j < keylen; j++) {
                key[j] = key1[j];
            }
        }
        for (j = keylen - 1; j > 0; j--) {
            if (temp[j] == key[j]) {
                rem[j - 1] = '0';
            } else {
                rem[j - 1] = '1';
            }
        }
        rem[keylen - 1] = temp1[i + keylen];
        strcpy(temp, rem);
    }

    strcpy(rem, temp);

    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++) {
        printf("%c", quot[i]);
    }

    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++) {
        printf("%c", rem[i]);
    }

    flag = 0;
    for (i = 0; i < keylen - 1; i++) {
        if (rem[i] == '1') {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\nNo Error\n");
    } else {
        printf("\nError is detected\n");
    }

    return 0;
}
