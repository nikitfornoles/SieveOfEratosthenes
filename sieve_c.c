#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main (int argc, char* argv[]) {
	int n = 0;
	printf("Enter a number: ");
	scanf ("%d", &n);

	bool A [1000];

	int i, j;
	for (i = 2; i <= n; i++) {
		A [i] = true;
	}

	int limit = sqrt(n);
	for (i = 2; i <= limit; i++) {
		if (A[i]) {
			int k = 0;
			for (j = (i*i); j <= n; j = (i*i) + (k*i)) {
				if (A[j]) {
					A[j] = false;
					printf ("Setting %d to false.\n", j);
				}
				k = k + 1;
			}
		}
	}

	//prime numbers
	for (i = 2; i <= n; i++) {
		if (A[i])
			printf ("%d\n", i);
	}
	return 0;
}