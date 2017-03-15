#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


long long a = 4097, c = 421, m = 4294967296, cv=32, n=m/cv, diapazon[32], buf=0; //22695477

void launch() {
	for (int yy = 0;yy < cv;yy++) diapazon[yy] = 0;
}

long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
}


int main() {
	launch;
	long long x, count, y;
	printf("Start lkg.\n...\n");
		x = rand();
		long long k = lkg(x);
		count = 1;
		y = -1;
		x = k;
		while (y != k) {
			//if (count == 10000) break;
			y = lkg(x);
			buf = y/n;
			diapazon[buf]++;
			x = y;
			count++;
			//if (count % 1000000000 == 0) printf("%10lld\n", count);
		}
		//count--;
		printf("End lkg.\n");
		printf("Period - %lld\n", count);
		for (int yy = 0;yy < cv;yy++) printf("%d - %10lld\n",yy,diapazon[yy]);
	getchar();
	return 0;
}