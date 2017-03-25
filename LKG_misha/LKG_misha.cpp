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
kol = 100000, //Сколько чисел считать
testKol = 5; //Количество тестов

//Для Покер-Критерия:
long long k = 5, //Количество последовательных чисел
mas[6], //Массив с последовательными числами
N = 100000, //Количество групп
gr[6], //Массив количества групп с r различными числами
r = 0, //Количество различных чисел
v = 0, //Счетчик по массиву
R = 0; //Счетчик по массиву вероятностей

long double p[10]; //Массив вероятностей

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

//Хи-квадрат для Покер-Критерия
long double hi_square_pocker() {
	long double hi = 0;
	for (int d = 0;d < k;d++) {
		hi = hi + (powl(double(gr[d]), 2.0) / p[d]);
	}
	return ((hi / double(N*5)) - double(N*5)); 
}


//Подсчет различных чисел для Покер-Критерия
long long skolko() {
	long long rr = 0;
	for (long long i = 0;i < k;i++) {
		for (long long j = 0;j < i;j++) {
			if ((__max(mas[i], mas[j])-__min(mas[i], mas[j])) < (m/k)) goto end;
		}
		rr++;
	end:;
	}
	return rr;
}

//Вычисления числа Стирлинга
long long stirling(long long stir_k, long long stir_r) {
	if ((stir_k == stir_r) && (stir_k >= 0)) return 1;
	if ((stir_r == 0) && (stir_k > 0)) return 0;
	return (stirling(stir_k - 1, stir_r - 1) + stir_r*stirling(stir_k - 1, stir_r));
}


int main() {
	masOfX[0] = 745;
	masOfX[1] = 2837377;
	masOfX[2] = 37488842;
	masOfX[3] = 419857238;
	masOfX[4] = 2094658277;
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


		
		//Pocker-kriterii - dont working
		/*for (long long q = 0;q < testKol;q++) {
			k = 5;
			x = masOfX[q];
			for (long long i = 0;i < k;i++) gr[i] = 0;
			for (long long group = 0;group < N;group++) {
				for (long long i = 0;i < k;i++) { mas[i] = x; x = lkg(x); }
				R=skolko();
				gr[R-1]++;
			}

			for (long long i = 0;i < k;i++) {
				long long d = 1;
				for (int j = 0;j <= i;j++) {
					d *= (gr[i] - j);
			}
				p[i] = fabsl((double(d) / powl(double(gr[i]), double(k)))*double(stirling(k,i+1)));
			}


			/*int i = 0;
			while (i < k - 1) {
				if ((__max(p[i], p[i + 1]) - __min(p[i], p[i + 1])) < 0.001) { gr[i] = gr[i] + gr[i + 1]; p[i] = p[i] + p[i + 1]; for (int j = i + 2;j < k;j++) { gr[j - 1] = gr[j]; p[j - 1] = p[j]; } k--; } else i++;
				
			}

			printf("Pocker = %.5llf\n", hi_square_pocker());
			printf("-------------------------------------------------\n");
		}*/

		getchar();
		return 0;
}