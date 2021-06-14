#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 100
int buffer[SIZE];
HANDLE mutex1, mutex2;
HANDLE sem1, sem2;

typedef struct
{
	HANDLE h; // handle 
	DWORD tid; // tid 

}threadinfo;

int random_generator()
{
	int num;
    srand(time(0));
	num=1+rand() % (1000-1)+ 1;
	return num;
}

DWORD WINAPI thread_func_producer(void* p)
{
	int i;
	threadinfo* p1 = (threadinfo*)p;
	printf("\nproducer thread %d started", p1->h);
	
	while (1) {
		Sleep((rand() % 5000) + 10000);
		WaitForSingleObject(sem2, INFINITE);
		WaitForSingleObject(mutex1, INFINITE);
		int random_number = random_generator();
		
		for (i = 0; buffer[i] != 0; i++);
		buffer[i] = random_number;
		printf("\nproducer thread %d buffer[%d] = %d", p1->h, i,random_number);
		ReleaseMutex(mutex1);
		ReleaseSemaphore(sem1, 1, NULL);
	}

	printf("\nthread %d terminated", p1->h);
	return 0;
}

DWORD WINAPI thread_func_consumer(void* p)
{
	int i;
	threadinfo* p1 = (threadinfo*)p;
	printf("\nconsumer thread %d started", p1->h);
	
	while (1) {
		Sleep((rand() % 5000) + 10000);
		WaitForSingleObject(sem1, INFINITE);
		WaitForSingleObject(mutex2, INFINITE);
		
		for (i = 0; buffer[i] == 0; i++);
		printf("\nconsumer thread %d buffer[%d]=%d", p1->h, i, buffer[i]);
		buffer[i] = 0;
		ReleaseMutex(mutex2);
		ReleaseSemaphore(sem2, 1, NULL);
	}
	printf("\nthread %d terminated", p1->h);
	return 0;
}

int main()
{
	int i, n, m;
	threadinfo* thread_producer;
	threadinfo* thread_consumer;
	
	for (i = 0; i < SIZE; i++) {
		buffer[i] = 0;
	}

	printf("Enter producer number: ");
	scanf_s("%d", &n);

	printf("Enter consumer number: ");
	scanf_s("%d", &m);

	thread_producer = (threadinfo*)malloc(n * sizeof(threadinfo));
	thread_consumer = (threadinfo*)malloc(m * sizeof(threadinfo));

	mutex1 = CreateMutex(NULL, FALSE, NULL);
	mutex2 = CreateMutex(NULL, FALSE, NULL);

	sem1 = CreateSemaphore(NULL, 0, 100, NULL);
	sem2 = CreateSemaphore(NULL, 100, 100, NULL);

	for (i = 0; i < n; i++)
	{
		thread_producer[i].h = CreateThread(NULL, 0, thread_func_producer, thread_producer + i, CREATE_SUSPENDED, &thread_producer[i].tid);
	}

	for (i = 0; i < m; i++) {
		thread_consumer[i].h = CreateThread(NULL, 0, thread_func_consumer, thread_consumer + i, CREATE_SUSPENDED, &thread_consumer[i].tid);
	}

	for (i = 0; i < n; i++)
	{
		ResumeThread(thread_producer[i].h);
	}

	for (i = 0; i < m; i++) {
		ResumeThread(thread_consumer[i].h);
	}


	printf("\nMain terminated!\n");

	ExitThread(0);
}

