#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

long long a = 4097, c = 421, m = 4294967296; //22695477
long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
}


int main() {
	long long x, count, y;
	printf("Start lkg.\n");
		x = rand();
		long long k = lkg(x);
		count = 1;
		y = -1;
		x = k;
		while (y != k) {
			y = lkg(x);
			x = y;
			count++;
			if (count % 10000000 == 0) printf("%10lld\n", count);
		}
		count--;
		printf("End lkg.\n");
		printf("Period - %lld\n", count);
	getchar();
	return 0;
}