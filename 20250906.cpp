#define _CRT_SECURE_NO_WARNINGS

#pragma warning (disable : 6386)
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

bool isPrimeNumber(vector<int>* prime, int val)
{
	return binary_search(prime->begin(), prime->end(), val) ? true : false;
}

void makePrimeNumberList(int maxNo, vector<int>* prime)
{
	char* pa = new char[maxNo];
	for (int i = 0; i < maxNo; i++)	// �z��v�f�ԍ��Ƃ��Ă̕ϐ�
	{
		pa[i] = (i % 2) ? 0 : 1;		// �������������͂��ׂăt���O�𗎂Ƃ�
	}
	pa[0] = 0;	// 1�͑f���ł͂Ȃ�
	pa[1] = 1;	// 2�͑f���ł���
	for (int i = 3; i <= maxNo; i++) // ���R���Ƃ��Ă̕ϐ�
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

bool isPermutation(int a, int b)
{
	char countA[10] = { 0 }, countB[10] = { 0 };
	for (; a && b;)
	{
		countA[a % 10]++;
		countB[b % 10]++;
		a /= 10;
		b /= 10;
	}
	if (*(long long*)countA != *(long long*)countB || *(short*)&countA[8] != *(short*)&countB[8])
		return false;
	return true;
}

int CountPrimeKind(vector<int>* prime, int val)
{
	int count = 0;
	for (auto p = prime->begin(); p < prime->end(); p++)
	{
		if (*p * 2 > val)break;
		if ((val % *p) == 0)count++;
	}
	return count;
}



void q49()
{
	vector<int> prime;
	makePrimeNumberList(10000, &prime);
	for (int i = 1001; i < 9998; i++)
	{	// ����
		for (int j = 1; j <= (9999 - i) / 2; j++)
		{
			int a = i, b = a + j, c = b + j;
			if (!isPrimeNumber(&prime, a) || !isPrimeNumber(&prime, b) || !isPrimeNumber(&prime, c))
				continue;
			if (!isPermutation(a, b) || !isPermutation(a, c))
				continue;
			printf("Q49:%d%d%d\n", a, b, c);
		}
	}
}

void q48()
{
	// ��(k = 1, 1000, k^k)�̉�10�������߂�
	long lsc[10] = { 0 };	// lsc[0]��1�̈�
	long calc[10] = { 0 };
	for (int i = 1; i <= 1000; i++)
	{
		// ���[�N������
		for (int j = 0; j < 10; j++)calc[j] = 0;
		calc[0] = 1;
		// �ݏ�v�Z
		for (int j = 0; j < i; j++)
		{	// k��̏�Z
			for (int k = 0; k < 10; k++)
			{
				calc[k] *= i;
			}
			// �J��オ�菈��(��Z�Ƃ͕����ď������Ȃ���΂Ȃ�Ȃ�)
			for (int k = 0; k < 10; k++)
			{
				if (k < 9)calc[k + 1] += calc[k] / 10;	// �ŏ�ʌ�����̌J��オ��͔p��
				calc[k] %= 10;
			}
		}
		// �ݏ�v�Z�̌��ʂ����ɉ��Z
		for (int j = 0; j < 10; j++)
		{
			lsc[j] += calc[j];
			if (j < 9)lsc[j + 1] += lsc[j] / 10;
			lsc[j] %= 10;
		}
	}
	printf("Q48:");
	// ���ʕ\��
	for (int i = 0; i < 10; i++)
	{
		printf("%d", lsc[9 - i]);
	}
	puts("");
}

void q47()
{
	vector<int> prime;
	makePrimeNumberList(200000, &prime);
	int iMin;
	for (int i = 1; i < 200000; i += 4)
	{
		bool flg = false;
		int cnt = CountPrimeKind(&prime, i);
		if (cnt != 4)continue;
		int count = 1;
		iMin = i;
		// �O���m�F
		for (int j = i - 1; j > i - 4; j--, count++)
		{
			if (CountPrimeKind(&prime, j) != 4)
				break;
			iMin = i;
		}
		// ����m�F
		for (int j = i + 1; j < i + 4; j++, count++)
		{
			if (CountPrimeKind(&prime, j) != 4)
				break;
		}
		if (count == 4)
		{
			printf("Q47:%d\n", iMin);
			return;
		}
	}

}

int main() {
	q47();
	q48();
	q49();
	return 0;
}