#pragma warning(disable:6386)

#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

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

void q30Re()
{
	int pow5[10] = {0};
	for (int i = 0; i < 10; i++) {
		pow5[i] = (int)pow(i, 5);
	}
	int sum = 0;
	for (int i = 2; i < 10000000; i++)
	{
		int tmp = 0;
		for(int calc = i; calc; calc /= 10){
			tmp += pow5[calc % 10];
		}
		if (i == tmp)
		{
			sum += i;
		}
	}
	printf("Q30(alt):%d\n", sum);
}

void q30()
{
	int sum = 0;
	for (int i = 2; i < 10000000; i++)
	{
		int calc = i;
		int tmp = 0;
		while (calc)
		{
			if ((calc % 10) > 0)
			{
				tmp += (int)pow(calc % 10, 5);
			}
			calc /= 10;
		}
		if (i == tmp)
		{
			sum += i;
		}
	}
	printf("Q30:%d\n", sum);
}

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

void q29_mult()
{
	set<cpp_int> value;
	for (int a = 2; a <= 100; a++)
		for (int b = 2; b <= 100; b++)
			value.insert((cpp_int)pow(a, b));
	printf("Q29(alt):%lld\n", value.size());
}

void q29()
{
	set<double> value;
	for (int a = 2; a <= 100; a++)
		for (int b = 2; b <= 100; b++)
			value.insert(pow(a, b));
	printf("Q29:%lld\n", value.size());
}

int q27f(int a, int b, int n)
{
	return n * n + a * n + b;
}

void q27()
{
	vector<int> prime;
	makePrimeNumberList(4000000, &prime);
	int n, nMax = 0, memA, memB;
	set<int> checked;
	for (int a = -1000; a < 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			for (n = 0; n < 1000; n++)
			{
				int tmp = q27f(a, b, n);
				if (!binary_search(prime.begin(), prime.end(), tmp))
					break;
			}
			if (n != 1000 && n > nMax)
			{
				nMax = n;
				memA = a;
				memB = b;
			}
		}
	}
	printf("Q27:%d\n", memA * memB);
}

int main() {
	q27();
	q29();
	q29_mult();
	q30();
	q30Re();
	return 0;
}