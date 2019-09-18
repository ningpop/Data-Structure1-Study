/*
	작성일: 2019.05.21
	작성자: 20154015 이남준
	프로그램명: 원형 큐 프로그램
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10 // 큐 최대 크기를 10으로 지정
typedef struct {
	char queue_name[MAX_QUEUE_SIZE];
	int queue_number;
} element; // 이름과 숫자를 담을 구조체 선언
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType; // 큐 배열과 큐의 처음과 끝을 저장하는 큐 구조체 선언

void error(char *message); // 큐의 에러 메시지 출력 함수
void init(QueueType *q); // 큐의 처음과 끝을 알려주는 변수들 초기화 함수
int is_empty(QueueType *q); // 큐가 비었는지 알려주는 함수
int is_full(QueueType *q); // 큐가 꽉 찼는지 알려주는 함수
void enqueue(QueueType *q, element item); // 큐에 데이터를 삽입하는 함수
element dequeue(QueueType *q); // 큐에서 가장 오래된 데이터를 삭제하는 함수

int main(void)
{
	FILE *fp = NULL; // 파일포인터 선언과 동시에 NULL로 초기화
	element temp; // 이름과 숫자를 담을 임시 구조체 생성
	QueueType q; // 큐 하나 생성
	init(&q); // 큐 초기화
	
	fp = fopen("data.txt", "r"); // fopen으로 data.txt파일을 읽기모드로 연다.

	if(fp == NULL) // 파일포인터가 NULL값이면
	{
		printf("파일 열기 실패\n"); // 에러 메시지 출력
		exit(1);
	}
	
	while(!feof(fp)) // 파일포인터가 파일의 끝에 닿을 때까지
	{
		fscanf(fp, "%s %d", temp.queue_name, &temp.queue_number); // 이름과 숫자를 읽어 임시 구조체에 저장
		printf("큐에 데이터 %s %d 삽입됨\n", temp.queue_name, temp.queue_number); // 데이터 삽입확인 문구 출력
		enqueue(&q, temp); // 이름과 숫자를 읽어 저장된 임시 구조체를 큐에 삽입
	}

	fclose(fp); // 파일닫기

	while(q.front != q.rear) // 큐의 front값과 rear값이 같을때까지 반복
	{
		temp = dequeue(&q); // 큐에서 가장 오래된 데이터를 삭제하여 임시 구조체에 저장
		printf("dequeue = %s %d\n", temp.queue_name, temp.queue_number); // 삭제하여 임시 구조체에 저장된 데이터 출력
	}	

	return 0;
}

void error(char *message) // 큐의 에러 메시지 출력 함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q) // 큐의 처음과 끝을 알려주는 변수들 초기화 함수
{
	q->front = q->rear = 0; // 큐의 front와 rear를 0으로 초기화
}

int is_empty(QueueType *q) // 큐가 비었는지 알려주는 함수
{
	return (q->front == q->rear); // 큐의 front와 rear가 같은지 T/F를 반환
}

int is_full(QueueType *q) // 큐가 꽉 찼는지 알려주는 함수
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front); // 큐의 rear+1값이 front와 같은지 비교후 T/F 반환
}

void enqueue(QueueType *q, element item) // 큐에 데이터를 삽입하는 함수
{
	if(is_full(q)) // 큐가 꽉 찼다면
		error("큐가 포화상태입니다."); // 에러메시지 출력
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE; // rear값이 다음 index를 가리킴
	q->queue[q->rear] = item; // 큐의 다음 index에 새로운 데이터를 삽입
}

element dequeue(QueueType *q) // 큐에서 가장 오래된 데이터를 삭제하는 함수
{
	if(is_empty(q)) // 큐가 비었다면
		error("큐가 공백상태입니다."); // 에러메시지 출력
	q->front = (q->front+1) % MAX_QUEUE_SIZE; // front값이 다음 front값을 가리킴
	return q->queue[q->front]; // front가 가리키는 큐의 값을 반환
}