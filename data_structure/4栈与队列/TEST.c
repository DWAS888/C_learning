#include <stdio.h>

#define MAXSIZE 5
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;

typedef struct {
    QElemType data[MAXSIZE];
    int front,rear;
} SqQueue;

Status InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue Q) {
    return ( (Q.rear - Q.front + MAXSIZE) % MAXSIZE );
}

Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->rear == Q->front)
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

int main() {
    SqQueue Q;
    QElemType e;
    Status s;

    InitQueue(&Q);
    printf("=== 1. 初始空队列 ===\n");
    printf("长度: %d (期望 0)\n\n", QueueLength(Q));

    printf("=== 2. 入队 10, 20, 30 ===\n");
    EnQueue(&Q, 10);
    EnQueue(&Q, 20);
    EnQueue(&Q, 30);
    printf("长度: %d (期望 3)\n", QueueLength(Q));
    printf("内部状态: front=%d, rear=%d\n\n", Q.front, Q.rear);

    printf("=== 3. 出队 1 个 ===\n");
    DeQueue(&Q, &e);
    printf("出队元素: %d (期望 10)\n", e);
    printf("长度: %d (期望 2)\n", QueueLength(Q));
    printf("内部状态: front=%d, rear=%d\n\n", Q.front, Q.rear);

    printf("=== 4. 再入队 40, 50（关键：rear 会绕回）===\n");
    EnQueue(&Q, 40);
    EnQueue(&Q, 50);
    printf("长度: %d (期望 4)\n", QueueLength(Q));
    printf("内部状态: front=%d, rear=%d ← rear 绕回 0 了！\n\n", Q.front, Q.rear);

    printf("=== 5. 队列满了，再入队应该失败 ===\n");
    s = EnQueue(&Q, 60);
    printf("入队 60 结果: %d (0=失败 1=成功,期望 0)\n\n", s);

    printf("=== 6. 出队 4 个，把队列清空 ===\n");
    DeQueue(&Q, &e); printf("出队: %d\n", e);
    DeQueue(&Q, &e); printf("出队: %d\n", e);
    DeQueue(&Q, &e); printf("出队: %d\n", e);
    DeQueue(&Q, &e); printf("出队: %d\n", e);
    printf("长度: %d (期望 0)\n", QueueLength(Q));
    printf("内部状态: front=%d, rear=%d\n\n", Q.front, Q.rear);

    printf("=== 7. 空队列出队应该失败 ===\n");
    s = DeQueue(&Q, &e);
    printf("出队结果: %d (期望 0)\n\n", s);

    printf("=== 8. 再入队 100, 200（绕回后再用）===\n");
    EnQueue(&Q, 100);
    EnQueue(&Q, 200);
    printf("长度: %d (期望 2)\n", QueueLength(Q));
    printf("内部状态: front=%d, rear=%d\n", Q.front, Q.rear);

    return 0;
}
