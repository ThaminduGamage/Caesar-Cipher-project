#ifndef QUEUE_H
#define QUEUE_H

#define MAX 26

typedef struct {
    char data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
void rotateQueue(Queue *q, int shift);
char encryptChar(Queue *q, char ch);
char decryptChar(Queue *q, char ch);

#endif
