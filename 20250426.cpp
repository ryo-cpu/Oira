#include <stdio.h>
#include <math.h>
#include <vector>

#pragma warning(disable:6386)

using namespace std;
typedef unsigned long long ull;
const int MaxNo = 10000;

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

void q9()
{
	int a, b, c;
	unsigned long long val;
	for (a = 1; a < 1000 - 2; a++)
	{
		for (b = a + 1; b < 1000 - 1; b++)
		{
			if (a + b > 1000)break;
			for (c = b + 1; c < 1000; c++)
			{
				if (a + b + c != 1000)continue;
				val = (unsigned long long)a * a + (unsigned long long)b * b;
				if (val == (unsigned long long)c * c)
				{
					printf("Q9:%d\n", a * b * c);
					return;
				}
			}
		}
	}
}

void q8()
{
	const char* digit1000 = 
		"73167176531330624919225119674426574742355349194934"
		"96983520312774506326239578318016984801869478851843"
		"85861560789112949495459501737958331952853208805511"
		"12540698747158523863050715693290963295227443043557"
		"66896648950445244523161731856403098711121722383113"
		"62229893423380308135336276614282806444486645238749"
		"30358907296290491560440772390713810515859307960866"
		"70172427121883998797908792274921901699720888093776"
		"65727333001053367881220235421809751254540594752243"
		"52584907711670556013604839586446706324415722155397"
		"53697817977846174064955149290862569321978468622482"
		"83972241375657056057490261407972968652414535100474"
		"82166370484403199890008895243450658541227588666881"
		"16427171479924442928230863465674813919123162824586"
		"17866458359124566529476545682848912883142607690042"
		"24219022671055626321111109370544217506941658960408"
		"07198403850962455444362981230987879927244284909188"
		"84580156166097919133875499200524063689912560717606"
		"05886116467109405077541002256983155200055935729725"
		"71636269561882670428252483600823257530420752963450";

	const int countMax = 1000 + 1 - 13;
	unsigned long long valueMax = 0, tmpValue = 0;
	for (int i = 0; i < countMax; i++)
	{
		const char* tmpPos = digit1000 + i;
		tmpValue = 1UL;
		for (int j = 0; j < 13 && tmpValue ; j++)
		{
			tmpValue *= (unsigned long long)tmpPos[j] - '0';
		}
		if (tmpValue > valueMax)valueMax = tmpValue;
	}
	printf("Q8:%lld\n", valueMax);
}

void q7()
{
	const int pMax = 4000000;
	vector<int> prime;
	makePrimeNumberList(pMax, &prime);
	printf("Q7:%d\n", prime[10000]);
}

int main()
{
	q7();
	q8();
	q9();

}

