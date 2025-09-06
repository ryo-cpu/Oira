#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 6386)	// 配列の境界チェック無視

typedef unsigned long long ull;
#include <vector>
#include <map>

using namespace std;

void makePrimeNumberList(int maxNo, vector<int>* prime)
{
	if (maxNo < 2)return;
	char* pa = new char[maxNo];
	for (int i = 0; i < maxNo; i++)	// 配列要素番号としての変数
	{
		pa[i] = (char)((i % 2) ? 0 : 1);		// そもそも偶数はすべてフラグを落とす
	}
	pa[0] = (char)0;	// 1は素数ではない
	pa[1] = (char)1;	// 2は素数である
	for (int i = 3; i <= maxNo; i++) // 自然数としての変数
	{
		if (!pa[i - 1])continue;
		for (ull j = (unsigned long long)i * i; j <= maxNo; j += 2 * (ull)i)
		{
			pa[j - 1] = 0;
		}
	}
	for (int i = 0; i < maxNo; i++)
	{
		if (pa[i])prime->push_back(i + 1);
	}
	return;
}

// 素因数分解して、各素因数の個数を求める
template <typename T>
map<T, T> prime_factor(T n) {
	map<T, T> ret;
	for (T i = 2; i * i <= n; i++) {
		T tmp = 0;
		while (n % i == 0) {
			tmp++;
			n /= i;
		}
		ret[i] = tmp;
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

// 約数の個数を計算する
template <typename T>
T divisor_num(T N) {
	map<T, T> pf = prime_factor(N);
	T ret = 1;
	for (auto p : pf) {
		ret *= (p.second + 1);
	}
	return ret;
}

void q12()
{
	int trNo = 0;
	int divCount = 0;
	int n = 1;
	while (-1)
	{
		trNo = n * (++n + 1) / 2;
		divCount = divisor_num(trNo);
		if (divCount >= 500)break;
	}
	printf("Q12:%d\n", trNo);
}


void q11()
{
	const int matrix[20][20] = {
{ 8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 8,},
{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,},
{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,},
{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,},
{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,},
{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,},
{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,},
{67,26,20,68,02,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21,},
{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72,},
{21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95,},
{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92,},
{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57,},
{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58,},
{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40,},
{04,52, 8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66,},
{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69,},
{04,42,16,73,38,25,39,11,24,94,72,18, 8,46,29,32,40,62,76,36,},
{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16,},
{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54,},
{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48,},
	};
	unsigned long long max = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20 + 1 - 4; j++)
		{
			unsigned long long hVal, vVal, lDia, rDia;
			hVal = (ull)matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];
			vVal = (ull)matrix[j][i] * matrix[j + 1][i] * matrix[j + 2][i] * matrix[j + 3][i];
			if (hVal > max)max = hVal;
			if (vVal > max)max = vVal;
			if (i >= 20 + 1 - 4)continue;
			lDia = (ull)matrix[j][i] * matrix[j + 1][i + 1] * matrix[j + 2][i + 2] * matrix[j + 3][i + 3];
			rDia = (ull)matrix[j][i + 3] * matrix[j + 1][i + 2] * matrix[j + 2][i + 1] * matrix[j + 3][i];
			if (lDia > max)max = lDia;
			if (rDia > max)max = rDia;
		}
	}
	printf("Q11:%lld\n", max);
}


void q10()
{
	const int MaxNo = 2000000;
	vector<int> prime;
	makePrimeNumberList(MaxNo, &prime);
	unsigned long long val = 0;
	for (auto it = prime.begin(); it < prime.end(); it++)
	{
		val += *it;
	}
	printf("Q10:%lld\n", val);
}

int main()
{
	q10();
	q11();
	q12();

}
