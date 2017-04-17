#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


long long a = 834633493, //Множитель
c = 34657, //Приращение
m = 4294967296, //Модуль
T[16], //Массив промежутков для Хи-квадрата
Y[1048576], // Массив промежутков для конфликтов
N = 1000000,//Кол-во наблюдений для Хи-квадрата
W = 16384, //Кол-во наблюдений для конфликтов
prom = 16, //Кол-во промежутков для Хи-квадрата
kvo = 1048576; // Кол-во промежутков для конфликтов
//ЛКГ 
long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
}

void obnult() {
	for (int i = 0; i < prom; i++) { T[i] = 0; }
}

void obnuly() {
	for (int i = 0; i < prom; i++) { Y[i] = 0; }
}

long long per() {
	long long x0 = 1065748872, x = x0, t = 0;
	do { x = lkg(x); t++; } while (x != x0);
	return t;
}

int power() {
	long long c = a - 1;
	int s = 1;
	int k = 1;
	while (1) {
		k *= c;
		if (k % m == 0) { return s; }
		s++;
	}
}

double hihi() {
	long long s = 0;
for (int i = 0; i < prom; i++) {
	s += T[i] * T[i] * prom;
}
return (double(s) / double(N)) -double(N);
}

/*int konf() {

}*/

int main() {
	setlocale(LC_ALL, "Russian");
	long long x = 0, L[10] = { 3435787, 1343567099, 2346624335, 3345926656, 4545647999, 5232777845, 6343888746, 7343518369, 8357451120, 9548990768 }, y = 0;
	printf("power = %d\n", power());
	//printf("period = %lld\n", per());
	//printf("%d", a % 8);
	printf("------------------------------------------------------------------\n");
	for (int j = 0; j < 10; j++) {
		obnult();
		x = L[j];
		for (long long i = 0; i < N; i++) {
			y = x / (m / prom);
			x = lkg(x);
			T[y]++;
		}

		printf("Хи-квадрат = %.2f\n", hihi());
		
	}
	printf("------------------------------------------------------------------\n");
	obnuly();
	x = L[1];
	for (int i = 0; i < W; i++) {
		y = x / (m / kvo);
		x = lkg(x);
		if
	}
	return 0;
}