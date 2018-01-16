#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n;
	cout << "Enter a number: ";
	cin >> n;

	bool *A = new bool [n];

	int i;
	for (i = 2; i <= n; i++) {
		A [i] = true;
	}

	int limit = sqrt (n);
	for (i = 2; i <= limit; i++) {
		if (A[i]) {
			int k = 0;
			for (int j = (i*i); j <= n; j = (i*i) + (k*i)) {
				if (A[j]) {
					A [j] = false;
					cout << "Setting " << j << " to false.\n";
				}
				k = k + 1;
			}
		}
	}

	//prime numbers from 2 to n
	for (i = 2; i <= n; i++) {
		if (A[i])
			cout << i << endl;
	}
	return 0;
}