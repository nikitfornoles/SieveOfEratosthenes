#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

int n = 0;
bool A [1000];
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

void* sieve (void* x);

int main (int argc, char* argv[]) {
	printf("Enter a number: ");
	scanf ("%d", &n);

	int i, limit;
	for (i = 2; i <= n; i++) {
		A [i] = true;
	}

	limit = sqrt(n);
	pthread_t tid[limit];

	for (i = 2; i <= limit; i++) {
		pthread_create (&tid[i], NULL, sieve, (void*) i);
	}

	for (i = 2; i <= limit; i++) {
		pthread_join (tid[i], NULL);
	}

	//prime numbers
	for (i = 2; i <= n; i++) {
		if (A[i])
			printf ("%d\n", i);
	}
	return 0;
}

void* sieve (void* x) {
	pthread_mutex_lock (&count_mutex);
	int index = (int) x;
	if (A[index]) {
		int k = 0;
		int j;
		for (j = (index*index); j <= n; j = (index*index) + (k*index)) {
			if (A[j]) {
				A[j] = false;
				printf ("I'm thread %d setting %d to false.\n", index, j);
			}
			k = k + 1;
		}
	}
	pthread_mutex_unlock (&count_mutex);
}
