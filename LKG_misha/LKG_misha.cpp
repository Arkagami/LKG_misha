#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


long long a = 79385237, //���������
c = 421, //�����
m = 4294967296, //������
cv=32, //���������� ����������
n=m/cv, //����� ������ ���������
diapazon[32], buf=0, 
kol = 100000; //������� ����� �������

//����������� ��������� ������� ����������
void launch() {
	for (int yy = 0;yy < cv;yy++) diapazon[yy] = 0;
}

//���
long long lkg(long long x) {
	long long  f = (a*x + c) % m;
	return f;
}

//���������� ��������
long long power() {
	long long b = 1, s=0;
	while (b%m) {
		b = b*(a - 1);
		s++;
	}
	return s;
}


int main() {
	launch;
	long long x = rand(), count, y;
	printf("Power - %lld\n-------------------------------------------------\n", power());
		long long k = lkg(x);
		count = 1;
		y = -1;
		x = k;
			for(long long q=0;q<kol;q++) {
				y = lkg(x);
				buf = y/n;
				diapazon[buf]++;
				x = y;
				count++;
			}
			count--;
			//printf("Period - %lld\n", count);
			printf("Hi-square:\n");
		for (int yy = 0;yy < cv;yy++) printf("%2d - %lld\n",yy+1,diapazon[yy]);
		printf("-------------------------------------------------\n");
		getchar();
		return 0;
}