#include "queue.h"
#include <ctype.h>

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = MAX - 1;
    for (int i = 0; i < MAX; i++) {
        q->data[i] = 'A' + i;
    }
}

void rotateQueue(Queue *q, int shift) {
    Queue temp;
    initQueue(&temp);

    shift = (shift % MAX + MAX) % MAX;

    for (int i = 0; i < MAX; i++) {
        q->data[i] = temp.data[(i + shift) % MAX];
    }
}

char encryptChar(Queue *q, char ch) {
    if (!isalpha(ch)) return ch;
    char upper = toupper(ch);
    return q->data[upper - 'A'];
}

char decryptChar(Queue *q, char ch) {
    if (!isalpha(ch)) return ch;
    char upper = toupper(ch);
    for (int i = 0; i < MAX; i++) {
        if (q->data[i] == upper) {
            return 'A' + i;
        }
    }
    return ch;
}
