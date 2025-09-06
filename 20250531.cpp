#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CalcFactorialSum(int count)
{
	int answer[160] = { 0 };
	answer[0] = 1;
	for (int i = 1; i <= count; i++)
	{
		for (int j = 0; j < 160; j++) answer[j] *= i;
		for (int j = 0; j < 160; j++)
		{
			if (answer[j] > 9)
			{
				answer[j + 1] += answer[j] / 10;
				answer[j] %= 10;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 160; i++)
	{
		sum += answer[i];
	}
	return sum;
}

void q20()
{
	printf("Q20(10):%d\n", CalcFactorialSum(10));
	printf("Q20(100):%d\n", CalcFactorialSum(100));
}

int CalcBinPower(int count)
{
	int answer[400] = { 0 };
	answer[0] = 1;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			answer[j] *= 2;
		}
		for (int j = 0; j < 400; j++)
		{
			if (answer[j] > 9)
			{
				answer[j + 1] += answer[j] / 10;
				answer[j] %= 10;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 400; i++)sum += answer[i];
	return sum;
}


void q16()
{
	printf("Q16(15):%d\n", CalcBinPower(15));
	printf("Q16(40):%d\n", CalcBinPower(1000));
}

int main() {
	q16();
	q20();
}
