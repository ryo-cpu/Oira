#pragma warning(disable:6387)
#pragma warning(disable:6011)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

// 真の約数の和
int getProperDivisor(int value)
{
	static int PropSum[28122] = { 0 };			// 簡易的なキャッシュ
	if (PropSum[value])return PropSum[value];	// 前に計算済みのものはそこから返却する

	int sum = 0;
	for (int i = 1; i <= value / 2; i++)
	{
		if (!(value % i))sum += i;
	}
	PropSum[value] = sum;
	return sum;
}

// 過剰数かどうか判定する
bool isAbundant(int num)
{
	return getProperDivisor(num) > num;
}


void q23()
{
	int sum = 0, t;
	for (int i = 1; i < 28123; i++)
	{
		t = 0;
		for (int j = 12; j * 2 <= i; j++)
			if (isAbundant(j) && isAbundant(i - j))
			{
				t = 1;
				break;
			}
		if (t == 0)
			sum += i;

	}
	printf("Q23:%d\n", sum);
}

int __cdecl pcCompare(const void* a, const void* b)
{
	int ret = strcmp(*(const char**)a, *(const char**)b);
	return ret;
}

void q22()
{
	FILE* file = fopen("p022_names.txt", "rb");
	char* txt = (char*)malloc(50000);
	size_t readSize = fread(txt, 1, 50000, file);
	fclose(file);
	char** lemma = (char**)malloc(sizeof(char*) * 5170);
	int count = 0;
	int pos = 0;
	for (int i = 0; i < (int)readSize; i++)
		if (txt[i] == '\"')
			if (++count % 2)
				lemma[pos++] = txt + i + 1;
			else
				txt[i] = 0;
	qsort(lemma, pos, sizeof(char*), pcCompare);
	int sumscore = 0;
	for (int i = 0; i < pos; i++) {
		int strScore = 0;
		for (char* p = lemma[i]; *p; p++) strScore += *p - '@';
		sumscore += strScore * (i + 1);
	}
	printf("Q22:%d\n", sumscore);
	free(lemma);
	free(txt);
}



void q21()
{
	int allsum = 0;
	for (int i = 3; i < 10000; i++)
	{
		int baseDiv = getProperDivisor(i);
		int inhDiv = getProperDivisor(baseDiv);
		if (i == inhDiv && i != baseDiv)
		{
			allsum += i;
		}
	}
	printf("Q21:%d\n", allsum);
}

int main() {
	q21();
	q22();
	q23();
	return 0;
}