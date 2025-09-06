#include <stdio.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <algorithm>
#include <vector>

using namespace std;
using namespace boost::multiprecision;
using namespace boost::math;
typedef unsigned long long ull;

int sum_nn(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

int sum_n(int n) {
	return n * (n + 1) / 2;
}

void q28alt()
{
	int to_n = 501;
	int ans = 16 * sum_nn(to_n) - 28 * sum_n(to_n) + 16 * to_n - 3;
	printf("Q28(alt):%d\n", ans);
}

void q28()
{
	ull sum = 1;
	ull seq[4] = { 1, 1, 1, 1 };
	ull delta[4];
	for (int i = 0; i < 4; i++)delta[i] = 2 * (i + 1);
	for (int i = 0; i < 1001/2; i++) {
		for (int j = 0; j < 4; j++) {
			seq[j] += delta[j];
			sum += seq[j];
			delta[j] += 8;
		}
	}
	printf("Q28:%lld\n", sum);
}

int mp_keta(cpp_int x) {
	return (int)x.str().size();
}

// 桁数を調べる方法
void q25alt() {
	cpp_int lo = 1, hi = 1, ans = 0;
	int count = 3;
	for (; mp_keta(ans) < 1000; count++) {
		ans = hi + lo;
		lo = hi;
		hi = ans;
	}
	printf("Q25(alt):%d\n", count);
}

// まじめに調べる方法
void q25()
{
	char Fodd[1000] = { 0 };
	char Feven[1000] = { 0 };
	Fodd[0] = Feven[0] = 1;
	int count;
	for (count = 3; !Fodd[999] && !Feven[999]; count++)
	{
		char* to = (count % 2) ? Fodd : Feven;
		char* from = (count % 2) ? Feven : Fodd;
		for (int i = 0; i < 1000; i++)
		{
			to[i] += from[i];
		}
		for (int i = 0; i < 1000; i++)
		{
			if (to[i] > 9)
			{
				to[i + 1] += to[i] / 10;
				to[i] %= 10;
			}
		}
	}
	printf("Q25:%d\n", count);
}

// STLに感謝せよ
void q24alt()
{
	vector<int> set;
	for (int i = 0; i < 10; i++)set.push_back(i);
	for (int i = 0; i < 1000000 - 1; i++)
		next_permutation(set.begin(), set.end());
	printf("Q24(alt):");
	for (int i = 0; i < 10; i++)
		printf("%d", set[i]);
	printf("\n");
}

unsigned long long factorial(int val)
{
	return val ? val * factorial(val - 1) : 1;
}

// 順列組み合わせの公式を使ってまともに計算する方法
void q24()
{
	int order = 1000000 - 1;
	char numset[11] = { 0 };
	char rsv[] = "0123456789";
	int pos;
	for (int i = 0; i < 10; i++) {
		int fct = (int)factorial(9 - i);
		int cnt = order / fct;
		order %= fct;
		for (pos = 0; rsv[pos] == -1 || cnt > 0; pos++)
			if (rsv[pos] != -1)cnt--;
		numset[i] = rsv[pos];
		rsv[pos] = -1;
	}
	printf("Q24:%s\n", numset);
}

int main() {
	q24();
	q24alt();
	q25();
	q25alt();
	q28();
	q28alt();
}
