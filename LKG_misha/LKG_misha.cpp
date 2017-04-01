#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

const long long N = 1000000,//Кол-во наблюдений
prom = 51; //Кол-во промежутков
long long a = 834633493, //Множитель
c = 34657, //Приращение
m = 4294967296, //Модуль
R[N], //Массив наблюдений
T[prom]; //Массив промежутков
//ЛКГ 
long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
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

long long hihi() {

}

int main() {
	long long x = 0, x0=1627367263;

	x = lkg(x0);
	printf("rand() = %lld\n", x);
	printf("power = %d\n", power());
	//printf("%d", a % 8);
	

		getchar();
		return 0;
}