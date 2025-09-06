#include <stdio.h>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

unsigned long long factorial(int val)
{
	return val ? val * factorial(val - 1) : 1;
}

void q34()
{
	int sum = 0;
	for (int i = 3; i < 1000000; i++)
	{
		int current = i;
		unsigned long long tmpSum = 0;
		while (current)
		{
			tmpSum += factorial(current % 10);
			current /= 10;
		}
		if (i == tmpSum)sum += i;
	}
	printf("Q34:%d\n", sum);
}

bool is_pandigital(unsigned int a, unsigned  b, unsigned int c)
{
	std::string s = to_string(a) + to_string(b) + to_string(c);
	if (s.find('0') != std::string::npos)
		return false;

	std::vector <unsigned short, std::allocator <unsigned short> > v('9' + 1, 0);

	std::string::size_type s_len = s.length();
	for (unsigned short i = 0; i < s_len; i++)
		v[s[i]]++;

	for (char c = '1'; c <= '9'; c++)
		if (v[c] != 1)
			return false;

	return true;
}

int len(int n)
{
	int ret;
	for (ret = 1; n; ret++)
	{
		if (n < 10)return ret;
		n /= 10;
	}
	return ret;
}


void q32()
{
	std::set<unsigned int> s;
	unsigned long long sum = 0;
	int mult = 1;

	for (unsigned short i = 1; i < 10000; i++)
		for (unsigned short j = 1; j < 10000; ++j, mult = (unsigned long long)i * j)
		{
			if (len(i) + len(j) + len(mult) > 9)continue;
			else if (len(i) + len(j) + len(mult) == 9)
				if (is_pandigital(i, j, mult))
					if (s.find(mult) == s.end())
					{
						sum += mult;
						cout << i << "*" << j << " = " << mult << std::endl;
						s.insert(mult);
					}
		}

	printf("Q32:%lld\n", sum);

}


int findposs(int money, int maxcoin)
{
	int coins[8] = { 200, 100, 50, 20, 10, 5,2,1 };
	int sum = 0;
	if (maxcoin == 7) return 1;
	for (int i = maxcoin; i < 8; i++)
	{
		if (money - coins[i] == 0) sum += 1;
		if (money - coins[i] > 0) sum += findposs(money - coins[i], i);
	}
	return sum;
}

void q31()
{
	printf("Q31:%d\n", findposs(200, 0));
}

int main() {
	q31();
	q32();
	q34();

	return 0;
}