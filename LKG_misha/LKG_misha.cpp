#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


long long a = 79385237, //Множитель
c = 421, //Сдвиг
m = 4294967296, //Модуль
cv=30, //Количество диапазонов
n=m/cv, //Длина одного диапазона
diapazon[30], buf=0, 
masOfX[6], //Массив начальных значений X
kol = 100000; //Сколько чисел считать

//Изначальное обнуление массива диапазонов
void launch() {
	for (int yy = 0;yy < cv;yy++) diapazon[yy] = 0;
}

//ЛКГ
long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
}

//Вычисление мощности
long long power() {
	long long b = 1, s=0;
	while (b%m) {
		b = b*(a - 1);
		b = b % m;
		s++;
	}
	return s;
}

//Хи-квадрат
long double hi_square() {
	long long hi = 0;
	for (int d = 0;d < cv;d++) {
		hi += (diapazon[d] * diapazon[d] * cv);
	}
	return (double(hi) / double(kol) - double(kol));
}


int main() {
	masOfX[0] = 745;
	masOfX[1] = 2837377;
	masOfX[2] = 37488842;
	masOfX[3] = 419857238;
	masOfX[4] = 2094658277;
	long long x, count, y;
	printf("Power - %lld\n-------------------------------------------------\n", power());
		long long k = 0;
		count = 0;
		y = -1;
		printf("Hi-Square must be between 18.49 and 43.77\n");
		for (int g = 0;g < 5;g++) {
			launch();
			x = masOfX[g];
			for (long long q = 0;q < kol;q++) {
				y = lkg(x);
				buf = y / n;
				diapazon[buf]++;
				x = y;
				count++;
			}
			count--;
			//printf("Period - %lld\n", count);
			//printf("Hi-square:\n");
			//for (int yy = 0;yy < cv;yy++) printf("%2d - %lld\n", yy + 1, diapazon[yy]);
			printf("Hi-Square %d = %.2llf\n", g+1, hi_square());
		}
		printf("-------------------------------------------------\n");
		getchar();
		return 0;
}