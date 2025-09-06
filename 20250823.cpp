#define _CRT_SECURE_NO_WARNINGS

#pragma warning (disable : 6386)
#include <stdio.h>

// 十進数の桁をカウントする
template<class T> int countCol(T val)
{
	if (!val)return 0;
	T tmp = val;
	int colCount = 1;
	while (tmp /= (T)10)colCount++;
	return colCount;
}

bool is_pandigital(unsigned int a)
{
	int len = countCol<int>(a);
	int count[10] = { 0 };
	for (; a; a /= 10)
	{
		int tmp = a % 10;
		if (!tmp)return false;
		count[tmp]++;
	}
	for (int i = 1; i <= len; i++)
	{
		if (!count[i] || count[i] > 1)return false;
	}
	return true;
}

bool isPythagorean(int a, int b, int c)
{
	return (a * a + b * b) == (c * c);
}

int getMul(int val)
{
	int multi = 1;
	for (int i = 0; i < val; i++)multi *= 10;
	return multi;
}


void q40()
{
	int answer = 1;			// 解答を格納する
	int col = 1;			// 次は何桁目を取るか
	int count = 0;			// 解答を取る回数(7で終わり)
	int accumlation = 0;	// ここまでの累積桁数
	for (int i = 1; i < 1000000 && count < 7; i++)
	{
		int len = countCol<int>(i);
		if (accumlation < col && col <= accumlation + len)
		{
			// この数値内に当該桁が含まれるので、当該桁を取り出す
			// 12345 67[8]9
			int tVal = i;
			// 10で割る回数=1 = len - (col - accumlation)
			for (int c = 0; c < len - (col - accumlation); c++)
			{
				tVal /= 10;
			}
			tVal %= 10;
			answer *= tVal;
			count++;

			// 後始末
			col *= 10;
		}
		accumlation += len;
	}
	printf("Q40:%d\n", answer);
}

void q39()
{
	int maxP = 0;
	int countMax = 0;
	int count[1000] = { 0 };
	for (int a = 1; a < 998; a++)
	{
		for (int b = a; b < 999; b++)
		{
			for (int c = b; c < 1000; c++)
			{
				int tmpP = a + b + c;
				if (tmpP > 1000)break;
				if (isPythagorean(a, b, c))
				{
					++count[tmpP - 1];
					break;
				}
			}
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		if (countMax < count[i])
		{
			maxP = i + 1;
			countMax = count[i];
		}
	}
	printf("Q39:%d\n", maxP);
}


void q38()
{
	long long max = 0;
	for (int i = 1; i < 10000; i++)
	{
		for (int j = 2; ; j++)
		{
			long long pan = 0;
			for (int k = 1; k <= j; k++)
			{
				int tmp = i * k;
				pan *= getMul(countCol<int>(tmp));
				pan += tmp;
			}
			int len = countCol<long long>(pan);
			if (len < 9)continue;
			else if (len > 9)break;
			else
			{
				if (!is_pandigital((unsigned int)pan))continue;
				if (pan > max)
				{
					max = pan;
				}
			}
		}
	}
	printf("Q38:%lld\n", max);
}

int main()
{
	q38();
	q39();
	q40();
	return 0;
}