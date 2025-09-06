#define _CRT_SECURE_NO_WARNINGS

#pragma warning (disable : 6386)
#include <stdio.h>
#include <vector>

using namespace std;

typedef unsigned long long ull;

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

// �\�i���̌����J�E���g����
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
	//if (count[0])return false;
	for (int i = 1; i <= len; i++)
	{
		if (!count[i] || count[i] > 1)return false;
	}
	return true;
}

int calcPn(int n)
{
	return n * (3 * n - 1) / 2;
}

bool IsPentagonalNumber(int n) {
	if (n <= 0)return false;
	int chk = 1 + 24 * n;
	int root = (int)sqrt((double)chk);
	if (root * root != chk)return false;
	return ((1 + root) % 6 == 0);
}

const int MAX_LIMIT = 10000;

// �G���g�X�e�l�X��⿂��g���đf���̃��X�g�𐶐�
void sieve(std::vector<bool>& IsPrime) {
	IsPrime[0] = IsPrime[1] = false;
	for (int p = 2; p * p < MAX_LIMIT; ++p) {
		if (IsPrime[p]) {
			for (int i = p * p; i < MAX_LIMIT; i += p) {
				IsPrime[i] = false;
			}
		}
	}
}

// ���������S���������ǂ����𔻒�
bool isPerfectSquare(int n) {
	if (n < 0)return false;
	int root = (int)sqrt(n);
	return root * root == n;
}

void q46()
{
	// MAX_LIMIT�܂ł̑f����ێ�����x�N�^�[
	vector<bool> IsPrime(MAX_LIMIT, true);
	sieve(IsPrime);

	// ��������2�{��ێ�����x�N�^�[
	vector<int> twiceSquareNum;
	for (int i = 1; ; ++i) {
		int tsq = 2 * i * i;
		if (tsq >= MAX_LIMIT) {
			break;
		}
		twiceSquareNum.push_back(tsq);
	}

	// 3����n�߂Ċ�����Ƀ`�F�b�N
	for (int n = 3; n < MAX_LIMIT; n += 2) {
		// n���f���Ȃ�X�L�b�v
		if (IsPrime[n]) {
			continue;
		}
		// n����̍�����
		bool found = false;
		for (int p = 2; p < n; ++p) {
			if (IsPrime[p]) {
				int remainder = n - p;
				if (remainder > 0 && remainder % 2 == 0) {
					if (isPerfectSquare(remainder / 2)) {
						found = true;
						break;
					}
				}
			}
		}
		// �����𖞂����Ȃ���̍���������������
		if (!found) {
			printf("Q46:%d\n", n);
			break;
		}
	}
}

void q44()
{
	// search
	for (int i = 1; i < 10000; i++) {
		for (int j = i + 1; j < 10000; j++) {
			int pv = calcPn(j) + calcPn(i);
			int mv = calcPn(j) - calcPn(i);
			if (!IsPentagonalNumber(pv) || !IsPentagonalNumber(mv))continue;
			printf("Q44:%d\n", mv);
			return;
		}
	}
}

void q41()
{
	vector<int> prime;
	makePrimeNumberList(999999999, &prime);
	int max = 0;
	for (auto it = prime.begin(); it < prime.end(); it++)
	{
		if (!is_pandigital(*it))continue;
		max = *it;
	}
	printf("Q41:%d\n", max);
}


int main() {
	q41();
	q44();
	q46();
}
