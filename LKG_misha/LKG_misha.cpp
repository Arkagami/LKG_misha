#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


long long a = 79385237, //Множитель
c = 421, //Сдвиг
m = 4294967296, //Модуль
cv = 31, //Количество диапазонов
n = m / cv, //Длина одного диапазона
diapazon[32], buf = 0,
masOfX[6], //Массив начальных значений X
kol = 1000000, //Сколько чисел считать
testKol = 5; //Количество тестов


long long
d = 7, //Наиболее подходящее число
d_2[7][7], //Массив количества пар
N = 100000; //Сколько чисел считать



//Изначальное обнуление массива диапазонов
void launch() {
	for (int yy = 0;yy < cv;yy++) diapazon[yy] = 0;
}

//Изначальное обнуление массива пар
void launches() {
	for (int xy = 0;xy < d;xy++) for (int yy = 0;yy < d;yy++) d_2[xy][yy] = 0;
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
	for (int dd = 0;dd < cv;dd++) {
		hi += (diapazon[dd] * diapazon[dd] * cv);
	}
	return (double(hi) / double(kol) - double(kol));
}

//Критерий серий
long double kri_ser() {
	long long hi = 0;
	for (int dd = 0;dd < d;dd++) {
		for (int dd1 = 0;dd1 < d;dd1++) {
			hi += (d_2[dd][dd1] * d_2[dd][dd1] * d * d);
		}
	}
	return (double(hi) / double(N) - double(N));
}

int main() {
	masOfX[0] = 723;
	masOfX[1] = 37482;
	masOfX[2] = 2837375;
	masOfX[3] = 419855238;
	masOfX[4] = 20946582779;
	long long x, count, y;

	printf("Power - %lld\n-------------------------------------------------\n", power());


		count = 0;
		y = -1;
		printf("Hi-Square must be between 18.49 and 43.77\n");
		for (int g = 0;g < testKol;g++) {
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


		printf("Kriteri' seri' must be between %.2llf and %.2llf\n", (d*d + sqrtl(2.0*powl(double(d),2.0))*(-1.64) + 2.0*powl(1.64,2.0)/3.0 -2.0/3.0), (d*d + sqrtl(2.0*powl(double(d), 2.0))*(1.64) + 2.0*powl(1.64, 2.0) / 3.0 - 2.0 / 3.0));
		for (int g = 0;g < testKol;g++) {
			launches();
			x = masOfX[g];
			long long y1 = 0, y2 = 0;
			for (long long q = 0;q < N;q++) {
				y1 = lkg(x);
				y2 = lkg(y1);
				d_2[y1 % d][y2 % d]++;
				x = y2;
			}
			printf("Kriteri' seri' %d = %.2llf\n", g + 1, kri_ser());
		}
		printf("-------------------------------------------------\n");

		getchar();
		return 0;
}