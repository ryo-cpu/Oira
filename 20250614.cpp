#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

using namespace std;

void q19()
{	// 1901`2000”N‚Å1“ú‚ª“ú—j“ú‚Å‚ ‚éŒ‚Ì”
	int count = 0;
	for (int year = 1901; year <= 2000; year++) {
		for (int month = 1; month <= 12; month++) {
			date d(year, month, 1);
			if (d.day_of_week() == 0)count++;
		}
	}
	printf("Q19:%d\n", count);
}


void q67()
{
	FILE* file = fopen("q67.txt", "rt");
	char buff[300];
	int current[100] = { 0 };
	int last[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		fgets(buff, 300, file);
		char* p = strtok(buff, " ");
		last[0] = atoi(p) + current[0];
		for (int j = 1; j <= i; j++)
			last[j] = atoi(strtok(NULL, " ")) + max(current[j - 1], current[j]);
		for (int k = 0; k < 100; k++)current[k] = last[k];
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		if (ans < current[i])ans = current[i];
	printf("Q67:%d\n", ans);
}


void q18()
{
	const int pyramid[] = {
		75,
		95,64,
		17,47,82,
		18,35,87,10,
		20,04,82,47,65,
		19,01,23,75,03,34,
		88,02,77,73,07,63,67,
		99,65,04,28,06,16,70,92,
		41,41,26,56,83,40,80,70,33,
		41,48,72,33,47,32,37,16,94,29,
		53,71,44,65,25,43,91,52,97,51,14,
		70,11,33,28,77,73,17,78,39,68,17,57,
		91,71,52,38,17,14,91,43,58,50,27,29,48,
		63,66,04,68,89,53,67,30,73,16,69,87,40,31,
		04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23,
	};
	int sum = 0, summax = 0;
	int base = 0;
	int loc = 0;
	for (int trial = 0; trial < 16384; trial++)
	{
		loc = 0;
		base = 0;
		sum = 0;
		for (int i = 1; i <= 15; i++)
		{
			sum += pyramid[base + loc];
			base += i;
			if (trial & (1 << (i - 1)))loc++;
		}
		if (sum > summax)summax = sum;
	}
	printf("Q18:%d\n", summax);

}

int main() {
	q18();
	q67();
	q19();
}