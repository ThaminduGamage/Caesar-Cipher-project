#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

#define MAX_LEN 1024

void toUpperStr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char mode;
    char message[MAX_LEN];
    int shift;
    Queue q;

    while (1) {
        printf("\nEncryption (E) or Decryption (D)?: ");
        scanf(" %c", &mode);
        getchar(); // Consume newline

        if (toupper(mode) == 'E') {
            printf("Enter your message: ");
            fgets(message, MAX_LEN, stdin);
            message[strcspn(message, "\n")] = '\0'; // remove newline

            printf("Enter shift key : ");
            scanf("%d", &shift);
            getchar();

            initQueue(&q);
            rotateQueue(&q, shift);

            printf("*****************************\n");
            printf("Encrypted Message: ");
            for (int i = 0; message[i]; i++) {
                printf("%c", encryptChar(&q, message[i]));
            }
            printf("\n");

        } else if (toupper(mode) == 'D') {
            printf("Encrypted Message: ");
            fgets(message, MAX_LEN, stdin);
            message[strcspn(message, "\n")] = '\0';

            printf("Enter shift key : ");
            scanf("%d", &shift);
            getchar();

            initQueue(&q);
            rotateQueue(&q, shift);

            printf("*****************************\n");
            printf("Original Message: ");
            for (int i = 0; message[i]; i++) {
                printf("%c", decryptChar(&q, message[i]));
            }
            printf("\n");

        } else {
            printf("Invalid option. Please enter E or D.\n");
        }
    }

    return 0;
}
