#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

struct Frac
{
	int num;
	int den;

	Frac(int num, int den)
		: num(num),
		den(den)
	{
		assert(den > 0);
	}

	Frac(int num)
		: num(num),
		den(1)
	{}
};

int compare(const Frac& left, const Frac& right)
{
	return left.num * right.den - right.num * left.den;
}

bool operator >= (const Frac& left, const Frac& right)
{
	return compare(left, right) >= 0;
}


bool operator < (const Frac& left, const Frac& right)
{
	return compare(left, right) < 0;
}

bool operator == (const Frac& left, const Frac& right)
{
	return compare(left, right) == 0;
}

Frac operator - (const Frac& left, const Frac& right)
{
	return Frac(left.num * right.den - right.num * left.den, left.den * right.den);
}

struct Rocket
{
	int dir;
	Frac time;
};

int main() 
{
	vector<int> tx(4);
	vector<int> vx(4);

	for (int i = 0; i < 4; i++)
		cin >> tx[i] >> vx[i];

	int tr, dist,ans,from,to,time;
	cin >> tr >> dist;
	vector <Rocket> r;

	for (int i = 0; i < 4; i++)
		r.push_back(Rocket{ i,Frac(tx[i] * vx[i] + dist,vx[i]) });

	sort(r.begin(), r.end(), [](const Rocket& left, const Rocket& right)
	{
		return left.time < right.time;
	});

	ans = 1;

	for (int i = 1; i < 4; i++)
	{
		from = r[i - 1].dir;
		to = r[i].dir;
		if (from % 2 == to % 2)
			time = 2 * tr;
		else
			time = tr;

		if (r[i].time - r[i - 1].time < time)
		{
			if (i + 1 < 4 && r[i].time == r[i + 1].time && r[i + 1].time - r[i - 1].time >= tr)
			{
				assert(r[i - 1].dir % 2 == r[i].dir % 2);
				assert(r[i - 1].dir % 2 != r[i + 1].dir % 2);
				ans++;
			}
		}
	}

	if (ans == 4)
		cout << "ALIVE";
	else
		cout << ans;
}