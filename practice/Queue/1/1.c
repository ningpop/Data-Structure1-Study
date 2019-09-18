/*
	�ۼ���: 2019.05.21
	�ۼ���: 20154015 �̳���
	���α׷���: ���� ť ���α׷�
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // ť �ִ� ũ�⸦ 10���� ����
typedef struct {
	char queue_name[MAX_QUEUE_SIZE];
	int queue_number;
} element; // �̸��� ���ڸ� ���� ����ü ����
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType; // ť �迭�� ť�� ó���� ���� �����ϴ� ť ����ü ����

void error(char *message); // ť�� ���� �޽��� ��� �Լ�
void init(QueueType *q); // ť�� ó���� ���� �˷��ִ� ������ �ʱ�ȭ �Լ�
int is_empty(QueueType *q); // ť�� ������� �˷��ִ� �Լ�
int is_full(QueueType *q); // ť�� �� á���� �˷��ִ� �Լ�
void enqueue(QueueType *q, element item); // ť�� �����͸� �����ϴ� �Լ�
element dequeue(QueueType *q); // ť���� ���� ������ �����͸� �����ϴ� �Լ�

int main(void)
{
	FILE *fp = NULL; // ���������� ����� ���ÿ� NULL�� �ʱ�ȭ
	element temp; // �̸��� ���ڸ� ���� �ӽ� ����ü ����
	QueueType q; // ť �ϳ� ����
	init(&q); // ť �ʱ�ȭ
	
	fp = fopen("data.txt", "r"); // fopen���� data.txt������ �б���� ����.

	if(fp == NULL) // ���������Ͱ� NULL���̸�
	{
		printf("���� ���� ����\n"); // ���� �޽��� ���
		exit(1);
	}
	
	while(!feof(fp)) // ���������Ͱ� ������ ���� ���� ������
	{
		fscanf(fp, "%s %d", temp.queue_name, &temp.queue_number); // �̸��� ���ڸ� �о� �ӽ� ����ü�� ����
		printf("ť�� ������ %s %d ���Ե�\n", temp.queue_name, temp.queue_number); // ������ ����Ȯ�� ���� ���
		enqueue(&q, temp); // �̸��� ���ڸ� �о� ����� �ӽ� ����ü�� ť�� ����
	}

	fclose(fp); // ���ϴݱ�

	while(q.front != q.rear) // ť�� front���� rear���� ���������� �ݺ�
	{
		temp = dequeue(&q); // ť���� ���� ������ �����͸� �����Ͽ� �ӽ� ����ü�� ����
		printf("dequeue = %s %d\n", temp.queue_name, temp.queue_number); // �����Ͽ� �ӽ� ����ü�� ����� ������ ���
	}	

	return 0;
}

void error(char *message) // ť�� ���� �޽��� ��� �Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) // ť�� ó���� ���� �˷��ִ� ������ �ʱ�ȭ �Լ�
{
	q->front = q->rear = 0; // ť�� front�� rear�� 0���� �ʱ�ȭ
}

int is_empty(QueueType *q) // ť�� ������� �˷��ִ� �Լ�
{
	return (q->front == q->rear); // ť�� front�� rear�� ������ T/F�� ��ȯ
}

int is_full(QueueType *q) // ť�� �� á���� �˷��ִ� �Լ�
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front); // ť�� rear+1���� front�� ������ ���� T/F ��ȯ
}

void enqueue(QueueType *q, element item) // ť�� �����͸� �����ϴ� �Լ�
{
	if(is_full(q)) // ť�� �� á�ٸ�
		error("ť�� ��ȭ�����Դϴ�."); // �����޽��� ���
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE; // rear���� ���� index�� ����Ŵ
	q->queue[q->rear] = item; // ť�� ���� index�� ���ο� �����͸� ����
}

element dequeue(QueueType *q) // ť���� ���� ������ �����͸� �����ϴ� �Լ�
{
	if(is_empty(q)) // ť�� ����ٸ�
		error("ť�� ��������Դϴ�."); // �����޽��� ���
	q->front = (q->front+1) % MAX_QUEUE_SIZE; // front���� ���� front���� ����Ŵ
	return q->queue[q->front]; // front�� ����Ű�� ť�� ���� ��ȯ
}