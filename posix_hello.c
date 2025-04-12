/**
CS 425 Assignment 6.1
Kirin Sharma
This program creates a number of posix threads specified by a command-line argument and
prints hello world from each process, then finalizes the environment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count; /*Global thread count*/

void *Hello(void* rank); /*Thread function*/

int main(int argc, char* argv[]) {
	long thread;
	pthread_t* thread_handles;

	/* Get num of threads from command line*/
	thread_count = strtol(argv[1], NULL, 10);
	
	thread_handles = malloc(thread_count*sizeof(pthread_t));
	
	for (thread = 0; thread < thread_count; thread++) {
		pthread_create(&thread_handles[thread], NULL, Hello, (void*) thread);
	}

	printf("Hello from the main thread\n");

	for (thread = 0; thread < thread_count; thread++) {
		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);
	return 0;
} /* main */


void *Hello(void* rank) {
	long my_rank = (long) rank;
	
	printf("Hello from thread %ld of %d\n", (my_rank + 1), thread_count);

	return NULL;
} /* Hello */
