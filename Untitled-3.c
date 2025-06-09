#include <stdio.h>

#define SIZE 100

 int queue[SIZE];
int front = -1;
int rear = -1;

 int isEmpty() {
    return front == -1 || front > rear;
}

 int isFull() {
    return rear == SIZE - 1;
}

 void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

 int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = queue[front];
    front++;
    return value;
}

 void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

 int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    return 0;
}
