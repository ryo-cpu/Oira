#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int revVal(int val)
{
	int ret = 0;
	while (val)
	{
		ret *= 10;
		ret += val % 10;
		val /= 10;
	}
	return ret;
}

int revValBin(int val)
{
	int ret = 0;
	while (val)
	{
		ret *= 2;
		ret += val % 2;
		val /= 2;
	}
	return ret;
}

void makePrimeNumberList(int maxNo, vector<int>* prime)
{
	char* pa = new char[maxNo];
	for (int i = 0; i < maxNo; i++)	// ”z—ñ—v‘f”Ô†‚Æ‚µ‚Ä‚Ì•Ï”
	{
		pa[i] = (i % 2) ? 0 : 1;		// ‚»‚à‚»‚à‹ô”‚Í‚·‚×‚Äƒtƒ‰ƒO‚ð—Ž‚Æ‚·
	}
	pa[0] = 0;	// 1‚Í‘f”‚Å‚Í‚È‚¢
	pa[1] = 1;	// 2‚Í‘f”‚Å‚ ‚é
	for (int i = 3; i <= maxNo; i++) // Ž©‘R”‚Æ‚µ‚Ä‚Ì•Ï”
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


bool isPrimeNumber(vector<int>* prime, int val)
{
	return binary_search(prime->begin(), prime->end(), val) ? true : false;
}

int rotateNumber(int val)
{
	int tmp = val;
	int mod = val % 10;
	int colCount = 1;
	while (tmp /= 10)
	{
		colCount++;
		mod *= 10;
	}
	val /= 10;
	val += mod;
	return val;
}

bool isRotPrime(vector<int>* prime, int val)
{
	int tmp = val;
	int colCount = 1;
	while (tmp /= 10)colCount++;
	for (int i = 0; i < colCount; i++)
	{
		if (!isPrimeNumber(prime, val))return false;
		val = rotateNumber(val);
	}
	return true;
}


void q37()
{
	vector<int> prime;
	makePrimeNumberList(4000000, &prime);
	int sum = 0;
	for (int i = 11; i < 4000000; i++)
	{
		if (!isPrimeNumber(&prime, i))continue;
		int tmp1 = i, tmp2;
		int divend = 1;
		bool non = true;
		while (tmp1 /= 10)
		{
			divend *= 10;
			tmp2 = i % divend;
			if (!isPrimeNumber(&prime, tmp1)) {
				non = false; break;
			}
			if (!isPrimeNumber(&prime, tmp2)) {
				non = false; break;
			}
		}
		if (non)sum += i;
	}
	printf("Q37:%d\n", sum);

}

void q36()
{
	int sum = 0;
	for (int i = 1; i < 1000000; i += 2)
	{
		if (i != revVal(i))continue;
		if (i != revValBin(i))continue;
		sum += i;
	}
	printf("Q36:%d\n", sum);
}

void q35()
{
	vector<int> prime;
	makePrimeNumberList(1000000, &prime);
	int count = 0;
	for (int i = 2; i < 1000000; i++)
	{
		if (isRotPrime(&prime, i))count++;
	}
	printf("Q35:%d\n", count);
}

int main() {
	q35();
	q36();
	q37();
	return 0;
}
